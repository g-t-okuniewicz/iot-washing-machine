/*
 * FSMStates.h
 *
 */

#ifndef FSMSTATES_H_
#define FSMSTATES_H_

#include "FSM.h"
#include <exception>
#include <stdexcept>

class FSM;

class FSMState {
public:
	virtual void readSensors(FSM& fsm) = 0;
	virtual void sendReadings(FSM& fsm) = 0;
	virtual ~FSMState();
protected:
	void setState(FSM& fsm, FSMState* state);
};

class Idle : public FSMState {
public:
	virtual void readSensors(FSM& fsm);
	virtual void sendReadings(FSM& fsm);
	virtual ~Idle();
};

class Sensing : public FSMState {
public:
	virtual void readSensors(FSM& fsm);
	virtual void sendReadings(FSM& fsm);
	virtual ~Sensing();
};

class Processing : public FSMState {
public:
	virtual void readSensors(FSM& fsm);
	virtual void sendReadings(FSM& fsm);
	virtual ~Processing();
};

#endif /* FSMSTATES_H_ */

/*
 #include "machine.h"
#include <exception>
#include <stdexcept>

class Machine;

class AbstractState {
public:
	virtual void sell(Machine& machine, unsigned int quantity) = 0;
	virtual void refill(Machine& machine, unsigned int quantity) = 0;
	virtual ~AbstractState();
protected:
	void setState(Machine& machine, AbstractState* state);
	void updateStock(Machine& machine, unsigned int quantity);
};

class Normal : public AbstractState {
public:
	virtual void sell(Machine& machine, unsigned int quantity);
	virtual void refill(Machine& machine, unsigned int quantity);
	virtual ~Normal();
};

class SoldOut : public AbstractState {
public:
	virtual void sell(Machine& machine, unsigned int quantity);
	virtual void refill(Machine& machine, unsigned int quantity);
	virtual ~SoldOut();
};
 */
