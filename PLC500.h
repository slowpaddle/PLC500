#ifndef PLC500_h
#define PLC500_h

#include "Arduino.h"

class PLC500 {
  public:
  void begin();
  void setY(int x, bool y);
  void setYA(int x, int y);
  bool readX(int x);
  bool readY(int x);
  int readXA(int x);
  int readYA(int x);
  int inX[17];
  int outY[13];
  int inXA[17];
  int outYA[9]; 
};
//extern _GetCSV GetCSV;

#endif