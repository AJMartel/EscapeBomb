/*
 * ProcessAbstract.h
 *
 *  Created on: Jun 7, 2017
 *      Author: feud7506
 *
 * Processes are used to run services. Use Process for supervised processes and ProcessNOP for non supervised process.
 */

#ifndef PROCESS_PROCESSABSTRACT_H_
#define PROCESS_PROCESSABSTRACT_H_

#include "../service/ServiceAbstract.h"

class ProcessAbstract {
public:
	ProcessAbstract(ServiceAbstract *service, const char *processName);
	virtual ~ProcessAbstract();

	void execCurrentState();
	const char *getProcessName();

	virtual void start()=0;
	virtual void stop()=0;
	virtual void logStat()=0;
	virtual unsigned long getTotalTime()=0;
	virtual unsigned long getMaxElapseTime()=0;
	virtual unsigned long getHitCount()=0;
	virtual unsigned long getAverageTime()=0;

	ServiceAbstract *service;
	const char *processName;
private:
};

#endif
