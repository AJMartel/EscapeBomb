/*
 * DevicePhotoresistor.h
 *
 *  Created on: Jun 12, 2016
 *      Author: feud7506
 *
 * Manages photoresistor. To plug :
 *   - // TODO
 *
 * Example :
 * TODO
 * DeviceButton deviceButton(PIN);
 * device Button.isPressed();
 *
 * DeviceButton	deviceButton = new DeviceButton(PIN_BUTTON);
 * deviceButton->isPressed();
 *
 */

#ifndef DAO_DEVICEPHOTORESISTOR_H_
#define DAO_DEVICEPHOTORESISTOR_H_

#include <Arduino.h>

class DevicePhotoresistor {
public:
	DevicePhotoresistor(uint8_t pin);
	virtual ~DevicePhotoresistor();

	uint8_t readLight();
private:
	uint8_t pin;
};

#endif
