# Overview #

1ump is a project which goal is to develope hardware and software tools for MCU networks. Idea is to develope hardware interface that will allow virtually unlimited number of MCU devices to be connected together with fast data transfer between them so this implementation can be used in real-time systems. Hardware needs to be as cheap as possible but it must be highly reliable, since for the future idea is to make this product industry ready. Second part is developing software tools that will be used with the hardware. That includes all firmware and PC tools that will be needed to setting up the network and monitoring it.

# Project Description #

> desktop-app

- Desktop application written in Java.
- Runnable cross platform application.
- Source files of the Java project.

> firmware-master

- Firmware for MCU on 1ump master board.
- Standalone firmware upload tools.
- Source files for firmware of 1ump master board written as C++ using PlatformioIDE.

> firmware-slave

- Firmware for MCU on 1ump slave board.
- Standalone firmware upload tools.
- Source files for firmware of 1ump slave board written as C++ using PlatformioIDE.

> kicad-v5

- Source projects of 1ump hardware designed using Kicad 5.

> pcbs

- GERBER files for 1up boards.

> schematics

- Schematics of 1ump boards.

# Custom communication protocol #

This project will use custom communication protocol called TWCL Communication Protocol (for short TWCL) that is developed in the scope of this project. The goal of TWCL is to allow simple and easy-to-use communication protocol for connecting virtually infinite number of devices with few hardware wires as possible while allowing fast and reliable data transfer. Since UART is widely used, it is supported by majority of MCUs and it can be easily converted to USB protocol, TWCL is based on it. TWCL communication uses some software and hardware implementations on top of UART to allow data transfer between devices connected to communication bus (in TWCL network).

## Abstract ##

UART is a simple protocol that uses only 2 wires for communication, one is TX (transmit line) and other is RX line (receive line). To establish communication between two devices over UART, TX line of one device is connected to RX line of other and vice versa, as shown in Figure XXXX. If there is more then 2 devices that need to be connected together there is only one way to connect them over UART with out introducing additional components and that is daisy-chaining devices as shown in Figure XXXX. This is not a major problem if 3 to 4 devices are in network, big problem arise when there are even more devices in network. By using daisy-chain, if the first device needs to communicate with last device in the chain, communication packet first needs to pass thru all devices in between them. This is time consuming and can not be implemented in real-time systems, on top of that all devices in middle of the chain need to have 2 UARTs.  

![Figure 1](https://i.imgur.com/6Op9Tdw.jpg)

_Figure 1 - Connecting 2 devices over UART._

![Figure 2](https://i.imgur.com/6Op9Tdw.jpg)

_Figure 2 - Connecting more then 2 devices over UART using daisy-chain configuration._

TWCL communication is based on master/slave relationship between devices. There are 2 types of bus lines, master bus and slave bus. There can be 


There can be many configuration but the typical configuration
is to have one master bus that have one master and many slave-master devices connected to it, while
slave-master devices has there own slave bus. This configuration is shown in Figure XXXX.
In TWCL same slave bus, direct slave to slave communication can not be achieved, instead slave
will send packet to master and master will redirect it to selected slave. In time sensitive application
this packet propagation time needs to be considered and it is based on communication speed and
master redirect time. For slave to slave communication between to different bus lines, propagation
time is even longer.
For example (follow the Figure XXXX), is SLAVE 11 want to send packet to SLAVE 02, packet
will first go to SLAVE1/MASTER, then it will be redirected to MASTER, then it will be redirected
to SLAVE 02. In this way packet needs to do thru 2 redirect stages.
Packet that is sent by master device is always broadcasted with the address of the device that is
sending the packet and address of the device where packet needs to go. This means that all slave
devices in the bus will receive packet but only the device with packet address will process it. Same
is applicable to slave-master bus line.