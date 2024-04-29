#include "g_logger.h"
#include <Zumo32U4.h>

globale_logger::globale_logger() {
  Serial.begin(9600);
  info("Logger is geinistaliseerd: BUADRATE is 9600");
};
globale_logger::globale_logger(unsigned long UART_Speed) {
  Serial.begin(UART_Speed);
  info("Logger is geinistaliseerd: "+UART_Speed);
};
bool globale_logger::logger(String level,String invoer) {
    Serial.print(level);
    Serial.print(invoer);
    Serial.println();
};

bool globale_logger::info(String invoer) {
    logger("[INFO]:",invoer);
};
bool globale_logger::warn(String invoer) {
    logger("[WARN]:",invoer);
};
bool globale_logger::error(String invoer) {
    logger("[ERR]:",invoer);
};
bool globale_logger::fatal(String invoer) {
    logger("[CRASH]:",invoer);
    Zumo32U4Buzzer().play("V10 L8 CECECE ");

};
