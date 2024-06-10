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
  bool tijdelijkeWaarde = false;
  while (true) {
    if  (0 < Serial1.available()) {
      
      String input = Serial1.readString();
      
      Serial1.println(input);
      if (input == "c") {
        lijnsensor.calibrate();
        buzzer.play("C6 V1");
        tijdelijkeWaarde = true;

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
  delay(100);
  int fout = lijnsensor.BepaalFout();
  int kleur = lijnsensor.bepaalKleur();
  Serial1.println(fout);
  motorcontroller.zetSnelheid(fout,kleur);
}

