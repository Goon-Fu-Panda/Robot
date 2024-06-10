#include "WString.h"
#include "motorController.h"

motorController::motorController():Motors(),Encoders(),leftSpeed(0),rightSpeed(0),minSpeed(0),maxSpeed(300){
  Encoders.init();
}
motorController::~motorController() {

}
void motorController::zetSnelheid(int veranderingSnelheid,int kleur) {
  leftSpeed = maxSpeed + veranderingSnelheid;
  rightSpeed = maxSpeed - veranderingSnelheid;
  leftSpeed= constrain(leftSpeed,minSpeed, maxSpeed);
  rightSpeed =constrain(rightSpeed,minSpeed, maxSpeed);

  if (kleur == 2) {
    leftSpeed /= 2;
    rightSpeed /= 2; 
  }

  Motors.setSpeeds(leftSpeed,  rightSpeed);
  
}
void motorController::zetMinSnelheid(int invoer) {
  minSpeed = invoer;
}
void motorController::zetMaxSnelheid(int invoer) {
  maxSpeed = invoer;
}
void motorController::zetDirectSnelheid(int left,int right) {
  Motors.setSpeeds(left, right);
}
