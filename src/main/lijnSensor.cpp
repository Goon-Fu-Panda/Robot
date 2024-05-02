#include "lijnSensor.h"
#include <Zumo32U4.h>


lijnSensor::lijnSensor(): Zumo32U4LineSensors() {
  Zumo32U4LineSensors::initThreeSensors(SENSOR_LEDON);
  int i[3] = {2,2,2};
  Zumo32U4LineSensors::read(i);
  for (int j =0 ;;j++)
  Serial.println(i);
};
lijnSensor::~lijnSensor() {
  
};
void lijnSensor::lees(unsigned int *sensorInvoer) {
  Zumo32U4LineSensors::readLine(sensorInvoer);

};