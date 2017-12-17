/*
 * DeviceLed.h
 *
 *  Created on: Jun 12, 2016
 *      Author: feud7506
 *
 * Manages press button. To plug :
 *   - no need to use a pullup resistor (internal arduino pullup is used)
 *
 * Example :
 * DeviceButton deviceButton(PIN);
 * device Button.isPressed();
 *
 * DeviceButton	deviceButton = new DeviceButton(PIN_BUTTON);
 * deviceButton->isPressed();
 *
 */

#ifndef DAO_DEVICEBUTTON_H_
#define DAO_DEVICEBUTTON_H_

#include <Arduino.h>

class DeviceButton {
public:
	DeviceButton(uint8_t pin);
	virtual ~DeviceButton();

	boolean isPressed();
private:
	uint8_t pin;
};

#endif
