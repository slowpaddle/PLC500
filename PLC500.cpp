//====================================================================
// PLC500.h - Description and Usage
// Dave Gillen - davebuildsthings.ca
// Written February 16, 2022 / Updated April 2, 2023
// This library and sample code is open source and free to use/modify.
//====================================================================

#include "PLC500.h"

// =============================================================
// Set up the inputs and outputs  
// =============================================================
void PLC500::begin() {  
  // Initialize Array for the PLC500 Digital Inputs ( X1 - X16 )
  int inXX[17]={-1, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 37, 36, 35, 34, 33, 32}; //16
  // Initialize digital inputs
  for(int i=0; i<17; i++) {
    inX[i] = inXX[i];
    if(inX[i] > 0) {
      pinMode(inX[i], INPUT);
    }
  }
  
  // Initialize Array for the PLC500 Digital Outputs ( Y1 - Y12 )
  int outYY[13]={-1, 42, 43, 44, 45, 46, 47, 48, 49, 38, 39, 40, 41}; //12
  for(int i=0; i<13; i++) {
    outY[i] = outYY[i];
    if(outY[i] > 0) {
      pinMode(outY[i], OUTPUT);
      digitalWrite(outY[i], LOW);
    }
  }
  
  // Initialize Array for the PLC500 Analog Inputs ( XA1 - XA16 )
  int inXAXA[17]={-1, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A15, A14, A13, A12}; //16
  for(int i=0; i<17; i++) {
    inXA[i] = inXAXA[i];
  }
  
  // Initialize Array for the PLC500 Analog Outputs ( YA1 - YA8 )
  int outYAYA[9]={-1, 2, 3, 4, 5, 6, 7, 8, 9}; //8
  for(int i=0; i<9; i++) {
    outYA[i] = outYAYA[i];
  }
}

// =============================================================
// Set the state of a digital output (12 total)
// =============================================================
void PLC500::setY(int x, bool y) {
  bool result;
  if(x < 13 && x > 0) {
    digitalWrite(outY[x], y);
    result = digitalRead(outY[x]);
  }
}

// =============================================================
// Set the value of an analog output (8 total)
// =============================================================
void PLC500::setYA(int x, int y) {
  int result;
  if(x < 9 && x > 0) {
    analogWrite(outYA[x], y);
    result = analogRead(outYA[x]);
  }
}

// =============================================================
// Read the state of a digital input (16 total)
// =============================================================
bool PLC500::readX(int x) {
  bool result;
  if(x < 17 && x > 0) {
    result = !digitalRead(inX[x]); // Inverts the input state.
  }
  else {
    result = 0;
  }
  return result;
}

// =============================================================
// Read the value of an analog input (16 total)
// =============================================================
int PLC500::readXA(int x) {
  int result;
  if(x < 17 && x > 0) {
    result = analogRead(inXA[x]);
  }
  else {
    result = 0;
  }
  return result;
}

// =============================================================
// Read the state of a digital output (12 total)
// =============================================================
bool PLC500::readY(int x) {
  bool result;
  if(x < 13 && x > 0) {
    //digitalRead(outY[x], y);
    result = digitalRead(outY[x]);
  }
  else {
    result = 0;
  }
  return result;
}

// =============================================================
// Read the value of an analog output (8 total)
// =============================================================
int PLC500::readYA(int x) {
  int result;
  if(x < 9 && x > 0) {
    result = analogRead(outYA[x]);
  }
  else {
    result = 0;
  }
  return result;
}
