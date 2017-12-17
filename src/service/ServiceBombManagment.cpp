#include "Event.h"
#include "ServiceBombManagment.h"

ServiceBombManagment::ServiceBombManagment() {
	photoresistor = new DevicePhotoresistor(PIN_PHOTORESISTOR);
	coverContactor = new DeviceButton(PIN_COVER);
	wire1 = new DeviceButton(PIN_WIRE1);
	toggle1 = new DeviceToggleButton(PIN_TOGGLE1);
	toggle2 = new DeviceToggleButton(PIN_TOGGLE2);
	toggle3 = new DeviceToggleButton(PIN_TOGGLE3);
	toggle4 = new DeviceToggleButton(PIN_TOGGLE4);
	toggle5 = new DeviceToggleButton(PIN_TOGGLE5);

	currentState = &ServiceBombManagment::stateInitial;
}

ServiceBombManagment::~ServiceBombManagment() {
}

void ServiceBombManagment::execCurrentState() {
	(this->*currentState)();
}

void ServiceBombManagment::update(Event *event) {
}

void ServiceBombManagment::stateInitial() {
	if (photoresistor->readLight() >= LUX_NIGHT) {
		Serial.print("Light received ");
		Serial.println(photoresistor->readLight());
		Event event(EventTypeRun);
		notify(&event);

		currentState = &ServiceBombManagment::stateCoverBlocked;
	}
}

void ServiceBombManagment::stateCoverBlocked() {
	if (!coverContactor->isPressed()) {
		Serial.println("Cover unlock");
		Event event(EventTypeFastRun);
		notify(&event);

		currentState = &ServiceBombManagment::stateCoverReleased;
	} else if (!wire1->isPressed()) {
		Serial.println("Wire1 unplugged");
		currentState = &ServiceBombManagment::stateToggleSwitchInit;
	}
}

void ServiceBombManagment::stateCoverReleased() {
	if (coverContactor->isPressed()) {
		Serial.println("Cover released");
		Event event(EventTypeRun);
		notify(&event);

		currentState = &ServiceBombManagment::stateCoverBlocked;
	}
}

int ServiceBombManagment::togglesOnToInt() {
	int toggleOnToInt = 0;
	if (toggle1->isPressed())
		toggleOnToInt += 1;
	if (toggle2->isPressed())
		toggleOnToInt += 2;
	if (toggle3->isPressed())
		toggleOnToInt += 4;
	if (toggle4->isPressed())
		toggleOnToInt += 8;
	if (toggle5->isPressed())
		toggleOnToInt += 16;

	return toggleOnToInt;
}

void ServiceBombManagment::stateToggleSwitchInit() {
	int toggleOnToInt = togglesOnToInt();

	if (toggleOnToInt != TOGGLE_SWITCH_ALL_OFF) {
		Serial.print("Toggle ");
		Serial.print(toggleOnToInt);
		delay(10);
		if (toggleOnToInt == TOGGLE_SWITCH_1_ON) {
			Serial.println(" next");
			currentState = &ServiceBombManagment::stateToggleSwitch1;
		} else {
			Serial.println(" error");
			currentState = &ServiceBombManagment::stateToggleSwitchKo;
		}
	}
}

void ServiceBombManagment::stateToggleSwitch1() {
	int toggleOnToInt = togglesOnToInt();

	if (toggleOnToInt != TOGGLE_SWITCH_1_ON) {
		Serial.print("Toggle ");
		Serial.print(toggleOnToInt);
		delay(10);
		if (toggleOnToInt == TOGGLE_SWITCH_1_2_ON) {
			Serial.println(" next");
			currentState = &ServiceBombManagment::stateToggleSwitch2;
		} else {
			Serial.println(" error");
			currentState = &ServiceBombManagment::stateToggleSwitchKo;
		}
	}
}

void ServiceBombManagment::stateToggleSwitch2() {
	int toggleOnToInt = togglesOnToInt();

	if (toggleOnToInt != TOGGLE_SWITCH_1_2_ON) {
		Serial.print("Toggle ");
		Serial.print(toggleOnToInt);
		delay(10);
		if (toggleOnToInt == TOGGLE_SWITCH_1_2_3_ON) {
			Serial.println(" next");
			currentState = &ServiceBombManagment::stateToggleSwitch3;
		} else {
			Serial.println(" error");
			currentState = &ServiceBombManagment::stateToggleSwitchKo;
		}
	}
}

void ServiceBombManagment::stateToggleSwitch3() {
	int toggleOnToInt = togglesOnToInt();

	if (toggleOnToInt != TOGGLE_SWITCH_1_2_3_ON) {
		Serial.print("Toggle ");
		Serial.print(toggleOnToInt);
		delay(10);
		if (toggleOnToInt == TOGGLE_SWITCH_1_2_3_4_ON) {
			Serial.println(" next");
			currentState = &ServiceBombManagment::stateToggleSwitch4;
		} else {
			Serial.println(" error");
			currentState = &ServiceBombManagment::stateToggleSwitchKo;
		}
	}
}

void ServiceBombManagment::stateToggleSwitch4() {
	int toggleOnToInt = togglesOnToInt();

	if (toggleOnToInt != TOGGLE_SWITCH_1_2_3_4_ON) {
		Serial.print("Toggle ");
		Serial.print(toggleOnToInt);
		delay(10);
		if (toggleOnToInt == TOGGLE_SWITCH_ALL_ON) {
			Serial.println(" next");
			currentState = &ServiceBombManagment::stateWin;
		} else {
			Serial.println(" error");
			currentState = &ServiceBombManagment::stateToggleSwitchKo;
		}
	}
}

void ServiceBombManagment::stateToggleSwitchKo() {
	int toggleOnToInt = togglesOnToInt();

	if (toggleOnToInt == TOGGLE_SWITCH_ALL_OFF) {
		Serial.println("Toggle init");
		Event event(EventTypeLooseTime);
		notify(&event);

		currentState = &ServiceBombManagment::stateToggleSwitchInit;
	}
}

void ServiceBombManagment::stateWin() {
	Event event(EventTypeWin);
	notify(&event);
	currentState = &ServiceBombManagment::stateStop;

}

void ServiceBombManagment::stateStop() {
}
//Sur le côté de la bombe, un tube pvc transparent est fixé. Un capteur de niveau est caché dans le tube dans une partie non visible (ou pas). Sur ce tuyau est inscript "add water to refresh". Des tuyaux capilaires en sortent. Ces tuyaux sont reliés à un bouchon plastique.
//  => déboucher une bouteille d'eau trouvée dans la valiser
//  => boucher la bouteille avec le bouchon relié au mécanisme
//  => Placer la bouteille la tete en bas, fixée sur son support. Le liquide coule doucement. Il remplit le tube pvc. Lorsque le niveau est assez eau, cela ralenti le compte à rebour.
//

//Des fils de couleur sortent du mécanisme. Il faut débrancher les bons fils selon les indices trouvés dans la valise.
//  => Débrancher les mauvais fils fait accélerer le compte à rebours de 1 seconde à 1/10 de seconde
//  => Le rebrancher remets le compte a rebour dans le bon timing
//  => Lorsqu'il ne reste que les fils de bonne couleur, les leds à bascule s'allument
//
//Etteindre les leds à bascule dans le bon ordre. Lorsque la dernière led est etteinte :
//  => Si les bascules ont été coupées dans le bon ordre => le compte a rebour indique 0:00 et clignote puis affiche "gagné" et clignoque
//  => Sinon, le compte a rebour perd un temps donné. Il faut allumer toutes les leds à nouveau pour essayer un nouvel ordre
//
//Si le compte a rebour arrive à 0:10, un buzzer indique chaque seconde. A 0:00, il clignotte puis affiche "boom" ou dessiner une explision en clignotant et le buzzer sonne pendant 10 secondes.
//
//J'aimerais ajouter un mécanisme utilisant une bille de mercure qui fait un contact lorsqu'on incline la bille.
