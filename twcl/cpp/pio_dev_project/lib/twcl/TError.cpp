#include "TError.h"

TError::TError()	{
	c = 0x00;
	lvl = TERROR_NOT_SET;
}
TError::TError(unsigned int code, unsigned char level)	{
	c = code;
	lvl = level;
}
void TError::set(unsigned int code, unsigned char level)	{
	c = code;
	lvl = level;
}
void TError::set(unsigned int code)	{
	c = code;
}
void TError::set(unsigned char level)	{
	lvl = level;
}
unsigned int TError::getCode()	{
	return c;
}
unsigned char TError::getLevel()	{
	return lvl;
}
String TError::toString()	{
	String s = "";
	s += lvl;
	s += SPLIT;
	s += c;
	return s;
}
String TError::toMonitor()	{
	String s = "";
	s += ">>>   TError\r\nLevel: ";
	s += lvl;
	s += "\r\nCode: ";
	s += c;
	s += "\r\n";
	return s;
}