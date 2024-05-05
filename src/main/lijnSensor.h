#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H
#include <Zumo32U4.h>

class lijnSensor: public Zumo32U4LineSensors  {
  public:
    /**
      de standaard constructor voor deze classen nemen aan dat er 3 sensoren zijn.
      als dit niet zo is zall er invoer nodig zijn om de classe correct op te stellen
    */
    lijnSensor();
    /**
      dit is de alternative constuctor.
      deze zal wanneer er correct invoer wordt geven volgens de spec van de qtrSensor worden opgestelt.
      https://pololu.github.io/qtr-sensors-arduino/_q_t_r_sensors_8h.html
    */
    lijnSensor(unsigned char *, unsigned char , unsigned int, unsigned char);
    ~lijnSensor();
    /** 
      deze methode geeft de afwijking van de middelste sensor 
      het zal een negatief getal terug geven wanneer het links zit.
      en positief als het er rechts van zit.
    */
    int afwijkingLijn(unsigned int *);
    /** 
      we lopen door alle sensoren en kijken of het 0 is.
      En als dat zo is geven we 0 terug (dat deze niet aanwezig is).
    */
    bool aanwezigheidLijn(unsigned int *);

  private:
    unsigned int sensorAantal;
    int sensorError;

};


#endif