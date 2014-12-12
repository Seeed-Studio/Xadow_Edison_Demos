Xadow_Edison_Demos
==================

Xadow Edison demos, Arduino compatible

Declaration：
	This project is assembled with two repositories https://github.com/don/NDEF https://github.com/Seeed-Studio/PN532 and I modified two files:
	1. Hacked F() by adding #define __SAM3X8E__ in NDEF/Due.h
	2. Changed enum member NONE to _NONE in PN532/emulatetag.cpp


This project mainly include two demos Cool_light and GlowingTemperature.

To Getting start:

1. Cool_light
	Prepare three or one NFC Tag, write message into them by demo Cool_Light_WriteTag (open the demo see the details)

2. GlowingTemperature:
	
	
