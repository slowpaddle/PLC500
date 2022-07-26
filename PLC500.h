#ifndef PLC500_h
#define PLC500_h

#include "Arduino.h"

/*
 PLC500.h - Description and Usage
 Dave Gillen - handcrafteddesigns.ca
 February 16, 2022
 This library and same code is open source and free to use/modify.
 --------------------------------------------------------------------------------------------------------------------------------
 This library is intend for use with the CANADUINO PLC 500 Series boards.
 The intent is to simplify the process of accessing the inputs and outputs on the board using the board naming convention.
 PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino/
 PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino/
 --------------------------------------------------------------------------------------------------------------------------------
 function: PLC500Setup() / REQUIRED!
 This routine initializes all of the pins for their respective use on the PLC500 board and turns all outputs off on start.

 function: readX(n) - Digital Inputs X1 to X16
 Reads the value of a digital input where n is the digital input number on the PLC500 board.
 eg: readX(2) / Returns the value as bool. (HIGH/LOW), (true/false), (ON/OFF)

 function: readXA(n) - Analog Inputs XA1 to XA16
 Reads the value of an analog input where n is the analog input number on the PLC500 board.
 eg: readXA(2) / Returns the value as int.

 function: setY(n, v) - Digital Outputs Y1 to Y12
 Writes a value where n is the digital output number on the PLC500 board.
 eg: setY(1, HIGH) / Sets the output, reads the changed state and returns it as a bool. / Options (HIGH/LOW), (true/false), (ON/OFF)

 function: setYA(n, v) _ Analog Outputs YA1 to YA8
 Writes a value where n is the analog output number on the PLC500 board.
 eg: setYA(1, 899) / Sets the output, reads the changed value and returns it as an int.
*/

// Digital States
#define ON HIGH
#define OFF LOW

//RS232 Pins
#define RX1 19
#define TX1 18
#define RX2 17
#define TX2 16

// =============================================================
// Set up the inputs and outputs	
// =============================================================
void PLC500Setup();

// =============================================================
// Set the state of a digital output
// eg: setY(2, HIGH)
// eg: setY(2, ON)
// eg: bool value = setY(2, true)
// Returns the read state of the changed output
// =============================================================
bool setY(int x, bool y);

// =============================================================
// Set the value of an analog output
// eg: int value = setY(1, 1000)
// Returns the read state of the changed output
// =============================================================
int setYA(int x, int y);

// =============================================================
// Read the state of a digital input
// eg: bool value = readX(4)
// Returns the read state of the input
// =============================================================
bool readX(int x);

// =============================================================
// Read the state of a digital output
// eg: bool value = readY(4)
// Returns the read state of the output
// =============================================================
bool readY(int x);

// =============================================================
// Read the value of an analog input
// eg: int value = readXA(5)
// Returns the read state of the input
// =============================================================
int readXA(int x);

// =============================================================
// Read the value of an analog input
// eg: int value = readXA(5)
// Returns the read state of the input
// =============================================================
int readYA(int x);

#endif