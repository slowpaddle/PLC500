#include "PLC500.h"

// Initialize Array for the PLC500 Digital Inputs ( X1 - X16 )
int inX[17]={-1, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 37, 36, 35, 34, 33, 32};

// Initialize Array for the PLC500 Digital Outputs ( Y1 - Y12 )
int outY[13]={-1, 42, 43, 44, 45, 46, 47, 48, 49, 38, 39, 40, 41};

// Initialize Array for the PLC500 Analog Inputs ( XA1 - XA16 )
int inXA[17]={-1, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A15, A14, A13, A12};

// Initialize Array for the PLC500 Analog Outputs ( YA1 - YA8 )
int outYA[9]={-1, 2, 3, 4, 5, 6, 7, 8, 9};

// =============================================================
// Set up the inputs and outputs	
// =============================================================
void PLC500Setup() {
	
	// Initialize digital inputs
	for(int i=1; i<17; i++) {
		pinMode(inX[i], INPUT);
	}
	
	// Initialize analog inputs
	for(int i=1; i<17; i++) {
		pinMode(inXA[i], INPUT);
	}
	
	// Initialize digital outputs and set to LOW
	for(int i=1; i<13; i++) {
		pinMode(outY[i], OUTPUT);
		digitalWrite(outY[i], LOW);
	}	  
}

// =============================================================
// Set the state of a digital output (12 total)
// =============================================================
bool setY(int x, bool y) {
	bool result;
	if(x < 13 && x > 0) {
		digitalWrite(outY[x], y);
		result = digitalRead(outY[x]);
	}
	else {
		result = 0;
	}
	return result;
}

// =============================================================
// Set the value of an analog output (8 total)
// =============================================================
int setYA(int x, int y) {
	int result;
	if(x < 9 && x > 0) {
		analogWrite(outYA[x], y);
		result = analogRead(outYA[x]);
	}
	else {
		result = -1;
	}
	return result;
}

// =============================================================
// Read the state of a digital input (16 total)
// =============================================================
bool readX(int x) {
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
int readXA(int x) {
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
bool readY(int x) {
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
int readYA(int x) {
	int result;
	if(x < 9 && x > 0) {
		result = analogRead(outYA[x]);
	}
	else {
		result = 0;
	}
	return result;
}
