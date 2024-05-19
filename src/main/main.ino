#include <Wire.h>
#include <Zumo32U4.h>
#include "controller.h"

controller test;
void setup() {
  test.handbestuur();
}

void loop() {
  test.acties();
}

