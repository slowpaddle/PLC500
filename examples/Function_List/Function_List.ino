/*
 PLC500.h - Description and Usage
 Dave Gillen - handcrafteddesigns.ca
 February 16, 2022
 This library and sample code is open source and free to use/modify.
 --------------------------------------------------------------------------------------------------------------------------------
 This library is intend for use with the CANADUINO PLC 500 Series boards.
 The intent is to simplify the process of accessing the inputs and outputs on the board using the board naming convention.
 PLC 500-AC - https://universal-solder.ca/product/canaduino-plc-500-ac-industrial-plc-120-240v-ac-wifi-compatible-with-arduino/
 PLC 500-24 - https://universal-solder.ca/product/canaduino-plc-500-24-industrial-plc-12-24v-dc-wifi-compatible-with-arduino/
 --------------------------------------------------------------------------------------------------------------------------------
 View the Read_Me Example for additional information.
*/

#include <PLC500.h>


void setup() {
Serial.begin(115200); // opens serial port 3, sets data rate to 115200 bps
PLC500Setup();  // Initializes Inputs and Outputs



  Serial.println();

  Serial.println("Read Digital Inputs");
  Serial.println("===================");
  for(int i=1; i<17; i++) {
    Serial.print("readX(");
    Serial.print(i);
    Serial.print(") ");
      Serial.println(readX(i));
  }
    
  Serial.println();

  Serial.println("Read Analog Inputs");
  Serial.println("=================");
  for(int i=1; i<9; i++) {
    Serial.print("readXA(");
    Serial.print(i);
    Serial.print(") ");
      Serial.println(readXA(i));
  }
  
  Serial.println();  
  
  Serial.println("Read Digital Outputs");
  Serial.println("==================");
  for(int i=1; i<13; i++) {
    Serial.print("readY(");
    Serial.print(i);
    Serial.print(") ");
    Serial.println(readY(i));
  }

  Serial.println();
  
  Serial.println("Read Analog Outputs");
  Serial.println("===================");
  for(int i=1; i<9; i++) {
    Serial.print("readYA(");
    Serial.print(i);
    Serial.print(") ");
      Serial.println(readYA(i));
  }
  Serial.println();
  
  Serial.println("Set Analog Outputs");
  Serial.println("==================");
  for(int i=1; i<9; i++) {
    Serial.print("setYA(");
    Serial.print(i);
    Serial.println(", 255) ");
    setYA(i, 255);
  }

  Serial.println();
  
  Serial.println("Set Digital Outputs");
  Serial.println("===================");
  for(int i=1; i<13; i++) {
    Serial.print("setY(");
    Serial.print(i);
    Serial.println(", HIGH) ");
    setY(i, HIGH);
  }

  Serial.println();
    
  Serial.println("Read Digital Outputs");
  Serial.println("====================");
  for(int i=1; i<13; i++) {
    Serial.print("readY(");
    Serial.print(i);
    Serial.print(") ");
      Serial.println(readY(i));
  }
Serial.println();
Serial.println("Wait.....");
delay(2000);

Serial.println();
  
  Serial.println("Set Digital Outputs");
  Serial.println("===================");
  for(int i=1; i<13; i++) {
    Serial.print("setY(");
    Serial.print(i);
    Serial.println(", LOW) ");
    setY(i, LOW);
  }
}

void loop() {  
  
}
