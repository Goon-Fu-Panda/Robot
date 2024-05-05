#include "Print.h"
#include "HardwareSerial.h"
#include "xbee.h"

/*
  dit start de seriale verbinding en zet het naar de standaard baudrate van 9600
  hier mee word alle nodige systemen opgesteld
*/
xbee::xbee() {
  Serial1.begin(9600);

}
/* 
  bij deze constuctuur kan je nodige connectie snelheden zetten zo nodig is.
  dit kan bijvoorbeeld handig zijn als je meer characters wil versturen.
  of als je minder vertragging wil hebben door de stuur tijd.
*/
xbee::xbee(int BUAD_RATE) {
  Serial1.begin(BUAD_RATE);
}

/* 
  om de Seriale verbinding correct aftesluiten.
  en geen problematische instantie te krijgen.
  wordt hier Serial . end op geroepen om alles correect af te sluiten.
*/
xbee::~xbee() {
  Serial1.end();
}

/* 
  deze methode gebruikt de ingevoerde lengte om dat aantal keer door de array te gaan.
  !!! LET OP !!! als je een te grote lengthe geeft voor de array krijg je ongedefineerd gedrag.
  dit komt door dat de code door leest en print wat kan leiden tot een crash.
*/
void xbee::printLijst(int *array,unsigned int length) {
  for (int i = 0;i < length;i++) {
    Serial1.write(array[i]);
  }
}

/*
  Deze methode gebruikt de invoer en geeft het weer via de serial van de Xbee
*/
void xbee::printBin(int input) {
  Serial1.print(input,BIN);
}

/*
  Deze methode is zeer simpel het pakt de geven invoer en drukt het uit via de Xbee.
*/
void xbee::printHex(int input) {
  Serial1.print(input,HEX);
}
