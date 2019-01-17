/*
 * SensorManager.h
 *
 */

#ifndef SENSORMANAGER_H_
#define SENSORMANAGER_H_

#include "Sensors.h"
#include <vector>
#include <iostream>

class SensorManager {
public:
	SensorManager(std::vector<Sensor*>* sensors);
	virtual ~SensorManager();
	virtual void readSensors();
	virtual std::vector<Reading> getReadings();
private:
	std::vector<Sensor*>* mSensors;
	std::vector<Reading> mReadings;
};

#endif /* SENSORMANAGER_H_ */
