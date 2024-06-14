/**
 * @file Afstand.h
 * @brief Definieert de AfstandSensor klasse.
 */

/**
 * @class AfstandSensor
 * @brief Klasse voor het beheren van afstandssensoren.
 */
 #include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4ProximitySensors.h>

class AfstandSensor {
public:
  /**
     * @brief Constructor voor de AfstandSensor klasse.
     */
  AfstandSensor();

  /**
     * @brief Meet de afstand aan de linkerkant en geeft de resultaten via seriële monitor.
     * @return De gemeten afstand.
     */
  uint8_t AfstandSerialLinks() const;

  /**
     * @brief Meet de afstand aan de voorkant en geeft de resultaten via seriële monitor.
     * @return De gemeten afstand.
     */
  uint8_t AfstandSerialVoorL() const;
  uint8_t AfstandSerialVoorR() const;

  /**
     * @brief Meet de afstand aan de rechterkant en geeft de resultaten via seriële monitor.
     * @return De gemeten afstand.
     */
  uint8_t AfstandSerialRechts() const;

  /**
     * @brief Leest de sensoren uit.
     */
  void AfstandLezen();

  /**
     * @brief Activeert de sensoren.
     */
  void SensorActiveer();
private:
  // Maak een object van de klasse Zumo32U4ProximitySensors
  Zumo32U4ProximitySensors proxSensors;
};
