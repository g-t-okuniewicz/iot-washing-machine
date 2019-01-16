/*
 * FSM.cpp
 *
 */

#include "FSM.h"

FSM::FSM() {
	mState = new Idle();
}

FSM::~FSM() {
	delete mState;
}

void FSM::readSensors() {
	mState->readSensors(*this);
}

void FSM::sendReadings() {
	mState->sendReadings(*this);
}
