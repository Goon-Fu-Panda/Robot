#include "Arduino.h"
#include <Wire.h>
#include <Zumo32U4.h>


/*maakt de klasse Sensor aan met daarin alle Buttons*/
  class Sensor {
    Zumo32U4ButtonA buttonA;
    Zumo32U4ButtonB buttonB;
    Zumo32U4ButtonC buttonC;

public:
    Sensor() {
    }

    int readSensor() {
        return analogRead(A0);
    }

    bool readButtons() {
        bool buttonAPressed = buttonA.getSingleDebouncedPress();
        bool buttonBPressed = buttonB.getSingleDebouncedPress();
        bool buttonCPressed = buttonC.getSingleDebouncedPress();

        /*laat de status zien*/
        return (buttonAPressed || buttonBPressed || buttonCPressed);
    }

    char waitForButtonInput() {
        while (true) {
            /*wacht tot de knop is ingedrukt*/
            if (buttonA.getSingleDebouncedPress()) {
                return 'A';
            } else if (buttonB.getSingleDebouncedPress()) {
                return 'B';
            } else if (buttonC.getSingleDebouncedPress()) {
                return 'C';
            }
        }
    }
};

Sensor sensor;

void setup() {
    Serial.begin(9600);
}

void loop() {
    /* laat de sensorgegevens zien*/
    int sensorData = sensor.readSensor();
    Serial.print("Sensor data: ");
    Serial.println(sensorData);

    /*laat de buttonstate zien*/
    bool buttonsState = sensor.readButtons();
    Serial.print("Buttons state: ");
    Serial.println(buttonsState);

    /*wacht totdat de button is ingedrukt*/
    Serial.println("Waiting for button input...");
    char buttonPressed = sensor.waitForButtonInput();
    Serial.print("Button pressed: ");
    Serial.println(buttonPressed);

    /* wacht totdat de loop opnieuw wordt uitegevoerd*/
    delay(1000);
}