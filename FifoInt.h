#ifndef Fifo_h
#define Fifo_h

#include "Arduino.h"
using type_fi = int;

class Fifo {
	public:
		Fifo (int size);
		Fifo (type_fi *sample, int size);
		void in (type_fi val);
		type_fi out (void);
		type_fi read (void);
		inline int size (void) { return _size; };
		inline int count (void) { return _count; };
		inline bool isFull (void);
		inline bool isEmpty (void);
		bool allEqual (void);
        type_fi average (void);
	private:
		int _size, _count, _inPtr, _outPtr;
		type_fi *_buf;
		void increase (int *ptr);
};

#endif
