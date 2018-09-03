#include "TMessage.h"

TMessage::TMessage()	{}
TMessage::TMessage(String message)	{
	msg = message;
}
void TMessage::set(String message)	{
	msg = message;
}
void TMessage::set(unsigned char message)	{
	msg = "";
	msg += message;
}
void TMessage::set(unsigned int message)	{
	msg = "";
	msg += message;
}
void TMessage::set(unsigned long message)	{
	msg = "";
	msg += message;
}
void TMessage::set(int message)	{
	msg = "";
	msg += message;
}
void TMessage::set(long message)	{
	msg = "";
	msg += message;
}
void TMessage::set(float message)	{
	msg = String(message);
}
void TMessage::set(double message)	{
	msg = String(message);
}
void TMessage::set(char message)	{
	msg = "";
	msg += message;
}
String TMessage::get()	{
	return msg;
}
unsigned char TMessage::toUINT8()	{
	return (unsigned char)msg.toInt();
}
unsigned int TMessage::toUINT16()	{
	return (unsigned int)msg.toInt();
}
unsigned long TMessage::toUINT32()	{
	return (unsigned long)msg.toInt();
}
int TMessage::toINTEGER()	{
	return msg.toInt();
}
long TMessage::toLONG()	{
	return msg.toInt();
}
float TMessage::toFLOAT()	{
	return msg.toFloat();
}
double TMessage::toDOUBLE()	{
	return toDouble();
}
char TMessage::toCHAR()	{
	return msg.charAt(0);
}
double TMessage::toDouble()	{
	int offs = 0;
	if(msg.charAt(0) == '-')	{
		offs = 1;
	}

	int dot = msg.indexOf(".") - offs;

	if(dot > 0)	{
		double mult = 1;
		double res = 0;
		for(int i = 0; i < dot; i++)	{
			mult *= 10;
		}
		for(unsigned int i = offs; i < msg.length(); i++)	{
			switch(msg.charAt(i))	{
				case '9':	{
					res += mult*9;
				}break;
				case '8':	{
					res += mult*8;
				}break;
				case '7':	{
					res += mult*7;
				}break;
				case '6':	{
					res += mult*6;
				}break;
				case '5':	{
					res += mult*5;
				}break;
				case '4':	{
					res += mult*4;
				}break;
				case '3':	{
					res += mult*3;
				}break;
				case '2':	{
					res += mult*2;
				}break;
				case '1':	{
					res += mult*1;
				}break;
				case '.':	{
					mult *= 10;
				}
			}
			mult /= 10;
		}
		if(offs > 0)	{
			return -res;
		}
		return res;
	}
	return 0.0;
}