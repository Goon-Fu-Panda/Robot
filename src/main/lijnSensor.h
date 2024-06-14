#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include <Zumo32U4.h>


class lijnSensor : public Zumo32U4LineSensors{
  public:
    /**
    \brief dit is de constructor deze overervd van Zumo32U4LineSensor dus alles methodes van die klass kunnen ook op deze.
    */
    lijnSensor();
    ~lijnSensor();
    /**
    \brief dit bepaald hoe erg de motor moet gaan draaien om terug op de lijn te komen.
    */
    int BepaalFout();
    /**
    \brief deze methode zal direct de motoren aan sturen deze zal heen en terug draaien om data te krijgen en de sensoren te caliberen.
    \warning stuurt motoren direct aan!!
    */
    void calibrateZelf();
    /**
    \brief Deze methode gebruikt de waardes van de sensoren om te bepalen welke kleur we momenteel op zijn.
    \return de waarde die terug komt is 0 wanneer het systeem het niet weet of 2 voor groen of 1 voor zwart
    */
    int bepaalKleur();
    /**
    \brief 
    */
    int readLine(unsigned int *sensor_values,unsigned char readMode = 1, unsigned char white_line=0);
    private:
    // Zumo32U4LineSensors lineSensors;
    unsigned int sensorWaardes[5];
    int laatsteError;
    int laatsteErrorKleur;
};

#endif