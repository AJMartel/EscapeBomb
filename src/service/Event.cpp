#include "Event.h"

/**
 * Default constructor, creates list with start and end as NULL
 */
Event::Event(EventType eventType) {
	this->eventType=eventType;
	this->value=0;
}

/**
 * Default destructor
 */
Event::~Event() {
}

EventType Event::getEventType() {
	return this->eventType;
}

void* Event::getValue() {
	return value;
}

void Event::setValue(void *value) {
	this->value=value;
}
