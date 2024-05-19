#include "Print.h"
#include "controller.h"
#include <Zumo32U4.h>

controller::controller():status(1),linesensor(),sensorWaardes{0,0,0},zigbeeInvoer(),lastError(0) {
  linesensor.initThreeSensors();

}

controller::controller(int startmodus):status(startmodus),linesensor(),sensorWaardes{0,0,0},zigbeeInvoer(),lastError(0) {
  linesensor.initThreeSensors();

}

void controller::volglijn() {
  status = 0;
}
void controller::handbestuur() {
  status = 1;
}
void controller::acties() {
  int16_t position = 0;
  int16_t error = 0;
  int16_t speedDifference = 0;
  int16_t leftSpeed = 0;
  int16_t rightSpeed = 0;
  switch (status) {
    case 0:
       position = linesensor.readLine(sensorWaardes);
       error = position - 2000;
       speedDifference = error / 4 + 6 * (error - lastError);

      lastError = error;
       leftSpeed = (int16_t)maxSpeed + speedDifference;
       rightSpeed = (int16_t)maxSpeed - speedDifference;

      leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
      rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

      motors.setSpeeds(leftSpeed, rightSpeed);
      break;
    ;
    case 1:
      if (Serial1.available() < 0) {
        return;
      }
      zigbeeInvoer = Serial1.readString();
      zigbeeInvoer.toUpperCase();
      if ()

      
      break;
    default:
      Serial1.print("controller: no status matches");
  }
}