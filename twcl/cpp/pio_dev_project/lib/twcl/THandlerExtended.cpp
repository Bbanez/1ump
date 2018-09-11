#include "THandlerExtended.h"

THandler::THandler(TAddress myAddress, TAddress netmask, unsigned char role)	{
	address = myAddress;
	rl = role;
	mask = netmask;
	packetStart = false;
	redirect = false;
}
THandler::THandler(TAddress myAddress, TAddress netmask, unsigned char role, unsigned long baud, 
		HardwareSerial *serialPort, unsigned char busyInPin, unsigned char busyOutPin)	{
	serial = serialPort;
	serial->begin(baud);
	bip = busyInPin;
	bop = busyOutPin;
	pinMode(bop, OUTPUT);
	digitalWrite(bop, 0);
	pinMode(bip, INPUT);
	if(rl != MASTER)	{
		digitalWrite(bop, 1);
		delay(10);
		if(digitalRead(bip))	{
			error.set(0x0009, TERROR_WARNING);
		}
		digitalWrite(bop, 0);
	}
	rl = role;
	packetStart = false;
	redirect = false;
	address = myAddress;
	mask = netmask;
}
bool THandler::init(unsigned long baud, HardwareSerial *serialPort, 
		unsigned char busyInPin, unsigned char busyOutPin)	{
	serial = serialPort;
	serial->begin(baud);
	bip = busyInPin;
	bop = busyOutPin;
	pinMode(bop, OUTPUT);
	digitalWrite(bop, 0);
	pinMode(bip, INPUT);

	if(rl != MASTER)	{
		digitalWrite(bop, 1);
		delay(10);
		if(digitalRead(bip))	{
			error.set(0x0008, TERROR_WARNING);
			digitalWrite(bop, 0);
			return false;
		}
		digitalWrite(bop, 0);
	}
	return true;
}
bool THandler::listen()	{
	if(serial->available())	{
		unsigned char available = serial->available();
		while(available > 0)	{
			rollingBuffer = serial->read();
			available--;
			if(packetStart)	{
				switch(rollingBuffer)	{
					case END_BYTE:	{
						buffer += (char)END_BYTE;
						packetStart = false;
						if(packet.build(buffer))	{
							if(rl == MASTER)	{
								if((packet.getTo().get() & mask.get()) == mask.get())	{
									redirect = true;
								}
								return true;
							}else	{
								if(packet.getTo().get() == address.get())	{
									return true;
								}
								clear();
							}
						}else	{
							clear();
							error.set(0x000A, TERROR_EXCEPTION);
							return true;
						}
					}break;
					default:	{
						buffer += rollingBuffer;
						if(buffer.length() > maxBufferSize)	{
							clear();
							error.set(0x000B, TERROR_EXCEPTION);
							return true;
						}
						switch(buffer.length())	{
							case TPACKET_1ST_SPLIT_POSITION:	{
								if(rollingBuffer != SPLIT_BYTE)	{
									clear();
									error.set(0x000C, TERROR_EXCEPTION);
									return true;
								}
							}break;
							case TPACKET_2ND_SPLIT_POSITION:	{
								if(rollingBuffer != SPLIT_BYTE)	{
									clear();
									error.set(0x000D, TERROR_EXCEPTION);
									return true;
								}
							}break;
							case TPACKET_3RD_SPLIT_POSITION:	{
								if(rollingBuffer != SPLIT_BYTE)	{
									clear();
									error.set(0x000E, TERROR_EXCEPTION);
									return true;
								}
							}break;
						}
					}break;
				}
			}else	{
				if(rollingBuffer == START_BYTE)	{
					packetStart = true;
					buffer = "";
					buffer += (char)START_BYTE;
				}
			}
		}
	}
	return false;
}
void THandler::setBuffer(unsigned long maxSize)	{
	maxBufferSize = maxSize;
}
void THandler::clear()	{
	buffer = "";
	packetStart = false;
	packet.clear();
}
bool THandler::send(TPacket thisPacket)	{
	return send(thisPacket.getTo(), thisPacket.getDescription(), thisPacket.getMessage());
}
bool THandler::send(TAddress to, TDescription description, TMessage message)	{
	if(rl == MASTER)	{
		serial->print((char)START_BYTE);
		serial->print((char)address.get((unsigned char)0));
		serial->print((char)address.get(1));
		serial->print((char)address.get(2));
		serial->print((char)address.get(3));
		serial->print((char)SPLIT_BYTE);
		serial->print((char)to.get((unsigned char)0));
		serial->write(to.get(1));
		serial->print((char)to.get(2));
		serial->print((char)to.get(3));
		serial->print((char)SPLIT_BYTE);
		serial->print((char)description.get((unsigned char)0));
		serial->print((char)description.get(1));
		serial->print((char)description.get(2));
		serial->print((char)description.get(3));
		serial->print((char)SPLIT_BYTE);
		serial->print(message.get());
		serial->print((char)END_BYTE);
		return true;
	}else	{
		if(digitalRead(bip))	{
			digitalWrite(bop, 1);
			serial->print((char)START_BYTE);
			serial->print((char)address.get((unsigned char)0));
			serial->print((char)address.get(1));
			serial->print((char)address.get(2));
			serial->print((char)address.get(3));
			serial->print((char)SPLIT_BYTE);
			serial->print((char)to.get((unsigned char)0));
			serial->print((char)to.get(1));
			serial->print((char)to.get(2));
			serial->print((char)to.get(3));
			serial->print((char)SPLIT_BYTE);
			serial->print((char)description.get((unsigned char)0));
			serial->print((char)description.get(1));
			serial->print((char)description.get(2));
			serial->print((char)description.get(3));
			serial->print((char)SPLIT_BYTE);
			serial->print(message.get());
			serial->print((char)END_BYTE);
			digitalWrite(bop, 0);
			return true;
		}
	}
	return false;
}
bool THandler::send(String packetAsString)	{
	if(rl == MASTER)	{
			serial->print(packetAsString);
			return true;
	}else	{
		if(digitalRead(bip))	{
			digitalWrite(bop, 1);
			serial->print(packetAsString);
			digitalWrite(bop, 0);
			return true;
		}
	}
	return false;
}
bool THandler::checkForError()	{
	if(error.getLevel() != TERROR_NOT_SET)	{
		return true;
	}
	return false;
}
TError THandler::getError()	{
	TError temp = error;
	error.set(0x0000, TERROR_NOT_SET);
	return temp;
}
bool THandler::isRedirect()	{
	if(redirect)	{
		redirect = false;
		return true;
	}
	return false;
}
String THandler::getBuffer()	{
	return buffer;
}
TPacket THandler::getPacket()	{
	return packet;
}
TAddress THandler::getMyAddress()	{
	return address;
}
TAddress THandler::getNetmask()	{
	return mask;
}