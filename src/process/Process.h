/*
 * Process.h
 *
 *  Created on: Jun 7, 2017
 *      Author: feud7506
 *
 * Use Process for supervised processes and ProcessNOP for non supervised process.
 *
 */

#ifndef PROCESS_PROCESS_H_
#define PROCESS_PROCESS_H_

#include "ProcessAbstract.h"

class Process : public ProcessAbstract {
public:
	Process(ServiceAbstract *service, const char *processName);
	virtual ~Process();

	void start();
	void stop();
	void logStat();
	unsigned long getTotalTime();
	unsigned long getMaxElapseTime();
	unsigned long getHitCount();
	unsigned long getAverageTime();
private:
	unsigned long totalTime;
	unsigned long maxElapseTime;
	unsigned long hitCount;
	unsigned long currentElapseTime;
};

#endif
