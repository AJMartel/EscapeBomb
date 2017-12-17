/*
 * DeviceLed.h
 *
 * Created on: Jun 12, 2016
 *      Author: feud7506
 *
 * Manages LEDs. To plug :
 *   - use 220 ohms resistor between vcc and led or led and gnd
 *   - long leg led must be used with vcc, short with gnd
 *   - remind that the default led 13 is on the board.
 *
 * Example :
 * DeviceLed deviceled(PIN_LED);
 * deviceled.turnOn();
 *
 * DeviceLed deviceLed = new DeviceLed(PIN_LED);
 * deviceled->turnOff();
 *
 */

#ifndef DAO_DEVICELED_H_
#define DAO_DEVICELED_H_

#include <Arduino.h>

#define DEFAULT_LED 13

class DeviceLed {
public:
	DeviceLed();
	DeviceLed(uint8_t pin);
	virtual ~DeviceLed();

	void turnOn();
	void turnOff();
private:
	uint8_t pin;
};

#endif
