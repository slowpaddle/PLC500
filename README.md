# PLC500

This Arduino library is intend for use with the CANADUINO PLC 500 Series boards.
This library and sample code is open source and free to use/modify.

--------------------------------------------------------------------------------
The intent of this library is to simplify the process of accessing the inputs and outputs on the board using the board naming convention.

PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino 

PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino

--------------------------------------------------------------------------------
function: PLC500Setup() / REQUIRED!

	This routine initializes all of the pins for their respective use on the PLC500 board and turns all
	outputs off on start-up.

--------------------------------------------------------------------------------
function: readX(n) - Digital Inputs X1 to X16

	Reads the value of a digital input where n is the digital input number on the PLC500 board.

eg: readX(2) / Returns the value as bool. (HIGH/LOW), (true/false), (ON/OFF)

--------------------------------------------------------------------------------
function: readXA(n) - Analog Inputs XA1 to XA12

	Reads the value of an analog input where n is the analog input number on the PLC500 board.
	XA1 thru XA8 : 5V reads 511, 10V reads 1023
	XA9 thru XA12 : 4mA reads 205, 20mA reads 1023

eg: readXA(2) / Returns the value as int.

--------------------------------------------------------------------------------
function: readY(n) - Digital Outputs Y1 to Y12

	Reads the value of a digital input where n is the digital input number on the PLC500 board.

eg: readY(2) / Returns the value as bool. (HIGH/LOW), (true/false), (ON/OFF)

--------------------------------------------------------------------------------
function: readYA(n) - Analog Outputs YA1 to YA8

	Writes a value where n is the analog output number on the PLC500 board.

eg: setYA(1, 899) / Reads the value and returns it as an int.

--------------------------------------------------------------------------------
function: setY(n, v) - Digital Outputs Y1 to Y12

	Writes a value where n is the digital output number on the PLC500 board and
	v is the value.
	
eg: setY(1, HIGH) / Sets the output, reads the changed state and returns it as a bool.

Options (HIGH/LOW), (true/false), (ON/OFF)

--------------------------------------------------------------------------------
function: setYA(n, v) - Analog Outputs YA1 to YA8

	Writes a value where n is the analog output number on the PLC500 board and
	v is the value. (0 to 255)
	Values for YA1 & YA2: 0 causes 4mA, 255 causes 20mA (Using the 4-20ma output pins.)
	Values for YA1 & YA8: 127 causes 5V, 255 causes 10V (Using the voltage output pins.)

eg: setYA(1, 127) / Sets the output, reads the changed value and returns it as an int.

--------------------------------------------------------------------------------
	//Example Code
	#include <PLC500.h>

	void setup() {
	  PLC500Setup();  // Initializes Inputs and Outputs
	}

	void loop() {  
	  for (int i=1; i<13; i++) {  	// Read the input pins
	    if(readX(i) == ON) {      	// If the input is ON/true/HIGH, turn the same numbered output ON/true/HIGH
	      setY(i, ON);
	    }
	    else {	// If the input is OFF/false/LOW, turn the same numbered output OFF/false/LOW
	      setY(i, OFF);
	    }
	  }
	}
	
	/*
	* Alternatively
	*
	*	for (int i=1; i<13; i++) {  	// Read the input pins
	*		setY(i,(readX(i) == ON) ? 1 : 0);     // Set the output pins
  	*	}
	*
	*/
	
