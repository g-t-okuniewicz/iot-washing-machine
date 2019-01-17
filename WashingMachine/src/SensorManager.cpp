/*
 * SensorManager.cpp
 *
 */

#include "SensorManager.h"

SensorManager::SensorManager(std::vector<Sensor*>* sensors) {
	mSensors = sensors;
	for(unsigned int i=0; i<mSensors->size(); i++) {
		mReadings.push_back(mSensors->at(i)->getReading());
	}
}

SensorManager::~SensorManager() {
	delete mSensors;
	delete &mReadings;
}

void SensorManager::readSensors() {
	mReadings.clear();
	for(unsigned int i=0; i<mSensors->size(); i++) {
		mReadings.push_back(mSensors->at(i)->getReading());
	}
}

std::vector<Reading> SensorManager::getReadings() {
	mReadings.clear();
	for(unsigned int i=0; i<mSensors->size(); i++) {
		mReadings.push_back(mSensors->at(i)->getReading());
	}
	return mReadings;
}
/*
void SensorManager::sendReadings() {
	for(unsigned int i=0; i<mSensors->size(); i++) {
		std::cout << mReadings.at(i).getMeasurement() << std::endl;
		std::cout << mReadings.at(i).getUnit() << std::endl;
		std::cout << mReadings.at(i).getValue() << std::endl;
	}
}*/
