#include "TDescription.h"

TDescription::TDescription()	{ created = false; }

TDescription::TDescription(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	b[0] = b1;
	b[1] = b2;
	b[2] = b3;
	b[3] = b4;
	created = true;
}

unsigned char TDescription::get(unsigned char bytePosition)	{
	if(bytePosition < 4)	{
		return b[bytePosition];
	}
	return 0;
}

void TDescription::get(unsigned char *bytes)	{
	bytes[0] = b[0];
	bytes[1] = b[1];
	bytes[2] = b[2];
	bytes[3] = b[3];
}

void TDescription::set(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	b[0] = b1;
	b[1] = b2;
	b[2] = b3;
	b[3] = b4;
	created = true;
}

void TDescription::set(unsigned char *bytes)	{
	b[0] = bytes[0];
	b[1] = bytes[1];
	b[2] = bytes[2];
	b[3] = bytes[3];
	created = true;
}

void TDescription::set(unsigned long value)	{
	b[0] = (0xFF000000 & value) >> 24;
	b[1] = (0x00FF0000 & value) >> 16;
	b[2] = (0x0000FF00 & value) >> 8;
	b[3] = (0x000000FF & value);
}

bool TDescription::isSet()	{
	return created;
}