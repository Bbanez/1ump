#ifndef THandler_h
#define THandler_h

#include "Arduino.h"
#include "TPacket.h"

#define MASTER			0x01
#define SLAVE_MASTER	0x02
#define SLAVE			0x03

class THandler	{
	public:
		THandler(TAddress myAddress, TAddress netmask, unsigned char role);
		THandler(TAddress myAddress, TAddress netmask, unsigned char role, unsigned long baud, 
				HardwareSerial *serialPort, unsigned char busyInPin, 
				unsigned char busyOutPin);
		bool init(unsigned long baud, HardwareSerial *serialPort, 
				unsigned char busyInPin, unsigned char busyOutPin);
		bool listen();
		void setBuffer(unsigned long maxSize);
		void clear();
		bool isRedirect();
		bool send(TPacket thisPacket);
		bool send(TAddress to, TDescription description, TMessage message);
		bool send(String packetAsString);
		bool checkForError();
		TError getError();
		String getBuffer();
		TPacket getPacket();
		TAddress getMyAddress();
		TAddress getNetmask();
	private:
		HardwareSerial *serial;
		String buffer;
		TPacket packet;
		TAddress address, mask;
		TError error;
		unsigned long maxBufferSize = 1024;
		unsigned char rl, bip, bop;
		unsigned char rollingBuffer;
		bool packetStart, redirect;
};

#endif