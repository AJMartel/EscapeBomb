/*
 * ServicePedestrianLight.h
 *
 *  Created on: May 21, 2017
 *      Author: feud7506
 *
 * Manages the pedestrian light. Wait for traffic light events.
 *
 */

#ifndef SERVICE_SERVICEBOMBMANAGMENT_H_
#define SERVICE_SERVICEBOMBMANAGMENT_H_

#include "ServiceAbstract.h"
#include "../dao/DeviceButton.h"
#include "../dao/DeviceToggleButton.h"
#include "../dao/DevicePhotoresistor.h"
#include "../util/SmartDelay.h"
#include "Event.h"

#define PIN_PHOTORESISTOR A0
#define PIN_COVER 2
#define PIN_WIRE1 10
#define PIN_TOGGLE1 3
#define PIN_TOGGLE2 4
#define PIN_TOGGLE3 5
#define PIN_TOGGLE4 6
#define PIN_TOGGLE5 7

#define LUX_NIGHT 100

#define TOGGLE_SWITCH_ALL_OFF 0
#define TOGGLE_SWITCH_1_ON 1
#define TOGGLE_SWITCH_1_2_ON 3
#define TOGGLE_SWITCH_1_2_3_ON 7
#define TOGGLE_SWITCH_1_2_3_4_ON 15
#define TOGGLE_SWITCH_ALL_ON 31

class ServiceBombManagment : public ServiceAbstract {
public:
	ServiceBombManagment();
	virtual ~ServiceBombManagment();
	void update(Event *event);

	void execCurrentState();

private:
	DevicePhotoresistor* photoresistor;
	DeviceButton* coverContactor;
	DeviceButton* wire1;

	DeviceToggleButton* toggle1;
	DeviceToggleButton* toggle2;
	DeviceToggleButton* toggle3;
	DeviceToggleButton* toggle4;
	DeviceToggleButton* toggle5;

	// pointer to the current state
	void (ServiceBombManagment::*currentState)();

	// differents states
	void stateInitial();
	void stateCoverBlocked();
	void stateCoverReleased();

	void stateToggleSwitchInit();
	void stateToggleSwitch1();
	void stateToggleSwitch2();
	void stateToggleSwitch3();
	void stateToggleSwitch4();
	void stateToggleSwitchKo();
	void stateWin();
	void stateStop();

	int togglesOnToInt();
};

#endif
