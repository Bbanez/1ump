#include "TError.h"

TError::TError()	{
	msg = "";
	lvl = TERROR_NOT_SET;
}
TError::TError(String message, unsigned char level)	{
	msg = message;
	lvl = level;
}
void TError::set(String message, unsigned char level)	{
	msg = message;
	lvl = level;
}
void TError::set(String message)	{
	msg = message;
}
void TError::set(unsigned char level)	{
	lvl = level;
}
String TError::getMessage()	{
	return msg;
}
unsigned char TError::getLevel()	{
	return lvl;
}