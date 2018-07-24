#include "Fifo.h"

Fifo::Fifo (int size) {
	_size = size;
	_buf = new type_fi[_size];
	_inPtr = _outPtr = _count = 0;
}

Fifo::Fifo (type_fi *sample, int size) {
	_size = _count = size;
	_buf = sample;
	_inPtr = _outPtr = 0;
}

void Fifo::in (type_fi val) {
	_buf[_inPtr] = val;
	increase (&_inPtr);
		//if (++_inPtr == _size) _inPtr = 0;
		
	if (++_count > _size) {
		_count = _size;
		increase (&_outPtr);
	}
}

void Fifo::increase (int *ptr) { if ( ++*ptr == _size) *ptr = 0; }

type_fi Fifo::out () {
	if (!isEmpty()) {
		type_fi retval = _buf[_outPtr];
		increase (&_outPtr);
		--_count;
		
		return retval;
	}
	else return -1;
}

type_fi Fifo::read () {
	if (!isEmpty()) {
		type_fi retval = _buf[_outPtr];
		increase (&_outPtr);
		
		return retval;
	}
	else return -1;
}

inline bool Fifo::isFull () { return _count == _size; }

inline bool Fifo::isEmpty () { return _count == 0; }

bool Fifo::allEqual () {
	if (_count < _size) return false;
	
	for (int i = 0; i < _size-1; i++)
		if (_buf[i] != _buf[i+1]) 
			return false;
		
	return true;
}

type_fi Fifo::average () {
	type_fi avg = 0;
    for (int i = 0; i < _size-1; i++) {
        avg += _buf[i];
    }
		
	return avg/_count;
}
