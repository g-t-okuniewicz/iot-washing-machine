/*
 * FSMStates.cpp
 *
 */

#include "FSMStates.h"

FSMState::~FSMState() {

}

void FSMState::setState(FSM& fsm, FSMState* state) {
	FSMState* aux = fsm.pState;
	fsm.pState = state;
	delete aux;
}

Idle::~Idle() {

}

void Idle::onExit(FSM& fsm) {
	usleep(10000000);
	std::cout << "Sensing" << std::endl;
	setState(fsm, new Sensing());
	fsm.onExit();
}

Sensing::~Sensing() {

}

void Sensing::onExit(FSM& fsm) {
	fsm.getSensorManager()->readSensors();
	std::cout << "Processing" << std::endl;
	setState(fsm, new Processing());
	fsm.onExit();
}

Processing::~Processing() {

}

void Processing::onExit(FSM& fsm) {
	fsm.getCommManager()->sendReadings(
			fsm.getSensorManager()->getReadings()
			);
	std::cout << "Idle" << std::endl;
	setState(fsm, new Idle());
	fsm.onExit();
}
