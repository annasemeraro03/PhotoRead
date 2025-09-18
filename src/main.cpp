/*
  Project: Reading phototransistor value
  Author: Anna Semeraro
  Description: Arduino code for ESP32 to read the value of a phototransistor when a red LED is turned on/off
*/

// libraries
#include <Arduino.h>

// configuration of the pins
#define PHOTO_SENSOR_PIN 34   // pin to which the phototransistor is connected
#define RED_LED 14            // pin to which the red LED is connected

bool ledState = false;        // state of the LED (on/off)

/**
 * @brief Function to setup the ESP32
 * @param None
 * @return None
 */
void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
}

/**
 * @brief Function to loop the ESP32
 * @param None
 * @return None
 */
void loop() { 
  digitalWrite(RED_LED, ledState ? HIGH : LOW);     

  // Print the results
  Serial.print(String(analogRead(PHOTO_SENSOR_PIN)) + "\n");

  delay(1500);                  // Wait for 1.5 second before the next iteration
}