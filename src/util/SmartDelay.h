/*
 * SmartDelay.h
 *
 *  Created on: Jun 6, 2017
 *      Author: feud7506
 *
 *  This class is used for non blocking delays in milliseconds for Arduino code specially for multitasking management
 */

#ifndef SRC_UTIL_SMARTDELAY_H_
#define SRC_UTIL_SMARTDELAY_H_

#include <Arduino.h>

class SmartDelay {
public:
	SmartDelay();
	virtual ~SmartDelay();
	bool now();
	void reset();
	void setNow();
	void setNextDelay(unsigned long nextDelay);
	void addNextDelay(unsigned long millisToAdd);
private:
	unsigned long nextDelay;
};

#endif
