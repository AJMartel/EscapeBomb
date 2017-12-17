/*
 * ServiceAbstract.h
 *
 * Created on: Apr 25, 2017
 *      Author: feud7506
 *
 * Abstract class for services implementation.
 */

#ifndef SERVICE_SERVICEABSTRACT_H_
#define SERVICE_SERVICEABSTRACT_H_

#include "../util/List.h"
#include "Event.h"

class ServiceAbstract {
private:
	List<ServiceAbstract*>* listServiceListeners;
	void (*runState)();	// pointer to the current state

public:
	ServiceAbstract();
	virtual ~ServiceAbstract();
	void addAListener(ServiceAbstract* serviceListener);
	void notify(Event *event);
	virtual void update(Event *event)=0;
	virtual void execCurrentState()=0;
};

#endif
