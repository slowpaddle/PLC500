//====================================================================
// PLC500.h - Description and Usage
// Dave Gillen - davebuildsthings.ca
// Written February 16, 2022 / Updated April 2, 2023
// This library and sample code is open source and free to use/modify.
//====================================================================

#ifndef PLC500_h
#define PLC500_h

#include "Arduino.h"

#define ON HIGH
#define OFF LOW

class PLC500 {
  public:
    void begin();
    void setY(int x, bool y);
    void setYA(int x, int y);
    bool readX(int x);
    bool readY(int x);
    int readXA(int x);
    int readYA(int x);
  private:
    int inX[17];
    int outY[13];
    int inXA[17];
    int outYA[9]; 
};

#endif
