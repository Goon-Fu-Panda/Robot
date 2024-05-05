#include <Wire.h>
#include <Zumo32U4.h>
#include "lijnSensor.h"
#include "xbee.h"

lijnSensor lijn;
unsigned int lijnWaardes[3]= {20,20,20};
xbee xbees;
void setup() {
}

void loop() {
  
  lijn.read(lijnWaardes);

}
