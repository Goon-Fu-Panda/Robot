#include "xbee.h"
#include "HardwareSerial.h"

xbee::xbee() {
  Serial1.begin(9600);

}
xbee::~xbee() {

}