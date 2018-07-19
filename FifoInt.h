#ifndef Fifo_h
#define Fifo_h

#include "Arduino.h"

class Fifo {
	public:
		Fifo (int size);
		Fifo (float *sample, int size);
		void in (float val);
		float out ();
		float read ();
		int size ();
		int count ();
		bool isFull ();
		bool isEmpty ();
		bool allEqual ();
	private:
		int _size, _count, _inPtr, _outPtr;
		float *_buf;
		void increase (int *ptr);
};


#endif