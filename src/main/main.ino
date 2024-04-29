#include "g_logger.h"
#include <Wire.h>
#include <Zumo32U4.h>

globale_logger logger;
void setup() {
  // put your setup code here, to run once:
  logger = globale_logger();
  delay(2000);
  logger.info("INFO");
  logger.warn("WARN");
  logger.error("ERROR");
  logger.fatal("CRASH");
  // Zumo32U4Motors().setSpeeds(60, 60);

}

void loop() {
  if (Zumo32U4ButtonA().isPressed() == true) {
    logger.fatal("aasasadasas");
  }
  // put your main code here, to run repeatedly:
}
