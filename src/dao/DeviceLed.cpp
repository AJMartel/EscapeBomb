#include "DeviceLed.h"

/**
 * Default constructor
 *   the DeviceLed constructor take the led 13, embedded on arduino boards
 *
 */
DeviceLed::DeviceLed() {
  this->pin=DEFAULT_LED;
  pinMode(this->pin, OUTPUT);
  digitalWrite(this->pin, HIGH);
}

/**
 * Constructor
 *   pin : the physical pin used for the led
 *
 */
DeviceLed::DeviceLed(uint8_t pin) {
  this->pin=pin;
  pinMode(this->pin, OUTPUT);
  digitalWrite(this->pin, HIGH);
}

DeviceLed::~DeviceLed() {
}

/**
 * This methodes turns the led on i.e. set the pin to HIGH
 */
void DeviceLed::turnOn() {
	digitalWrite(pin, HIGH);
}

/**
 * This methodes turns the led off i.e. set the pin to LOW
 */
void DeviceLed::turnOff() {
	digitalWrite(pin, LOW);
}
