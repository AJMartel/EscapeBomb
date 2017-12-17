/*
 * DeviceToggle.h
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

#ifndef DAO_DEVICETOGGLEBUTTON_H_
#define DAO_DEVICETOGGLEBUTTON_H_

#include <Arduino.h>

class DeviceToggleButton {
public:
	DeviceToggleButton(uint8_t pin);
	virtual ~DeviceToggleButton();

	boolean isPressed();
private:
	uint8_t pin;
};

#endif
