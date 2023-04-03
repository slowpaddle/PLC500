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
