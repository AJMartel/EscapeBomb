/*
 * ServiceTrafficLight.h
 *
 *  Created on: May 21, 2017
 *      Author: root
 *
 * Manages Traffic light. Send events to ServicePedestrianLight. Wait for time events or pedestrian events.
 */

#ifndef SERVICE_SERVICESCREEN_H_
#define SERVICE_SERVICESCREEN_H_

#include "ServiceAbstract.h"
#include "../dao/DeviceLed.h"
#include "../util/SmartDelay.h"
#include "Event.h"

class ServiceScreen : public ServiceAbstract {
public:
	ServiceScreen();
	virtual ~ServiceScreen();
	void update(Event *event);

	void execCurrentState();

private:
	SmartDelay counter;
	uint16_t countdown;
	float speed;

	// pointer to the current state
	void (ServiceScreen::*currentState)();

	// differents states
	void stateNoDisplay();
	void stateDisplay();
	void stateGameOver();
	void stateWin();
};

#endif
