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
		TError(String message, unsigned char level);
		void set(String message, unsigned char level);
		void set(String message);
		void set(unsigned char level);
		String getMessage();
		unsigned char getLevel();
	private:
		String msg;
		unsigned char lvl;
};

#endif