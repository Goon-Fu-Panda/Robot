#include "HardwareSerial.h"
#ifndef XBEE_H
#define XBEE_H

class xbee {
  public:
    xbee();
    xbee(int);
    ~xbee();
    void printLijst(int *array,unsigned int length);
    void printHex(int);
    void printBin(int);
  private:

};


#endif