#include "Process.h"
#include "ProcessAbstract.h"
#include <Arduino.h>

Process::Process(ServiceAbstract *service, const char *processName) : ProcessAbstract(service, processName) {
	this->totalTime=0;
	this->maxElapseTime=0;
	this->hitCount=0;
	this->currentElapseTime=0;
}

Process::~Process() {
}

void Process::start() {
	this->currentElapseTime=millis();
	this->hitCount++;
}

void Process::stop() {
	unsigned long elapseTime=millis()-this->currentElapseTime;
	this->totalTime+=elapseTime;
	if( elapseTime > this->maxElapseTime) {
		this->maxElapseTime=elapseTime;
	}
}

void Process::logStat() {
	Serial.print("PROCESS|");
	Serial.print(this->getProcessName());
	Serial.print("|");
	Serial.print(this->getTotalTime());
	Serial.print("|");
	Serial.print(this->getHitCount());
	Serial.print("|");
	Serial.print(this->getAverageTime());
	Serial.print("|");
	Serial.print(this->getMaxElapseTime());
	Serial.println();
}

unsigned long Process::getTotalTime() {
	return this->totalTime;
}

unsigned long Process::getMaxElapseTime() {
	return this->maxElapseTime;
}

unsigned long Process::getHitCount() {
	return this->hitCount;
}

unsigned long Process::getAverageTime() {
	if( this->hitCount == 0) {
		return 0;
	} else {
		return this->totalTime/this->hitCount;
	}
}
