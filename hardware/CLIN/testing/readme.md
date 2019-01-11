# TWCL Communication Testing #

TWCL network testing will be given here. This way anyone interested can setup network at there home and improve software or hardware for it. This document is intended as a proof of concept. For advanced development and/or improvement it is recommended to build 1ump MASTER and SLAVE boards from files provided in this project under _root/pcbs_ directory.

## Interface effects on input signal ##

ATmega2560 is used as a signal generator. Circuit is connected on test board according to sheet 2 in _TWCL-network-test-circuits.pdf_. Use shortest wires possible and populate the test board with components.

![Figure 1](https://i.imgur.com/qDV7Va2.png)
_Figure 1 - Signal propagation diagram._

- tPHL = 15.2ns
- tPLH = 41ns
- tr = 7ns
- tf = 4.8ns

![Figure 2](https://i.imgur.com/9HwXNBp.jpg)
_Figure 2 - Test results of signal propagation. Input: square wave of 500kHz frequency, equal to 1Mbps transfer speed._

![Figure 3](https://i.imgur.com/Q3FfIRL.jpg)
_Figure 3 - Propagation of 1 byte of UART packet at 1000000 baud thru interface._

As it can be seen, some noise and oscillations at introduced to output signal in addition to signal propagation delay. This delay will not be problematic for targeted maximum baud of 1000000 but oscillation spikes can cause damage to sensitive electronics and will cause problems with EMC compliance. This problem will be solved in circuit design and PCB design of final boards.

## Basic network testing ##

## Extended network testing ##