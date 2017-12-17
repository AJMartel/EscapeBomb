#include "ProcessAbstract.h"

ProcessAbstract::ProcessAbstract(ServiceAbstract *service, const char *processName) {
	this->service=service;
	this->processName=processName;
}

ProcessAbstract::~ProcessAbstract() {
}

void ProcessAbstract::execCurrentState() {
	start();
	service->execCurrentState();
	stop();
}

const char* ProcessAbstract::getProcessName() {
	return processName;
}
