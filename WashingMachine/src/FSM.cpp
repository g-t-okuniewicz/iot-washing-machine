/*
 * FSM.cpp
 *
 */

#include "FSM.h"

FSM::FSM(SensorManager* sensorManager, CommManager* commManager) {
	pSensorManager = sensorManager;
	pCommManager = commManager;
	std::cout << "Idle" << std::endl;
	pState = new Idle();
	onExit();
}

FSM::~FSM() {
	delete pState;
}

void FSM::onExit() {
	pState->onExit(*this);
}

SensorManager* FSM::getSensorManager() {
	return pSensorManager;
}

CommManager* FSM::getCommManager() {
	return pCommManager;
}
