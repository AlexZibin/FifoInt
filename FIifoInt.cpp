#include "Fifo.h"

Fifo::Fifo (int size) {
	_size = size;
	_buf = new float[_size];
	_inPtr = _outPtr = _count = 0;
}

Fifo::Fifo (float *sample, int size) {
	_size = _count = size;
	_buf = sample;
	_inPtr = _outPtr = 0;
}

void Fifo::in (float val) {
	_buf[_inPtr] = val;
	increase (&_inPtr);
		//if (++_inPtr == _size) _inPtr = 0;
		
	if (++_count > _size) {
		_count = _size;
		increase (&_outPtr);
	}
}

void Fifo::increase (int *ptr) { if ( ++*ptr == _size) *ptr = 0; }

float Fifo::out () {
	if (!isEmpty()) {
		float retval = _buf[_outPtr];
		increase (&_outPtr);
		--_count;
		
		return retval;
	}
	else return -1;
}

float Fifo::read () {
	if (!isEmpty()) {
		float retval = _buf[_outPtr];
		increase (&_outPtr);
		
		return retval;
	}
	else return -1;
}

int Fifo::size () {
	return _size;
}

int Fifo::count () {
	return _count;
}

bool Fifo::isFull () { return _count == _size; }

bool Fifo::isEmpty () { return _count == 0; }

bool Fifo::allEqual () {
	if (_count < _size) return false;
	
	for (int i = 0; i < _size-1; i++)
		if (_buf[i] != _buf[i+1]) 
			return false;
		
	return true;
}
