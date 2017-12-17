/*
 * SmartDelay.cpp
 *
 *  Created on: Jun 6, 2017
 *      Author: root
 */

#include "SmartDelay.h"

/**
 * Default constructor
 */
SmartDelay::SmartDelay() {
	this->nextDelay=0;
}

SmartDelay::~SmartDelay() {
}

/**
 * True is current millis() greater than nextDelay
 */
bool SmartDelay::now() {
	return ( millis() > this->nextDelay );
}

/**
 * reset nextDelay to 0
 */
void SmartDelay::reset() {
	this->nextDelay=millis();
}

/**
 * set nextDelay
 */
void SmartDelay::setNextDelay(unsigned long nextDelay) {
	this->nextDelay=nextDelay;
}

/**
 *  add millis to the stored nextDelay
 */
void SmartDelay::addNextDelay(unsigned long millisToAdd) {
	this->nextDelay += millisToAdd;
}
