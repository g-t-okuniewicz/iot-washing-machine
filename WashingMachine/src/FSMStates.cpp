/*
 * FSMStates.cpp
 *
 */

#include "FSMStates.h"

FSMState::~FSMState() {

}

void FSMState::setState(FSM& fsm, FSMState* state) {
	FSMState* aux = fsm.mState;
	fsm.mState = state;
	delete aux;
}

Idle::~Idle() {

}

void Idle::waitForTimer(FSM& fsm) {
	usleep(10000000);
	std::cout << "Sensing" << std::endl;
	setState(fsm, new Sensing());
	fsm.readSensors();
}

void Idle::readSensors(FSM& fsm) {
	throw std::runtime_error("Cannot read sensors until timer expires.");
}

void Idle::sendReadings(FSM& fsm) {
	throw std::runtime_error("Cannot send readings until timer expires.");
}

Sensing::~Sensing() {

}

void Sensing::waitForTimer(FSM& fsm) {
	throw std::runtime_error("Cannot wait while reading sensors.");
}

void Sensing::readSensors(FSM& fsm) {
	fsm.getSensorManager()->readSensors();
	std::cout << "Processing" << std::endl;
	setState(fsm, new Processing());
	fsm.sendReadings();
}

void Sensing::sendReadings(FSM& fsm) {
	throw std::runtime_error("Cannot send while reading sensors.");
}

Processing::~Processing() {

}

void Processing::waitForTimer(FSM& fsm) {
	throw std::runtime_error("Cannot wait while communicating.");
}

void Processing::readSensors(FSM& fsm) {
	throw std::runtime_error("Cannot read sensors while communicating");
}

void Processing::sendReadings(FSM& fsm) {
	fsm.getSensorManager()->sendReadings();
	std::cout << "Idle" << std::endl;
	setState(fsm, new Idle());
	fsm.waitForTimer();
}
