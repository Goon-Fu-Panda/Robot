#ifndef BUTTON_H
#define BUTTON_H

#include <Zumo32U4.h>
/*roept de klas Sensor aan en de Buttons A,B,C*/
class Sensor {
private:
    Zumo32U4ButtonA buttonA;
    Zumo32U4ButtonB buttonB;
    Zumo32U4ButtonC buttonC;

public:
/*constructor voor Sensor*/
    Sensor();
/*deze functie leest de sensor uit*/
    int readSensor();
/*om de knoppen uit te kunnen lezen*/
    bool readButtons();
/*wacht totdat er een knop wordt ingetoets*/
    char waitForButtonInput();
};

#endif
