#include "Scheduler.h"

Scheduler::Scheduler() {
	this->processes = new List<ProcessAbstract*>();
	this->topMillis=0;
	this->schedulerDelay = 0;
}

Scheduler::Scheduler(unsigned long topMillis) {
	this->processes = new List<ProcessAbstract*>();
	this->topMillis=topMillis;
	this->schedulerDelay = new SmartDelay();
}

Scheduler::~Scheduler() {
}

/**
 * add a service to be orchestrated. No supervision.
 */
void Scheduler::addService(ServiceAbstract *service) {
	ProcessNOP *process = new ProcessNOP(service);
	processes->add(process);
}

/**
 * add a service to be orchestrated and supervised. The given name will be used for log
 */
void Scheduler::addService(ServiceAbstract *service, const char *processName) {
	Process *process = new Process(service, processName);
	processes->add(process);
}

void Scheduler::runAllProcesses() {
	ProcessAbstract* process;
	boolean logProcessStatNow=this->schedulerDelay->now();

	processes->resetIterator();
	while (processes->hasNext()) {
		process = processes->next();
		process->execCurrentState();
		if( logProcessStatNow ) {
			process->logStat();
		}
	}

	if( logProcessStatNow ) {
		Serial.print("FREEMEM|");
		Serial.println(this->getFreeRam());

		this->schedulerDelay->reset();
		this->schedulerDelay->addNextDelay(this->topMillis);
	}
}

int Scheduler::getFreeRam() {
	extern int __heap_start, *__brkval;
	int v;
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void Scheduler::resetProcessIterator() {
	processes->resetIterator();
}

ProcessAbstract *Scheduler::nextProcess() {
	return processes->next();
}

bool Scheduler::hasNextProcess() {
	return processes->hasNext();
}
