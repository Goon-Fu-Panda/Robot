#include "WString.h"
#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include <Zumo32U4.h>
#include "WString.h"




class lijnSensor :public Zumo32U4LineSensors{
  public:
    lijnSensor();
    ~lijnSensor();
    int BepaalFout();
    void calibrate_zelf();
    int bepaalKleur();
    int readLine(unsigned int *sensor_values,unsigned char readMode = 1, unsigned char white_line=0);
    private:
    // Zumo32U4LineSensors lineSensors;
    unsigned int sensorWaardes[5];
    int laatsteError;
    int laatsteErrorKleur;
};

#endif