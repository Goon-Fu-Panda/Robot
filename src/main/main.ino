#include "g_logger.h"

globale_logger logger;
void setup() {
  // put your setup code here, to run once:
  logger = globale_logger();
  logger.info("INFO");
  logger.warn("WARN");
  logger.error("ERROR");
  logger.fatal("CRASH");
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
}
