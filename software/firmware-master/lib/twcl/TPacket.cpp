#include "TPacket.h"

TPacket::TPacket()	{ created = false; }
TPacket::TPacket(TAddress from, TAddress to, TDescription description, TMessage message)	{
	msg = message;
	des = description;
	f = from;
	t = to;
	created = true;
}
bool TPacket::build(String packetAsString)	{
	if(packetAsString.charAt(0) == START_BYTE &&
			packetAsString.charAt(packetAsString.length()-1) == END_BYTE)	{
		if(packetAsString.charAt(TPACKET_1ST_SPLIT_POSITION) == SPLIT_BYTE 
				&& packetAsString.charAt(TPACKET_2ND_SPLIT_POSITION) == SPLIT_BYTE
				&& packetAsString.charAt(TPACKET_3RD_SPLIT_POSITION) == SPLIT_BYTE)	{
			f.set(packetAsString.charAt(1), packetAsString.charAt(2), 
					packetAsString.charAt(3), packetAsString.charAt(4));
			t.set(packetAsString.charAt(6), packetAsString.charAt(7), 
					packetAsString.charAt(8), packetAsString.charAt(9));
			des.set(packetAsString.charAt(11), packetAsString.charAt(12), 
					packetAsString.charAt(13), packetAsString.charAt(14));
			msg.set(packetAsString.substring(15, packetAsString.length() - 1));
			if(msg.get().equals("-1"))	{
				error.set(0x0007, TERROR_EXCEPTION);
				return false;
			}
			return true;
		}else	{
			error.set(0x0006, TERROR_EXCEPTION);
		}
	}else	{
		error.set(0x0001, TERROR_EXCEPTION);
	}
	return false;
}
String TPacket::toString()	{
	String packet = "------------------";
	packet.setCharAt(0, START_BYTE);
	packet.setCharAt(1, f.get((unsigned char)0));
	packet.setCharAt(2, f.get(1));
	packet.setCharAt(3, f.get(2));
	packet.setCharAt(4, f.get(3));
	packet.setCharAt(5, SPLIT_BYTE);
	packet.setCharAt(6, t.get((unsigned char)0));
	packet.setCharAt(7, t.get(1));
	packet.setCharAt(8, t.get(2));
	packet.setCharAt(9, t.get(3));
	packet.setCharAt(10, SPLIT_BYTE);
	packet.setCharAt(11, des.get((unsigned char)0));
	packet.setCharAt(12, des.get(1));
	packet.setCharAt(13, des.get(2));
	packet.setCharAt(14, des.get(3));
	packet.setCharAt(15, SPLIT_BYTE);
	packet += msg.get();
	packet += "-";
	packet.setCharAt(packet.length() - 1, END_BYTE);
	return packet;
}
void TPacket::clear()	{
	msg.set("");
	f.set(0,0,0,0);
	t.set(0,0,0,0);
	des.set(0,0,0,0);
}
bool TPacket::checkForError()	{
	if(error.getLevel() != TERROR_NOT_SET)	{
		return true;
	}
	return false;
}
TError TPacket::getError()	{
	TError temp = error;
	error.set(0x00, TERROR_NOT_SET);
	return temp;
}
void TPacket::setFrom(TAddress from)	{
	f = from;
}
void TPacket::setFrom(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	f.set(b1, b2, b3, b4);
}
void TPacket::setFrom(unsigned long from)	{
	f.set(from);
}
TAddress TPacket::getFrom()	{
	return f;
}
void TPacket::setTo(TAddress to)	{
	t = to;
}
void TPacket::setTo(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	t.set(b1, b2, b3, b4);
}
void TPacket::setTo(unsigned long to)	{
	t.set(to);
}
TAddress TPacket::getTo()	{
	return t;
}
void TPacket::setDescription(TDescription description)	{
	des = description;
}
void TPacket::setDescription(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)	{
	des.set(b1, b2, b3, b4);
}
void TPacket::setDescription(unsigned long description)	{
	des.set(description);
}
TDescription TPacket::getDescription()	{
	return des;
}
void TPacket::setMessage(TMessage message)	{
	msg = message;
}
TMessage TPacket::getMessage()	{
	return msg;
}
void TPacket::setType(unsigned char dataType)	{
	type = dataType;
}
unsigned char TPacket::getType()	{
	return type;
}