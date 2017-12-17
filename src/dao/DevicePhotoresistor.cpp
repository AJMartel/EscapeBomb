#include "DevicePhotoresistor.h"

/**
 * Constructor
 *   pin : the physical pin used for the button
 *
 */
DevicePhotoresistor::DevicePhotoresistor(uint8_t pin) {
	this->pin = pin;
	pinMode(pin, INPUT_PULLUP);
}

DevicePhotoresistor::~DevicePhotoresistor() {
}

/**
 * isPressed returns true if button is pressed
 *
 */

uint8_t DevicePhotoresistor::readLight() {
	return analogRead(pin);
}
