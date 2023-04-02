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
  Serial.begin(115200); // opens serial port 3, sets data rate to 115200 bps
  plc.begin();  // Initializes Inputs and Outputs

  Serial.println();

  Serial.println("Read Digital Inputs");
  Serial.println("===================");
  for(int i=1; i<17; i++) {
    Serial.print("plc.readX(");
    Serial.print(i);
    Serial.print(") ");
      Serial.println(plc.readX(i));
  }
    
  Serial.println();

  Serial.println("Read Analog Inputs");
  Serial.println("=================");
  for(int i=1; i<9; i++) {
    Serial.print("plc.readXA(");
    Serial.print(i);
    Serial.print(") ");
      Serial.println(plc.readXA(i));
  }
  
  Serial.println();  
  
  Serial.println("Read Digital Outputs");
  Serial.println("==================");
  for(int i=1; i<13; i++) {
    Serial.print("plc.readY(");
    Serial.print(i);
    Serial.print(") ");
    Serial.println(plc.readY(i));
  }

  Serial.println();
  
  Serial.println("Read Analog Outputs");
  Serial.println("===================");
  for(int i=1; i<9; i++) {
    Serial.print("plc.readYA(");
    Serial.print(i);
    Serial.print(") ");
    Serial.println(plc.readYA(i));
  }
  Serial.println();
  
  Serial.println("Set Analog Outputs");
  Serial.println("==================");
  for(int i=1; i<9; i++) {
    Serial.print("plc.setYA(");
    Serial.print(i);
    Serial.println(", 255) ");
    plc.setYA(i, 255);
  }

  Serial.println();
  Serial.println("Turning on Digital Outputs");
  Serial.println("Set Digital Outputs");
  Serial.println("===================");
  for(int i=1; i<13; i++) {
    Serial.print("plc.setY(");
    Serial.print(i);
    Serial.println(", HIGH) ");
    plc.setY(i, HIGH);
  }

  Serial.println();
    
  Serial.println("Read Digital Outputs");
  Serial.println("====================");
  for(int i=1; i<13; i++) {
    Serial.print("plc.readY(");
    Serial.print(i);
    Serial.print(") ");
    Serial.println(plc.readY(i));
  }
  
  Serial.println();
  Serial.println("Wait.....");
  delay(2000);

Serial.println();
  
  Serial.println("Set Digital Outputs");
  Serial.println("===================");
  for(int i=1; i<13; i++) {
    Serial.print("plc.setY(");
    Serial.print(i);
    Serial.println(", LOW) ");
    plc.setY(i, LOW);
  }
  
  Serial.println();
  Serial.println("Digital Outputs are Off");
}

void loop() {  
  
}
