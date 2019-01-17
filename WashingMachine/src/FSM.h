/*
 * FSM.h
 */

#ifndef FSM_H_
#define FSM_H_

#include "FSMStates.h"
#include "SensorManager.h"
#include "CommManager.h"

// defined in FSMStates.h
class FSMState;

class FSM {
	friend class FSMState;
public:
	FSM(SensorManager* pSensorManager, CommManager* pCommManager);
	void onExit();
	SensorManager* getSensorManager();
	CommManager* getCommManager();
	~FSM();
private:
	FSMState* pState;
	SensorManager* pSensorManager;
	CommManager* pCommManager;
};

#endif /* FSM_H_ */
