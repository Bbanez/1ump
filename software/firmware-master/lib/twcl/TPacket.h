#ifndef TPacket_h
#define TPacket_h

#include "TAddress.h"
#include "TDescription.h"
#include "TMessage.h"
#include "TError.h"
#include "WString.h"
#include "HardwareSerial.h"

// A B1 B2 B3 B4 C D1 D2 D3 D4 C  E1 E2 E3 E4 C  F  G
// 0 1  2  3  4  5 6  7  8  9  10 11 12 13 14 15 16 N

#define START_BYTE	0x01
#define SPLIT_BYTE	0x02
#define END_BYTE	0x03
#define TPACKET_1ST_SPLIT_POSITION	5
#define TPACKET_2ND_SPLIT_POSITION	10
#define TPACKET_3RD_SPLIT_POSITION	15

class TPacket	{
	public:
		TPacket();
		TPacket(TAddress from, TAddress to, TDescription description, TMessage message);

		bool build(String packetAsString);
		String toString();
		void clear();
		bool checkForError();
		TError getError();

		void setFrom(TAddress from);
		void setFrom(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		void setFrom(unsigned long from);
		TAddress getFrom();
		void setTo(TAddress to);
		void setTo(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		void setTo(unsigned long to);
		TAddress getTo();
		void setDescription(TDescription description);
		void setDescription(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		void setDescription(unsigned long description);
		TDescription getDescription();
		void setMessage(TMessage message);
		void setMessage(String message);
		TMessage getMessage();
		void setType(unsigned char dataType);
		unsigned char getType();
	private:
		TMessage msg;
		TDescription des;
		TAddress f, t;
		TError error;
		bool created;
		unsigned char type;

		double toDouble(String s);
};

#endif