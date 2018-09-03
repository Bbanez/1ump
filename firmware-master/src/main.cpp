#include "Arduino.h"
#include "THandler.h"

void setup() {
}

void loop() {
	THandler twcl(TAddress(192, 168, 0, 0), TAddress(192, 168, 0, 4), MASTER);
	twcl.init(115200, &Serial, 9, 10);
	TAddress to(192, 168, 0, 65);
	TDescription des(FLOAT, 123, 122, 121);
	TMessage msg;
	msg.set(45.123);
	pinMode(13, OUTPUT);
	digitalWrite(13, 0);
	Serial.println(to.get());
	Serial.println(msg.get());
	while(1)	{
		// if(twcl.listen())	{
		// 	digitalWrite(13, 1);
		// 	delay(100);
		// 	digitalWrite(13, 0);
		// }
		twcl.send(to, des, msg);
		delay(1500);
		digitalWrite(13, 1);
		delay(100);
		digitalWrite(13, 0);
		// to.set(0, to.get((unsigned char)0) + 1);
	}
}