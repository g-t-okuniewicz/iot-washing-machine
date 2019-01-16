/*
 * FSMStates.h
 *
 */

#ifndef FSMSTATES_H_
#define FSMSTATES_H_

#include "FSM.h"
#include <exception>
#include <stdexcept>
#include <unistd.h>

class FSM;

class FSMState {
public:
	virtual void waitForTimer(FSM& fsm) = 0;
	virtual void readSensors(FSM& fsm) = 0;
	virtual void sendReadings(FSM& fsm) = 0;
	virtual ~FSMState();
protected:
	void setState(FSM& fsm, FSMState* state);
};

class Idle : public FSMState {
public:
	virtual void waitForTimer(FSM& fsm);
	virtual void readSensors(FSM& fsm);
	virtual void sendReadings(FSM& fsm);
	virtual ~Idle();
};

class Sensing : public FSMState {
public:
	virtual void waitForTimer(FSM& fsm);
	virtual void readSensors(FSM& fsm);
	virtual void sendReadings(FSM& fsm);
	virtual ~Sensing();
};

class Processing : public FSMState {
public:
	virtual void waitForTimer(FSM& fsm);
	virtual void readSensors(FSM& fsm);
	virtual void sendReadings(FSM& fsm);
	virtual ~Processing();
};

#endif /* FSMSTATES_H_ */
