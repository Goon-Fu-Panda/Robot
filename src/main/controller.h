#include <stdint.h>
#include "WString.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Zumo32U4.h>

class controller {
  public:
    /**
    @brief standaard modus is afstand controleerbaar
    */
    controller();
    /** 
    @brief dit is de constructor.
    de int geeft aan of het in handbestuur moet starten of volglijn
    */
    controller(int startmodus);
    void handbestuur();
    void volglijn();
    /** 
      @brief dit is nodig om ervoor te zorgen dat er updates worden uitgevoerd
    */
    void acties();
  private:
    int status;
    unsigned int sensorWaardes[3];
    int16_t lastError;
    String zigbeeInvoer;
    Zumo32U4LineSensors linesensor;
    Zumo32U4Motors motors;
    const uint16_t maxSpeed = 400;

};


#endif