# Canaduino PLC500

This Arduino library is intend for use with the CANADUINO PLC 500 Series boards.
This library and sample code is open source and free to use/modify.

--------------------------------------------------------------------------------
The intent of this library is to simplify the process of accessing the inputs and outputs on the board using the board naming convention.

PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino 

PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino
--------------------------------------------------------------------------------
Create an instance of PLC500

	PLC500 plc;
--------------------------------------------------------------------------------
function: plc.begin() / REQUIRED!

	This routine initializes all of the pins for their respective use on the PLC500 board and turns all
	outputs off on start-up.

--------------------------------------------------------------------------------
function: plc.readX(n) - Digital Inputs X1 to X16

	Reads the value of a digital input where n is the digital input number on the PLC500 board.

eg: plc.readX(2) / Returns the value as bool. (HIGH/LOW), (true/false), (ON/OFF)

--------------------------------------------------------------------------------
function: plc.readXA(n) - Analog Inputs XA1 to XA16

	Reads the value of an analog input where n is the analog input number on the PLC500 board.
	XA1 thru XA8 : 5V reads 511, 10V reads 1023
	XA9 thru XA12 : 4mA reads 205, 20mA reads 1023
	XA13 thru XA16 : 5V Max Input reads 1023

eg: plc.readXA(2) / Returns the value as int.

--------------------------------------------------------------------------------
function: plc.readY(n) - Digital Outputs Y1 to Y12

	Reads the value of a digital input where n is the digital input number on the PLC500 board.

eg: plc.readY(2) / Returns the value as bool. (HIGH/LOW), (true/false), (ON/OFF)

--------------------------------------------------------------------------------
function: plc.readYA(n) - Analog Outputs YA1 to YA8

	Writes a value where n is the analog output number on the PLC500 board.

eg: setYA(1, 899) / Reads the value.

--------------------------------------------------------------------------------
function: plc.setY(n, v) - Digital Outputs Y1 to Y12

	Writes a value where n is the digital output number on the PLC500 board and
	v is the value.
	
eg: plc.setY(1, HIGH) / Sets the output.

Options (HIGH/LOW), (true/false), (ON/OFF)

--------------------------------------------------------------------------------
function: plc.setYA(n, v) - Analog Outputs YA1 to YA8

	Writes a value where n is the analog output number on the PLC500 board and
	v is the value. (0 to 255)
	Values for YA1 & YA2: 0 causes 4mA, 255 causes 20mA (Using the 4-20ma output pins.)
	Values for YA1 & YA8: 127 causes 5V, 255 causes 10V (Using the voltage output pins.)

eg: plc.setYA(1, 127) / Sets the output.

--------------------------------------------------------------------------------
	//Example Code
	#include <PLC500.h>
	PLC500 plc;
	
	void setup() {
	  plc.begin();  // Initializes Inputs and Outputs
	}

	void loop() {  
	  for (int i=1; i<13; i++) {  	// Read the input pins
	    if(plc.readX(i) == ON) {      	// If the input is ON/true/HIGH, turn the same numbered output ON/true/HIGH
	      plc.setY(i, ON);
	    }
	    else {	// If the input is OFF/false/LOW, turn the same numbered output OFF/false/LOW
	      plc.setY(i, OFF);
	    }
	  }
	}
	
	/*
	* Alternatively
	*
	*	for (int i=1; i<13; i++) {  	// Read the input pins
	*
	*		plc.setY(i,(plc.readX(i) == ON) ? ON : OFF);     // Set the output pins
	*
	*		Or Simply
	*
	*		plc.setY(i,(plc.readX(i));	// Set the output pins to input pin state
  	*	}
	*
	*/
	
