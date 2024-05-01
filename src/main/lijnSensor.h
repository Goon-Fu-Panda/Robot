#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H
#include <Zumo32U4.h>

class lijnSensor: public Zumo32U4LineSensors  {
  public:
    lijnSensor();
    ~lijnSensor();
  private:
    unsigned int *SensorWaardes;
    unsigned char SensorAantal;

};


#endif