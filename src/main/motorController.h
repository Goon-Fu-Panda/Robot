#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Zumo32U4.h>

class motorController {
  public:
    /** 
    \brief dit is de constructor dit zal automatisch de nodige klassen aanmaken
    */
    motorController();
    ~motorController();
    /**
    \brief deze methode zal de snelheid langzaam omhoog en omlaag schallen.
    */
    void zetSnelheid(int,int);
    /**
    \brief deze methode wordt gebruikt in de calculatie als grenswaarde waar de motor niet onder mag.
    */
    void zetMinSnelheid(int);
    /**
    \brief deze methode wordt gebruikt in de calculatie als grenswaarde waar de motor niet over mag.
    */
    void zetMaxSnelheid(int);
    /**
    \brief deze methode gaat om de systemen heen aan laat het toe om direct de moteren te zetten dit kan handig zijn tijdens calibratie.
    */
    void zetDirectSnelheid(int,int);
  private:
    Zumo32U4Motors Motors;
    Zumo32U4Encoders Encoders;
    int leftSpeed,rightSpeed,minSpeed,maxSpeed;

};

#endif