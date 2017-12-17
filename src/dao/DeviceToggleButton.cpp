#include "DeviceToggleButton.h"

/**
 * Constructor
 *   pin : the physical pin used for the button
 *
 */
DeviceToggleButton::DeviceToggleButton(uint8_t pin) {
	this->pin = pin;
	pinMode(pin, INPUT);
}

DeviceToggleButton::~DeviceToggleButton() {
}

/**
 * isPressed returns true if button is pressed
 *
 */
boolean DeviceToggleButton::isPressed() {
	return (digitalRead(pin) == HIGH);
}
