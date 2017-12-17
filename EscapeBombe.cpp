/**
 * Main programme for EscapeBombe managment
 *
 */
#include "EscapeBombe.h"

#include "src/process/Scheduler.h"
#include "src/service/ServiceScreen.h"
#include "src/service/ServiceBombManagment.h"

#define LOGGER "EscapeBombe : "

Scheduler scheduler(10000);
SmartDelay schedulerDelay;

void setup() {
	Serial.begin(9600);
	delay(200);
	Serial.print(LOGGER);
	Serial.println("starting");

	ServiceScreen* serviceScreen = new ServiceScreen();
	ServiceBombManagment* serviceBombManagment = new ServiceBombManagment();

	serviceBombManagment->addAListener(serviceScreen);

	scheduler.addService(serviceScreen);
	scheduler.addService(serviceBombManagment);

	delay(300);
	Serial.print(LOGGER);
	Serial.println("started");
}

void loop() {
	scheduler.runAllProcesses();
}
