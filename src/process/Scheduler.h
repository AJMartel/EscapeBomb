/*
 * Scheduler.h
 *
 *  Created on: Jun 6, 2017
 *      Author: feud7506
 *
 * Orchestrator for processes management.
 */

#ifndef PROCESS_SCHEDULER_H_
#define PROCESS_SCHEDULER_H_

#include "ProcessAbstract.h"
#include "Process.h"
#include "ProcessNOP.h"
#include "../util/SmartDelay.h"


class Scheduler {
public:
	Scheduler();
	Scheduler(unsigned long topMillis);
	virtual ~Scheduler();
	void addService(ServiceAbstract *service);
	void addService(ServiceAbstract *service, const char* processName);
	void runAllProcesses();
	int getFreeRam();
	void resetProcessIterator();
	ProcessAbstract *nextProcess();
	bool hasNextProcess();
private:
	List<ProcessAbstract*>* processes;
	unsigned long topMillis;
	SmartDelay* schedulerDelay;
};

#endif
