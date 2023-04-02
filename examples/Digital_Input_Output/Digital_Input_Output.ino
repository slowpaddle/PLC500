#include <PLC500.h>

/*
 PLC500.h - Description and Usage
 Dave Gillen - davebuildsthings.ca
 Written February 16, 2022 / Updated April 2, 2023
 This library and sample code is open source and free to use/modify.
 --------------------------------------------------------------------------------------------------------------------------------
 This library is intend for use with the CANADUINO PLC 500 Series boards.
 The intent is to simplify the process of accessing the inputs and outputs on the board using the board naming convention.
 PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino/
 PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino/
 --------------------------------------------------------------------------------------------------------------------------------
 Create an instance of PLC500
 Eg.: PLC500 plc;
 --------------------------------------------------------------------------------
 function: plc.begin() / REQUIRED!
 This routine initializes all of the pins for their respective use on the PLC500 board and turns all outputs off on start.

 function: plc.readX(n) - Digital Inputs X1 to X16
 Reads the value of a digital input where n is the digital input number on the PLC500 board.
 eg: plc.readX(2) / Returns the value as bool. (HIGH/LOW), (true/false)

 function: plc.readXA(n) - Analog Inputs XA1 to XA16
 Reads the value of an analog input where n is the analog input number on the PLC500 board.
 eg: plc.readXA(2) / Returns the value as int.

 function: plc.setY(n, v) - Digital Outputs Y1 to Y12
 Writes a value where n is the digital output number on the PLC500 board.
 eg: plc.setY(1, HIGH) / Sets the output. / Options (HIGH/LOW), (true/false)

 function: plc.setYA(n, v) _ Analog Outputs YA1 to YA8
 Writes a value where n is the analog output number on the PLC500 board.
 eg: plc.setYA(1, 899) / Sets the output.
*/

PLC500 plc;

void setup() {
  plc.begin();  // Initializes Inputs and Outputs
}

void loop() {
  
  for (int i=1; i<13; i++) {  	// Read the input pins
    if(plc.readX(i) == HIGH) {      	// If the input is true/HIGH, turn the same numbered output true/HIGH
      plc.setY(i, HIGH);
    }
    else {						// If the input is false/LOW, turn the same numbered output false/LOW
      plc.setY(i, LOW);
    }
  }
  
}
