# Overview #

1ump is a project started with a goal to develope software and hardware tools needed to create fast, simple and reliable communication networks with focus on embedded devices. The advantage of 1ump solution and CLIN communication protocol, that will be developed in the scope of this projects, is that it will be Open Source, easy and cheap to implement.

## Milestones ##

- Design and test CLIN interface.
- Design child interface schematic.
- Design parent interface schematic.
- Design and test prototype boards.
- Push revision 1 boards.
- Write API for Arduino, Mbed, AVR and STM platforms.
- Write desktop application for network monitoring and control.

## Custom communication protocol ##

This project will use custom communication protocol called CLIN Protocol (for short CLIN) that is developed in the scope of this project. The goal of CLIN is to allow simple and easy-to-use communication protocol for connecting virtually infinite number of devices with few hardware wires as possible while allowing fast and reliable data transfer. Since UART is widely used, it is supported by majority of MCUs and it can be easily converted to USB protocol, therefore CLIN is based on it. CLIN uses some software and hardware implementations on top of UART to allow data transfer between devices connected to communication bus (in CLIN network).

## Abstract ##

UART is a simple protocol that uses only 2 wires for communication, one is TX (transmit line) and other is RX (receive line). To establish communication between two devices over UART, TX line of one device is connected to RX line of other and vice versa, as shown in Figure 1. If there is more then 2 devices that need to be connected together, there is only one way to connect them over UART with out introducing additional components and that is daisy-chaining devices as shown in Figure 2. This is not a major problem if 3 to 4 devices are in network, big problem arise when there are even more devices in the network. By using daisy-chain, if the first device needs to communicate with last device in the chain, communication packet first needs to pass thru all devices in between them. This is time consuming and can not be implemented in real-time systems, on top of that all devices in middle of the chain need to have 2 UARTs and handle packets that are not for them.  

![Figure 1](https://i.imgur.com/cqJ2QVV.png)

_Figure 1 - Connecting 2 devices over UART._

![Figure 2](https://i.imgur.com/AV0xYTC.png)

_Figure 2 - Connecting more then 2 devices over UART using daisy-chain configuration._

As it can be concluded, this is not very practical, therefore daisy-chain can not be main solution. I2C and SPI will not be considered because I2C is limited to 127 devices in network and SPI uses to many cables and both of them can not be easily converted into USB protocol.

To connect more then 2 devices over UART, interface needs to be implemented as shown in Figure 3. Interface block is the hardware level block which purpose is to allow all devices connected together to pull down RX line of master device. In this configuration slave-to-slave communication can not be achieved. Communication packet will first be transmitted to master device and then be broadcasted to all slave devices in network. This solution has one major problem, since all slave devices are connected to the same lines, 2 or more slave devices can start transmitting at the same time. This will result in error on the master side because data will not have valid format. For this to be solved 1 more wire is included in network that is called BUSY line as shown in Figure 4. This line is used to check if communication bus is free for transmission. For example, every time before slave device transmit data to master, it will check BUSY line. If the line is free (not set) that means that bus is free and that packet can be transmitted. Before transmitting packet, slave device will set BUSY line telling all other slave devices that bus is not free for transmission. This will not completely remove simultaneous transmission that more devices but it will minimize it to insignificant level. 

![Figure 3](https://i.imgur.com/K0kT39E.png)

_Figure 3 - Basic idea for connecting more then 2 devices over 1 UART. Basic TWCL network._

![Figure 4](https://i.imgur.com/snl8ERU.png)

_Figure 4 - Full TWCL network._

## TWCL Network configurations ##

TWCL communication is based on master/slave relationship between devices. There are 2 types of bus lines, master bus and slave bus. There can be many configuration but the typical configuration is to have one master bus that have one master device and many slave-master devices connected to it, while slave-master devices has there own slave bus. This configuration is shown in Figure 4.

In same slave bus, direct slave-to-slave communication can not be achieved, instead slave will send packet to master and master will redirect it to selected slave. In time sensitive application this packet propagation time needs to be considered and it is based on communication speed and master redirect time. For slave-to-slave communication between to different bus lines, propagation time is even longer and is depending on number of redirects. For example (follow the Figure 4), if SLAVE 11 want to send packet to SLAVE 02, packet will first go to SLAVE1/MASTER, then it will be redirected to MASTER and then it will be redirected to SLAVE 02. In this way packet needs to go thru 2 redirect stages. Packet that is sent by master device is always broadcasted with the address of the device that is sending the packet and address of the device where packet needs to go. This means that all slave devices in the bus will receive packet sent by master but only the device with good packet address will process it. Same is applicable to slave-master bus line.

- Basic network configuration shown in figure 3.
- Full or extended network configuration shown in figure 4.
- Nested network configuration shown in figure 5.
- Combined network.

![Figure 5]()

_Figure 5 - Nested TWCL network configuration._