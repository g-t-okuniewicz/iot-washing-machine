/*
 * FSM.h
 */

#ifndef FSM_H_
#define FSM_H_

#include "FSMStates.h"
#include "SensorManager.h"

// defined in FSMStates.h
class FSMState;

class FSM {
	friend class FSMState;
public:
	FSM(SensorManager* sensorManager);
	void readSensors();
	void sendReadings();
	void waitForTimer();
	SensorManager* getSensorManager();
	~FSM();
private:
	FSMState* mState;
	SensorManager* mSensorManager;
};

#endif /* FSM_H_ */
