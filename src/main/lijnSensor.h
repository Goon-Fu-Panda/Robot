#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H
#include <Zumo32U4.h>

class lijnSensor: public Zumo32U4LineSensors  {
  public:
    lijnSensor();
    lijnSensor(unsigned char *, unsigned char , unsigned int, unsigned char);
    ~lijnSensor();
    int afwijkingLijn(unsigned int *);
    bool aanwezigheidLijn(unsigned int *);

  private:
    unsigned int sensorAantal;
    int sensorError;

};


#endif