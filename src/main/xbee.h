#include "HardwareSerial.h"
#ifndef XBEE_H
#define XBEE_H

class xbee {
  public:
    /**
      dit start de seriale verbinding en zet het naar de standaard baudrate van 9600
      hier mee word alle nodige systemen opgesteld
    */
    xbee();
    /**
      bij deze constuctuur kan je nodige connectie snelheden zetten zo nodig is.
      dit kan bijvoorbeeld handig zijn als je meer characters wil versturen.
      of als je minder vertragging wil hebben door de stuur tijd.
    */
    xbee(int);
    /** 
      om de Seriale verbinding correct aftesluiten.
      en geen problematische instantie te krijgen.
      wordt hier Serial . end op geroepen om alles correect af te sluiten.
    */
    ~xbee();
    /** 
      deze methode gebruikt de ingevoerde lengte om dat aantal keer door de array te gaan.
      !!! LET OP !!! als je een te grote lengthe geeft voor de array krijg je ongedefineerd gedrag.
      dit komt door dat de code door leest en print wat kan leiden tot een crash.
    */
    void printLijst(int *array,unsigned int length);
    /**
      Deze methode is zeer simpel het pakt de geven invoer en drukt het uit via de Xbee.
    */
    void printHex(int);
    /**
      Deze methode gebruikt de invoer en geeft het weer via de serial van de Xbee
    */
    void printBin(int);
  private:

};


#endif