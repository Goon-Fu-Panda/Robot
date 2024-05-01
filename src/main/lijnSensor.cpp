#include "lijnSensor.h"
#include <Zumo32U4.h>


lijnSensor::lijnSensor() {
  Zumo32U4LineSensors::initFiveSensors();
};
lijnSensor::~lijnSensor() {
  
};
