#include <Wire.h>
#include <Zumo32U4.h>
#include "lijnSensor.h"
#include "motorController.h"


motorController motorcontroller;

lijnSensor lijnsensor;
Zumo32U4Buzzer buzzer;
bool manual = true;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  while (true) {
    if  (0 < Serial1.available()) {
      
      String input = Serial1.readStringUntil('\0');
      
      Serial1.println(input);
      if (input == "c") {
        manual = false;
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
      if (manual == true ) {
        if (Serial1.available()) {

        
        int input = Serial.read()
        switch (input) {
        case 119:
            motorcontroller.zetDirectSnelheid(200,200);
          break;
          ;
        case 97:  
            motorcontroller.zetDirectSnelheid(-200,200);

          break;
          ;
        case 115:   
            motorcontroller.zetDirectSnelheid(-200,-200);

          break;
          ;
        case 100:
          motorcontroller.zetDirectSnelheid(200,-200);

          break;
          ;
        default:
          Serial.println();
        ;
        }
        }

      }
  int fout = lijnsensor.BepaalFout();
  int kleur = lijnsensor.bepaalKleur();

  // Serial1.println(kleur);
  motorcontroller.zetSnelheid(fout,kleur);
}

