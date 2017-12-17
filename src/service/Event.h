/*
 * Event.h
 *
 *  Created on: Mar 2, 2017
 *      Author: feud7506
 *
 *  Stores Event type (from enum eventType) et eventValue if needed
 *
 */

#ifndef SERVICE_EVENT_H
#define SERVICE_EVENT_H

enum EventType {EventTypeUndefined = 0, EventTypeRun = 1, EventTypeSlowRun = 2, EventTypeFastRun = 3, EventTypeLooseTime = 4, EventTypeWin = 5} ;


class Event {
public:
	Event(EventType eventType);
	~Event();

	EventType getEventType();
	void* getValue();
	void setValue(void *value);
private:
	EventType eventType;
	void* value;
};

#endif
