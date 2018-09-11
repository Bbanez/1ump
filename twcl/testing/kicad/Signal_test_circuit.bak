EESchema Schematic File Version 4
LIBS:twcl_test_circuit-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "TWCL interface signal propagation test circuit."
Date "2018-09-11"
Rev "1.0"
Comp "1ump - Open Source"
Comment1 ""
Comment2 "UART packet transmistion success."
Comment3 "ATmega2560 used as a square wave generator."
Comment4 "Tested with TH components on test board with 1kHz-500kHz square wave."
$EndDescr
$Comp
L Transistor_FET:BS170 Q?
U 1 1 5B98227B
P 5800 3850
AR Path="/5B98227B" Ref="Q?"  Part="1" 
AR Path="/5B97FA90/5B98227B" Ref="Q201"  Part="1" 
F 0 "Q201" H 6005 3896 50  0000 L CNN
F 1 "BS170" H 6005 3805 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6000 3775 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BS/BS170.pdf" H 5800 3850 50  0001 L CNN
	1    5800 3850
	1    0    0    -1  
$EndComp
Text GLabel 4700 3750 0    50   Input ~ 0
IN
$Comp
L power:Earth #PWR?
U 1 1 5B982284
P 5900 4050
AR Path="/5B982284" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B982284" Ref="#PWR0203"  Part="1" 
F 0 "#PWR0203" H 5900 3800 50  0001 C CNN
F 1 "Earth" H 5900 3900 50  0001 C CNN
F 2 "" H 5900 4050 50  0001 C CNN
F 3 "~" H 5900 4050 50  0001 C CNN
	1    5900 4050
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC00 U?
U 1 1 5B98228A
P 5300 3850
AR Path="/5B98228A" Ref="U?"  Part="1" 
AR Path="/5B97FA90/5B98228A" Ref="U201"  Part="1" 
F 0 "U201" H 5300 4175 50  0000 C CNN
F 1 "74HC00" H 5300 4084 50  0000 C CNN
F 2 "" H 5300 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc00" H 5300 3850 50  0001 C CNN
	1    5300 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5B982291
P 4900 3600
AR Path="/5B982291" Ref="R?"  Part="1" 
AR Path="/5B97FA90/5B982291" Ref="R201"  Part="1" 
F 0 "R201" H 4970 3646 50  0000 L CNN
F 1 "10k" H 4970 3555 50  0000 L CNN
F 2 "" V 4830 3600 50  0001 C CNN
F 3 "~" H 4900 3600 50  0001 C CNN
	1    4900 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3750 4900 3750
$Comp
L power:VCOM #PWR?
U 1 1 5B982299
P 4900 3450
AR Path="/5B982299" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B982299" Ref="#PWR0201"  Part="1" 
F 0 "#PWR0201" H 4900 3300 50  0001 C CNN
F 1 "VCOM" H 4917 3623 50  0000 C CNN
F 2 "" H 4900 3450 50  0001 C CNN
F 3 "" H 4900 3450 50  0001 C CNN
	1    4900 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3450 4800 3450
Wire Wire Line
	4800 3450 4800 3950
Wire Wire Line
	4800 3950 5000 3950
Connection ~ 4900 3450
Wire Wire Line
	4700 3750 4900 3750
Connection ~ 4900 3750
$Comp
L Device:R R?
U 1 1 5B982373
P 5900 3350
AR Path="/5B982373" Ref="R?"  Part="1" 
AR Path="/5B97FA90/5B982373" Ref="R202"  Part="1" 
F 0 "R202" H 5970 3396 50  0000 L CNN
F 1 "1k" H 5970 3305 50  0000 L CNN
F 2 "" V 5830 3350 50  0001 C CNN
F 3 "~" H 5900 3350 50  0001 C CNN
	1    5900 3350
	1    0    0    -1  
$EndComp
$Comp
L power:VCOM #PWR?
U 1 1 5B98237A
P 5900 3200
AR Path="/5B98237A" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B98237A" Ref="#PWR0202"  Part="1" 
F 0 "#PWR0202" H 5900 3050 50  0001 C CNN
F 1 "VCOM" H 5917 3373 50  0000 C CNN
F 2 "" H 5900 3200 50  0001 C CNN
F 3 "" H 5900 3200 50  0001 C CNN
	1    5900 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:D_ALT D?
U 1 1 5B982380
P 5600 3350
AR Path="/5B982380" Ref="D?"  Part="1" 
AR Path="/5B97FA90/5B982380" Ref="D201"  Part="1" 
F 0 "D201" V 5600 3429 50  0000 L CNN
F 1 "D_ALT" V 5645 3429 50  0001 L CNN
F 2 "" H 5600 3350 50  0001 C CNN
F 3 "~" H 5600 3350 50  0001 C CNN
	1    5600 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 3500 5600 3500
Connection ~ 5900 3500
Wire Wire Line
	5600 3200 5900 3200
Connection ~ 5900 3200
Wire Wire Line
	5900 3650 5900 3500
$Comp
L 74xx:74HC244 U?
U 1 1 5B98252A
P 6800 4000
AR Path="/5B98252A" Ref="U?"  Part="1" 
AR Path="/5B97FA90/5B98252A" Ref="U202"  Part="1" 
F 0 "U202" H 6500 4750 50  0000 C CNN
F 1 "74HC244" H 6500 4650 50  0000 C CNN
F 2 "" H 6800 4000 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT244.pdf" H 6800 4000 50  0001 C CNN
	1    6800 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5B982531
P 6150 4400
AR Path="/5B982531" Ref="R?"  Part="1" 
AR Path="/5B97FA90/5B982531" Ref="R203"  Part="1" 
F 0 "R203" V 5943 4400 50  0000 C CNN
F 1 "10k" V 6034 4400 50  0000 C CNN
F 2 "" V 6080 4400 50  0001 C CNN
F 3 "~" H 6150 4400 50  0001 C CNN
	1    6150 4400
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5B982538
P 6800 4800
AR Path="/5B982538" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B982538" Ref="#PWR0207"  Part="1" 
F 0 "#PWR0207" H 6800 4550 50  0001 C CNN
F 1 "Earth" H 6800 4650 50  0001 C CNN
F 2 "" H 6800 4800 50  0001 C CNN
F 3 "~" H 6800 4800 50  0001 C CNN
	1    6800 4800
	1    0    0    -1  
$EndComp
$Comp
L power:VCOM #PWR?
U 1 1 5B98253E
P 6800 3100
AR Path="/5B98253E" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B98253E" Ref="#PWR0206"  Part="1" 
F 0 "#PWR0206" H 6800 2950 50  0001 C CNN
F 1 "VCOM" H 6817 3273 50  0000 C CNN
F 2 "" H 6800 3100 50  0001 C CNN
F 3 "" H 6800 3100 50  0001 C CNN
	1    6800 3100
	1    0    0    -1  
$EndComp
$Comp
L power:VCOM #PWR?
U 1 1 5B982544
P 6000 4500
AR Path="/5B982544" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B982544" Ref="#PWR0205"  Part="1" 
F 0 "#PWR0205" H 6000 4350 50  0001 C CNN
F 1 "VCOM" V 6018 4628 50  0000 L CNN
F 2 "" H 6000 4500 50  0001 C CNN
F 3 "" H 6000 4500 50  0001 C CNN
	1    6000 4500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5B98254A
P 6150 4500
AR Path="/5B98254A" Ref="R?"  Part="1" 
AR Path="/5B97FA90/5B98254A" Ref="R204"  Part="1" 
F 0 "R204" V 6050 4500 50  0000 C CNN
F 1 "10k" V 5950 4500 50  0000 C CNN
F 2 "" V 6080 4500 50  0001 C CNN
F 3 "~" H 6150 4500 50  0001 C CNN
	1    6150 4500
	0    -1   -1   0   
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5B982551
P 6000 4400
AR Path="/5B982551" Ref="#PWR?"  Part="1" 
AR Path="/5B97FA90/5B982551" Ref="#PWR0204"  Part="1" 
F 0 "#PWR0204" H 6000 4150 50  0001 C CNN
F 1 "Earth" H 6000 4250 50  0001 C CNN
F 2 "" H 6000 4400 50  0001 C CNN
F 3 "~" H 6000 4400 50  0001 C CNN
	1    6000 4400
	0    1    1    0   
$EndComp
NoConn ~ 6300 3800
NoConn ~ 6300 3900
NoConn ~ 6300 4000
NoConn ~ 6300 4100
NoConn ~ 6300 4200
NoConn ~ 7300 3800
NoConn ~ 7300 3900
NoConn ~ 7300 4000
NoConn ~ 7300 4100
NoConn ~ 7300 4200
$Comp
L Device:R R?
U 1 1 5B982564
P 7300 3250
AR Path="/5B982564" Ref="R?"  Part="1" 
AR Path="/5B97FA90/5B982564" Ref="R205"  Part="1" 
F 0 "R205" H 7370 3296 50  0000 L CNN
F 1 "1k" H 7370 3205 50  0000 L CNN
F 2 "" V 7230 3250 50  0001 C CNN
F 3 "~" H 7300 3250 50  0001 C CNN
	1    7300 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3400 7300 3500
Wire Wire Line
	7300 3100 6800 3100
Wire Wire Line
	6800 3100 6800 3200
Connection ~ 6800 3100
Text GLabel 7400 3500 2    50   Output ~ 0
OUT
Wire Wire Line
	7400 3500 7300 3500
Connection ~ 7300 3500
NoConn ~ 6300 3700
NoConn ~ 6300 3600
NoConn ~ 7300 3600
NoConn ~ 7300 3700
Wire Wire Line
	6300 3500 5900 3500
$EndSCHEMATC
