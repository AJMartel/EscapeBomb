#include "ServiceAbstract.h"

ServiceAbstract::ServiceAbstract() {
	listServiceListeners = new List<ServiceAbstract*>();
	runState=0;
}

ServiceAbstract::~ServiceAbstract() {
}

void ServiceAbstract::addAListener(ServiceAbstract* serviceListener) {
	listServiceListeners->add(serviceListener);
}

void ServiceAbstract::notify(Event *event) {
	ServiceAbstract* serviceAbstract;
	listServiceListeners->resetIterator();
	while (listServiceListeners->hasNext()) {
		serviceAbstract = listServiceListeners->next();
		serviceAbstract->update(event);
	}
}
