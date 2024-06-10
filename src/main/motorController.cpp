#include "WString.h"
#include "motorController.h"

motorController::motorController():Motors(),Encoders(),leftSpeed(0),rightSpeed(0),minSpeed(0),maxSpeed(400){
  Encoders.init();
}
motorController::~motorController() {

}
void motorController::zetSnelheid(int veranderingSnelheid,int kleur) {
  // Serial1.println("snelheid:"+veranderingSnelheid);
  // Serial.println("snelheid:"+veranderingSnelheid);
  leftSpeed = maxSpeed + veranderingSnelheid;
  rightSpeed = maxSpeed - veranderingSnelheid;
  leftSpeed= constrain(leftSpeed,minSpeed, maxSpeed);
  rightSpeed =constrain(rightSpeed,minSpeed, maxSpeed);
  if (kleur == -1) {
    Motors.setSpeeds(0, 0);
  }
  // if (kleur == "GROEN") {
  //   leftSpeed /= 2;
  //   rightSpeed /= 2; 
  // }

  Motors.setSpeeds(leftSpeed,  rightSpeed);
  
}
void motorController::zetMinSnelheid(int invoer) {
  minSpeed = invoer;
}
void motorController::zetMaxSnelheid(int invoer) {
  maxSpeed = invoer;
}