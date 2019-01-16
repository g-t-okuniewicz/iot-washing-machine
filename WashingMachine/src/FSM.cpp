/*
 * FSM.cpp
 *
 */

#include "FSM.h"

FSM::FSM(SensorManager* sensorManager) {
	mSensorManager = sensorManager;
	std::cout << "Idle" << std::endl;
	mState = new Idle();
	waitForTimer();
}

FSM::~FSM() {
	delete mState;
}

void FSM::waitForTimer() {
	mState->waitForTimer(*this);
}

void FSM::readSensors() {
	mState->readSensors(*this);
}

void FSM::sendReadings() {
	mState->sendReadings(*this);
}

SensorManager* FSM::getSensorManager() {
	return mSensorManager;
}
