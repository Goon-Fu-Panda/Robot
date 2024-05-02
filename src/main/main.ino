#include <Wire.h>
#include <Zumo32U4.h>
#include "lijnSensor.h"

lijnSensor lijn;
unsigned int lijnWaardes[3]= {20,20,20};
Zumo32U4ButtonA buttonA;
void setup() {
  Serial.begin(9600);

}

void loop() {

  lijn.lees(lijnWaardes);
  if  (buttonA.getSingleDebouncedRelease()) {
    for (int i = 0;i<5;i++) {
      Serial.println(lijnWaardes[i]);

    }
  }
  

}
