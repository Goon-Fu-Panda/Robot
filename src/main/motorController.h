#include "WString.h"
#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Zumo32U4.h>

class motorController {
  public:
    /** 
      
    */
    motorController();
    ~motorController();
    /**
    @brief deze methode zal de snelheid langzaam omhoog en omlaag schallen.
    */
    void zetSnelheid(int,int);
    void zetMinSnelheid(int);
    void zetMaxSnelheid(int);
    void zetDirectSnelheid(int,int);
  private:
    Zumo32U4Motors Motors;
    Zumo32U4Encoders Encoders;
    int leftSpeed,rightSpeed,minSpeed,maxSpeed;

};

#endif