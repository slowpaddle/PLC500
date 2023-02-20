#include <PLC500.h>

/*
 PLC500.h - Description and Usage
 Dave Gillen - davebuildsthings.ca
 February 16, 2022
 This library and sample code is open source and free to use/modify.
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
 eg: setY(1, HIGH) / Sets the output. / Options (HIGH/LOW), (true/false), (ON/OFF)

 function: setYA(n, v) _ Analog Outputs YA1 to YA8
 Writes a value where n is the analog output number on the PLC500 board.
 eg: setYA(1, 899) / Sets the output.
*/

void setup() {
  PLC500Setup();  // Initializes Inputs and Outputs
}

void loop() {
  
  for (int i=1; i<13; i++) {  	// Read the input pins
    if(readX(i) == ON) {      	// If the input is ON/true/HIGH, turn the same numbered output ON/true/HIGH
      setY(i, ON);
    }
    else {						// If the input is OFF/false/LOW, turn the same numbered output OFF/false/LOW
      setY(i, OFF);
    }
  }
  
}
