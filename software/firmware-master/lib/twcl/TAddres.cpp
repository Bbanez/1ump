#include "TAddress.h"

TAddress::TAddress()	{ created = false; }

TAddress::TAddress(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	addr = ((unsigned long)b1 << 24);
	addr +=  ((unsigned long)b2 << 16) & 0xFF0000;
	addr +=  (b3 << 8) & 0xFF00;
	addr +=  b4;
	created = true;
}

void TAddress::get(unsigned char *byteArray)	{
	byteArray[0] = (addr >> 24) & 0xFF;
	byteArray[1] = (addr & 0x00FF000000) >> 16;
	byteArray[2] = (addr >> 8) & 0xFF;
	byteArray[3] = addr & 0xFF;
}

unsigned long TAddress::get()	{
	return addr;
}

unsigned char TAddress::get(unsigned char bytePosition)	{
	switch(bytePosition)	{
		case 0:	{
			return ((addr) >> 24);
		}
		case 1:	{
			return ((addr >> 16) & 0xFF);
		}
		case 2:	{
			return ((addr >> 8) & 0xFF);
		}
		case 3:	{
			return (addr & 0xFF);
		}
		default:	{
			return 0;
		}
	}
}

void TAddress::set(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	addr = ((unsigned long)b1 << 24);
	addr +=  ((unsigned long)b2 << 16) & 0xFF0000;
	addr +=  (b3 << 8) & 0xFF00;
	addr +=  b4;
	created = true;
}

void TAddress::set(unsigned char bytePosition, unsigned char value)	{
	switch(bytePosition)	{
		case 0:	{
			addr = addr & 0x00FFFFFF;
			addr += (long(value) << 24);
		}break;
		case 1:	{
			addr = addr & 0xFF00FFFF;
			addr += (long(value) << 16) & 0xFF0000;
		}break;
		case 2:	{
			addr = addr & 0xFFFF00FF;
			addr += (value << 8) & 0xFF00;
		}break;
		case 3:	{
			addr = addr & 0xFFFFFF00;
			addr += value;
		}break;
	}
}

void TAddress::set(unsigned long address)	{
	addr = address;
	created = true;
}

bool TAddress::isSet()	{
	return created;
}