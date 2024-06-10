#include "WString.h"
#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include <Zumo32U4.h>
#include "WString.h"




class lijnSensor {
  public:
    lijnSensor();
    ~lijnSensor();
    int BepaalFout();
    void calibrate();
    int bepaalKleur();
  private:
    /** 
      @brief geeft een waarde 
    */
    Zumo32U4LineSensors lineSensors;
    unsigned int sensorWaardes[5];
    int laatsteError;
    int laatsteErrorKleur;
};

#endif