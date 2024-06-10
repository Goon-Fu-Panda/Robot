#include "Arduino.h"
#include "lijnSensor.h"

lijnSensor::lijnSensor():lineSensors(),sensorWaardes(),laatsteError(0),laatsteErrorKleur(0) {
  lineSensors.initFiveSensors();
}
lijnSensor::~lijnSensor() {

}
int lijnSensor::BepaalFout() {
  int positie = lineSensors.readLine(sensorWaardes);
  // Serial1.print("SensorWaardes");

  // for (int i=0;i< 5;i++) {
  //     Serial1.print(sensorWaardes[i]);
  //     Serial1.print(" ");


  // }
  // Serial1.println("");

  // Our "error" is how far we are away from the center of the
  // line, which corresponds to position 2000.
  // Serial1.print("positie:");
  // Serial1.println(positie);
  int error = positie - 2000;
  // Get motor speed difference using proportional and derivative
  // PID terms (the integral term is generally not very useful
  // for line following).  Here we are using a proportional
  // constant of 1/4 and a derivative constant of 6, which should
  // work decently for many Zumo motor choices.  You probably
  // want to use trial and error to tune these constants for your
  // particular Zumo and line course.
  int16_t speedDifference = error / 4 + 6 * (error - laatsteError);
  // Serial.println(speedDifference);
  laatsteError = error;

  return speedDifference;
};
void lijnSensor::calibrate(){
  Zumo32U4Motors motors;
  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motors.setSpeeds(-200, 200);
    }
    else
    {
      motors.setSpeeds(200, -200);
    }

    lineSensors.calibrate();
  }
  motors.setSpeeds(0, 0);
}
int lijnSensor::bepaalKleur() {
  int zwarteGrensWaarde = 350;
  int groenGrensWaarde = 100;
  int samen =0;

  for (int i = 0;i<5;i++) {
      samen += sensorWaardes[i];

  }
  int error = samen;
  int kleurDifference = error / 4 + 6 * (error - laatsteErrorKleur);
  laatsteErrorKleur = error;
  Serial1.print("Kleur");
  Serial1.println(kleurDifference);
  kleurDifference = constrain(kleurDifference, 0, 1000);
  if (kleurDifference > groenGrensWaarde) return 2;
  if (kleurDifference > zwarteGrensWaarde) return 1;
  return -1;


 }