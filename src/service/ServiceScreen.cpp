/*
 * ServiceTrafficLight.cpp
 *
 *  Created on: May 21, 2017
 *      Author: root
 */

#include "ServiceScreen.h"

ServiceScreen::ServiceScreen() {

	currentState = &ServiceScreen::stateNoDisplay;

	counter.reset();
	countdown = (30 * 60)+1;

	speed=1;
}

ServiceScreen::~ServiceScreen() {
}

void ServiceScreen::execCurrentState() {
	(this->*currentState)();
}

void ServiceScreen::update(Event *event) {
	if (event->getEventType() == EventTypeRun) {
		if( currentState == &ServiceScreen::stateNoDisplay ) {
			currentState = &ServiceScreen::stateDisplay;
			counter.reset();
		} else {
			speed=1;
		}
	} else if (event->getEventType() == EventTypeFastRun) {
		speed=0.25;
	} else if (event->getEventType() == EventTypeSlowRun) {
		speed=2;
	} else if (event->getEventType() == EventTypeLooseTime) {
		countdown=countdown-30;
	} else if (event->getEventType() == EventTypeWin) {
		currentState = &ServiceScreen::stateWin;
	}
}

void ServiceScreen::stateNoDisplay() {
}

void ServiceScreen::stateDisplay() {
	if (counter.now()) {
		counter.addNextDelay(1000*speed);
		countdown--;
		short minutes = countdown / 60;
		short seconds = countdown - minutes * 60;

		Serial.print(minutes);
		Serial.print(":");
		Serial.println(seconds);

		if (countdown == 0) {
			currentState = &ServiceScreen::stateGameOver;
		}
	}
}

void ServiceScreen::stateGameOver() {
	if (counter.now()) {
		Serial.println("GameOver !");
		counter.addNextDelay(10000);
	}
}

void ServiceScreen::stateWin() {
	if (counter.now()) {
		Serial.println("Win !");
		counter.addNextDelay(10000);
	}
}
