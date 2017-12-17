/*
 * ProcessStat.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: root
 */

#include "ProcessNOP.h"
#include "ProcessAbstract.h"
#include <Arduino.h>

ProcessNOP::ProcessNOP(ServiceAbstract *service) : ProcessAbstract(service, "") {
}

ProcessNOP::~ProcessNOP() {
}

void ProcessNOP::start() {
}

void ProcessNOP::stop() {
}

void ProcessNOP::logStat() {
}

unsigned long ProcessNOP::getTotalTime() {
	return 0;
}

unsigned long ProcessNOP::getMaxElapseTime() {
	return 0;
}

unsigned long ProcessNOP::getHitCount() {
	return 0;
}

unsigned long ProcessNOP::getAverageTime() {
	return 0;
}
