#ifndef Fifo_h
#define Fifo_h

#include "Arduino.h"
using type_fi = int;

class Fifo {
	public:
		Fifo (int size);
		Fifo (type_fi *sample, int size);
		void in (type_fi val);
		type_fi out ();
		type_fi read ();
		int size ();
		int count ();
		bool isFull ();
		bool isEmpty ();
		bool allEqual ();
        type_fi average ();
	private:
		int _size, _count, _inPtr, _outPtr;
		type_fi *_buf;
		void increase (int *ptr);
};

#endif
