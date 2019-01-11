#include "Arduino.h"
#include "THandler.h"

void setup() {
}

void loop() {
	unsigned long us = micros();
	// THandler twcl(TAddress(192, 168, 0, 0), TAddress(192, 168, 0, 4), MASTER);
	// twcl.init(115200, &Serial, 9, 10);
	TAddress to(192, 168, 0, 65);
	TDescription des(FLOAT, 123, 122, 121);
	TMessage msg;
	msg.set(45.123);

	us = micros() - us;
	Serial.print(us);

	pinMode(13, OUTPUT);
	digitalWrite(13, 0);

	while(1)	{
		// if(twcl.listen())	{
		// 	if(twcl.checkForError())	{

		// 	}else	{
		// 		TPacket packet = twcl.getPacket();
		// 		twcl.send(packet);
		// 	}
		// }
	}
}