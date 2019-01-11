#ifndef TMessage_h
#define TMessage_h

#include "WString.h"

class TMessage	{
	public:
		TMessage();
		TMessage(String message);
		String get();
		unsigned char toUINT8();
		unsigned int toUINT16();
		unsigned long toUINT32();
		int toINTEGER();
		long toLONG();
		float toFLOAT();
		double toDOUBLE();
		char toCHAR();
		void set(unsigned char message);
		void set(unsigned int message);
		void set(unsigned long message);
		void set(int message);
		void set(long message);
		void set(float message);
		void set(double message);
		void set(char message);
		void set(String message);
	private:
		String msg;
		double toDouble();
};
#endif