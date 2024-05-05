#include "Arduino.h"
#include "lijnSensor.h"
#include <Zumo32U4.h>

/*
  de standaard constructor voor deze classen nemen aan dat er 3 sensoren zijn.
  als dit niet zo is zall er invoer nodig zijn om de classe correct op te stellen
*/
lijnSensor::lijnSensor(): Zumo32U4LineSensors(), sensorAantal(3), sensorError(0) {
  Zumo32U4LineSensors::initThreeSensors(SENSOR_LEDON);
};

/*
  dit is de alternative constuctor.
  deze zal wanneer er correct invoer wordt geven volgens de spec van de qtrSensor worden opgestelt.
  https://pololu.github.io/qtr-sensors-arduino/_q_t_r_sensors_8h.html
*/
lijnSensor::lijnSensor(uint8_t *pins, uint8_t numSensors, uint16_t timeout = 2000, uint8_t emitterPin = SENSOR_LEDON): Zumo32U4LineSensors(), sensorAantal(numSensors), sensorError(0) {
  Zumo32U4LineSensors::init(pins, numSensors, timeout,emitterPin);
};

lijnSensor::~lijnSensor() {

};

/* 
  deze methode geeft de afwijking van de middelste sensor 
  het zal een negatief getal terug geven wanneer het links zit.
  en positief als het er rechts van zit.
*/
int lijnSensor::afwijkingLijn(unsigned int *sensorInvoer) {
  int Lijnwaarde = Zumo32U4LineSensors::readLine(sensorInvoer);
  /* 
    het is hier 2000 omdat dat de waarde is voor 3 sensoren 
    zie : https://pololu.github.io/qtr-sensors-arduino/class_q_t_r_sensors.html#a8f2a5239ae547928284c5f81cd7ec89c
    voor meer info.
   */
  int middelSensor = 2000;
  return Lijnwaarde - middelSensor;
};


bool lijnSensor::aanwezigheidLijn(unsigned int *sensorInvoer) {
  int Lijnwaarde = Zumo32U4LineSensors::readLine(sensorInvoer);
  /* 
  we lopen door alle sensoren en kijken of het 0 is.
  En als dat zo is geven we 0 terug (dat deze niet aanwezig is).
  */
  for (int i=0 ;i<sensorAantal;i++) {
    if (sensorInvoer[i] == 0){
      return 0;
    }
  }
}