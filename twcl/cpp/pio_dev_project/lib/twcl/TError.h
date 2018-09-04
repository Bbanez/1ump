#ifndef TError_h
#define TError_h

#include "WString.h"

#define TERROR_FATAL		0x25
#define TERROR_WARNING		0x26
#define TERROR_EXCEPTION	0x27
#define TERROR_NOT_SET		0x28

class TError	{
	public:
		TError();
		TError(unsigned int code, unsigned char level);
		void set(unsigned int code, unsigned char level);
		void set(unsigned int code);
		void set(unsigned char level);
		unsigned int getCode();
		unsigned char getLevel();
		String toString();
		String toMonitor();
	private:
		#define SPLIT 0x04
		unsigned int c;
		unsigned char lvl;
};

#endif