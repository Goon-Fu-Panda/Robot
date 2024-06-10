#include <Wire.h>
#include <Zumo32U4.h>
#include "lijnSensor.h"
#include "motorController.h"


motorController motorcontroller;

lijnSensor lijnsensor;
Zumo32U4Buzzer buzzer;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  while (true) {
    if  (0 < Serial1.available()) {
      
      String input = Serial1.readString();
      
      Serial1.println(input);
      if (input == "c") {
        lijnsensor.calibrate_zelf();
        buzzer.play("C6 V1");

      }
      if (input == "b") {
          break;
      } 
    }
  }
}

void loop() {
      //   if (Serial1.read() == 's' || 'S') {
      //     Serial1.println("bomb");
      //     while (true) {
      //       if (Serial1.read() == 'p' || 'P') {
      //         break;
      //       }
      //       motorcontroller.zetSnelheid(0);
      //     }
      // }
  int fout = lijnsensor.BepaalFout();
  int kleur = lijnsensor.bepaalKleur();

  // Serial1.println(kleur);
  motorcontroller.zetSnelheid(fout,kleur);
}

