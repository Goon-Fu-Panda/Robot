#include "Arduino.h"
#include "lijnSensor.h"

lijnSensor::lijnSensor():sensorWaardes(),laatsteError(0),laatsteErrorKleur(0) {
  initFiveSensors();
}
lijnSensor::~lijnSensor() {

}
int lijnSensor::BepaalFout() {

  int positie = readLine(sensorWaardes);
  // We willen hier een verschil hebben tussen waar we zijn.
  // En waar we willen zijn dit doen we omdat zo de motoren sturen.
  // we doen -2000 hier omdat de sensoren 1 = 1000 dus dan als we nummer 3 willen doen we -2000
  int error = positie - 2000;

  /*Dit is een controller om de waardes te geen stabiliseren
   *De waardes die nu er aan hangen zijn na testen uit geprobeerd en deze leken op timaal.
   */
  int16_t speedDifference = error / 3 +  8 * ( error - laatsteError );
  laatsteError = error;

  return speedDifference;
};
void lijnSensor::calibrateZelf(){
  Zumo32U4Motors motors;
  // wacht voor een seconde om alles klaar te laten worden.
  delay(1000);

  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 0 && i <= 60){
      // draai heen 
      motors.setSpeeds(-200, 200);
    }
    else{
      // draai terug 
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
         if(value > 50) {
             on_line = 1;
         }
         // only average in values that are above a noise threshold
         if(value > 50) {
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
 /* De grens waardes hier onder zijn wij opgekomen door te testen.
  * En te kijken hoe het dan werkt en welke kant beter is.
  */
  int zwarteGrensWaarde = 400;
  int groenGrensWaarde = -1;
  int samen = 0;
  for (int i = 0;i<5;i++) {
      samen += sensorWaardes[i];
  }
  int error = samen;
  /* Wij nemen hier een gemiddelde van de vorige en nu om extreme osilaties.
   * Te verkomen in de robot.
  */
  int kleurDifference = error / 1 + 12 * (error - laatsteErrorKleur);
  laatsteErrorKleur = error;
  /* Hier worden de kleuren gecontroleerd en wordt 1 zwart of 2 groen en 0 is onbekend terug gegeven,
   * 
  */
  if (kleurDifference > zwarteGrensWaarde) return 1;
  if (kleurDifference > groenGrensWaarde) return 2;
  return 0;
  


 }
