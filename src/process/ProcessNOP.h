/*
 * ProcessNOP.h
 *
 *  Created on: Jun 7, 2017
 *      Author: feud7506
 *
 * Use Process for supervised processes and ProcessNOP for non supervised process.
 *
 */

#ifndef PROCESS_PROCESSNOP_H_
#define PROCESS_PROCESSNOP_H_

#include "ProcessAbstract.h"

class ProcessNOP : public ProcessAbstract {
public:
	ProcessNOP(ServiceAbstract *service);
	virtual ~ProcessNOP();

	void start();
	void stop();
	void logStat();
	unsigned long getTotalTime();
	unsigned long getMaxElapseTime();
	unsigned long getHitCount();
	unsigned long getAverageTime();
private:
};

#endif
