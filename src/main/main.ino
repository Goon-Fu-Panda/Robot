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
      if (manual == true ) {
        while ( !Serial.available()) {}

        
        char input = Serial.read();
        toLowerCase(input);
        switch (input) {
          case 'w':
              motorcontroller.zetDirectSnelheid(200,200);
                        Serial1.println("w");

              input = 0;
            break;
            ;
          case 'a':  
              motorcontroller.zetDirectSnelheid(-200,200);
                                    Serial1.println("a");

              input = 0;

            break;
            ;
          case 's':   
              motorcontroller.zetDirectSnelheid(-200,-200);
                                    Serial1.println("s");

              input = 0;

            break;
            ;
          case 'd':
            motorcontroller.zetDirectSnelheid(200,-200);
              input = 0;
                                    Serial1.println("d");


            break;
            ;
            case -1:Serial1.println("iets niet goed");
          default:
            motorcontroller.zetDirectSnelheid(200, 200);
                        input = 0;

            Serial.println(input);
            break;
          ;
          }
        

      }else {
        int fout = lijnsensor.BepaalFout();
        int kleur = lijnsensor.bepaalKleur();

        // Serial1.println(kleur);
        motorcontroller.zetSnelheid(fout,kleur);
      }

}

