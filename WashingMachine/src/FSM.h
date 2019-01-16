/*
 * FSM.h
 */

#ifndef FSM_H_
#define FSM_H_

#include "FSMStates.h"

// defined in FSMStates.h
class FSMState;

class FSM {
	friend class FSMState;
public:
	FSM();
	void readSensors();
	void sendReadings();
	~FSM();
private:
	FSMState* mState;
};

#endif /* FSM_H_ */
