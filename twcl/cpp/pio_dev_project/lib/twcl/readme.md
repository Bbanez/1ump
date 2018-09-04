# Error Codes #

CODE   | LEVEL     | PLACE                | DESCRIPTION
------ | --------- | -------------------- | -----------
0x0000 | Not set   | NONE                 | Not set.
0x0005 | Exception | TPacket.build()      | START or Stop byte does not exists in build string.
0x0006 | Exception | TPacket.build()      | One or more SPLIT bytes are not at expected position.
0x0007 | Exception | TPacket.build()      | Can not get MESSAGE part of the packet. Substring function return -1.
0x0008 | Warning   | THandler.init()      | Can not pull BUSY line of TWCL bus.
0x0009 | Warning   | THandler::THandler() | Can not pull BUSY line of TWCL bus.
0x000A | Exception | THandler.listen()    | Can not build packet.
0x000B | Exception | THandler.listen()    | Maximum software buffer size exceeded.
0x000C | Exception | THandler.listen()    | Expected SPLIT byte at position 5 of receiving packet.
0x000D | Exception | THandler.listen()    | Expected SPLIT byte at position 10 of receiving packet.
0x000E | Exception | THandler.listen()    | Expected SPLIT byte at position 15 of receiving packet.