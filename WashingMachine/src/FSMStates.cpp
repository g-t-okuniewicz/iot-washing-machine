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

void Idle::readSensors(FSM& fsm) {
	throw std::runtime_error("Cannot read sensors until timer expires.");
}

void Idle::sendReadings(FSM& fsm) {
	throw std::runtime_error("Cannot send readings until timer expires.");
}

Sensing::~Sensing() {

}

void Sensing::readSensors(FSM& fsm) {
	// TODO:
}

void Sensing::sendReadings(FSM& fsm) {
	throw std::runtime_error("Cannot send while reading sensors.");
}

Processing::~Processing() {

}

void Processing::readSensors(FSM& fsm) {
	throw std::runtime_error("Cannot read sensors while communicating");
}

void Processing::sendReadings(FSM& fsm) {
	// TODO:
}
/*
#include "MachineStates.h"

AbstractState::~AbstractState() {

}

void AbstractState::setState(Machine& machine, AbstractState* state) {
	AbstractState* aux = machine.mState;
	machine.mState = state;
	delete aux;
}

void AbstractState::updateStock(Machine& machine, unsigned int quantity) {
	machine.mStockQuantity = quantity;
}

Normal::~Normal() {
}

void Normal::sell(Machine& machine, unsigned int quantity) {
	unsigned int currStock = machine.getCurrentStock();
	if (currStock < quantity) {
		throw std::runtime_error("Not enough stock");
	}

	updateStock(machine, currStock - quantity);

	if(machine.getCurrentStock() == 0) {
		setState(machine, new SoldOut());
	}
}

void Normal::refill(Machine& machine, unsigned int quantity) {
	int currStock = machine.getCurrentStock();
	updateStock(machine, currStock + quantity);
}

SoldOut::~SoldOut() {
}

void SoldOut::sell(Machine& machine, unsigned int quantity) {
	throw std::runtime_error("Sold out.");
}

void SoldOut::refill(Machine& machine, unsigned int quantity) {
	updateStock(machine, quantity);
	setState(machine, new Normal());
} */


