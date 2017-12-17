#include "DeviceButton.h"

/**
 * Constructor
 *   pin : the physical pin used for the button
 *
 */
DeviceButton::DeviceButton(uint8_t pin) {
	this->pin = pin;
	pinMode(pin, INPUT_PULLUP);
}

DeviceButton::~DeviceButton() {
}

/**
 * isPressed returns true if button is pressed
 *
 */
boolean DeviceButton::isPressed() {
	return (digitalRead(pin) == LOW);
}
