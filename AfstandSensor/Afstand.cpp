#include "Afstand.h"

// Constructor voor de klasse AfstandSensor
AfstandSensor::AfstandSensor(){
  proxSensors.initThreeSensors();
}

// Methode om de afstand aan de linkerkant te meten en uit te voeren via seriële monitor
uint8_t AfstandSensor::AfstandSerialLinks()const {
  return proxSensors.countsLeftWithLeftLeds(); 
}

// Methode om de afstand aan de voorkant te meten en uit te voeren via seriële monitor
uint8_t AfstandSensor::AfstandSerialVoorL()const {
  return proxSensors.countsFrontWithLeftLeds();
}

uint8_t AfstandSensor::AfstandSerialVoorR()const {
  return proxSensors.countsFrontWithRightLeds();
}

// Methode om de afstand aan de rechterkant te meten en uit te voeren via seriële monitor
uint8_t AfstandSensor::AfstandSerialRechts()const {
  proxSensors.countsRightWithRightLeds();
}

// Methode om de sensoren uit te lezen
void AfstandSensor::AfstandLezen(){
  proxSensors.read();
}

// Methode om de sensoren te activeren
void AfstandSensor::SensorActiveer(){
  proxSensors.initThreeSensors();
}
