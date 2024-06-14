#include "Afstand.h"

// Maak een object van de klasse AfstandSensor
AfstandSensor sensor;

/**
 * @brief Setup functie voor het initialiseren van de sensor.
 */
void setup() {
    sensor.SensorActiveer();
}

/**
 * @brief Print een regel met alle sensorwaarden naar de seriële monitor.
 */
void printSensorReadings() {
    static char buffer[80];
    sprintf(buffer, "%d %d %d %d \n",
            sensor.AfstandSerialRechts(),
            sensor.AfstandSerialLinks(),
            sensor.AfstandSerialVoorL(),
            sensor.AfstandSerialVoorR()
    );
    Serial.print(buffer);
}

/**
 * @brief Continu uitvoeren van sensormetingen en resultaten afdrukken.
 */
void loop() {
    static uint16_t lastSampleTime = 0;

  if ((uint16_t)(millis() - lastSampleTime) >= 100)
  {
    lastSampleTime = millis();
    // Stuur Infra-Rood pulsen uit en lees de Afstandsensoren.
    sensor.AfstandLezen();
    // Stuur de resultaten naar de seriële monitor.
    printSensorReadings();
  }
}
