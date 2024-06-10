#include "Arduino.h"
#include "lijnSensor.h"

lijnSensor::lijnSensor():sensorWaardes(),laatsteError(0),laatsteErrorKleur(0) {
  initFiveSensors();
}
lijnSensor::~lijnSensor() {

}
int lijnSensor::BepaalFout() {

  int positie = readLine(sensorWaardes);

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
  int16_t speedDifference = error / 6 + 12 * (error - laatsteError);
  // Serial.println(speedDifference);
  laatsteError = error;

  return speedDifference;
};
void lijnSensor::calibrate_zelf(){
  Zumo32U4Motors motors;
  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 0 && i <= 60)
    {
      motors.setSpeeds(-200, 200);
    }
    else
    {
      motors.setSpeeds(200, -200);
    }

    calibrate();
  }
  motors.setSpeeds(0, 0);
  return;
}
  int lijnSensor::readLine(unsigned int *sensor_values,unsigned char readMode , unsigned char white_line ){
     unsigned char i, on_line = 0;
     unsigned long avg; // this is for the weighted total, which is long
                        // before division
     unsigned int sum; // this is for the denominator which is <= 64000
     readCalibrated(sensor_values, readMode);
     
     avg = 0;
     sum = 0;
  
     for(i=0;i<_numSensors;i++) {
     

         int value = sensor_values[i];
                //     Serial1.print("VALUES:");
                // Serial1.println(value);
         if(white_line)
             value = 1000-value;
  


         // keep track of whether we see the line at all
         if(value > 100) {
             on_line = 1;
         }
  
         // only average in values that are above a noise threshold
         if(value > 100) {
             avg += (long)(value) * (i * 1000);
             sum += value;
         }
     }
  
     if(!on_line)
     {
         // If it last read to the left of center, return 0.
         if(_lastValue < (_numSensors-1)*1000/2)
             return 0;
  
         // If it last read to the right of center, return the max.
         else
             return (_numSensors-1)*1000;
  
     }
  
     _lastValue = avg/sum;
  
     return _lastValue;
 }
int lijnSensor::bepaalKleur() {
  int zwarteGrensWaarde = 400;
  int groenGrensWaarde = -1;
  int samen =0;

  for (int i = 0;i<5;i++) {
      samen += sensorWaardes[i];

  }
  
  int error = samen;
  int kleurDifference = error / 1 + 12 * (error - laatsteErrorKleur);
  laatsteErrorKleur = error;
  // Serial1.print("Kleur");
  // Serial1.println(kleurDifference);
  if (kleurDifference > zwarteGrensWaarde) return 1;
  if (kleurDifference > groenGrensWaarde) return 2;
  return 0;
  


 }
