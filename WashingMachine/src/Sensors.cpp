/*
 * Sensors.cpp
 *
 */

#include "Sensors.h"

Reading::Reading() {
	measurement = "null";
	unit = "null";
	value = "null";
}

Reading::~Reading() {

}

void Reading::setMeasurement(std::string measurement) {
	this->measurement = measurement;
}

void Reading::setUnit(std::string unit) {
	this->unit = unit;
}

void Reading::setValue(std::string value) {
	this->value = value;
}

std::string Reading::getMeasurement() {
	return measurement;
}

std::string Reading::getUnit() {
	return unit;
}

std::string Reading::getValue() {
	return value;
}

Sensor::Sensor() {
	mReading = new Reading();
}

Sensor::~Sensor() {
	delete mReading;
}

Reading Sensor::getReading() {
	return *mReading;
}

DoorSensor::DoorSensor() {
	mReading = new Reading();
	mReading->setMeasurement("door_status");
	mReading->setValue("closed");
}

DoorSensor::~DoorSensor() {
	delete mReading;
}

Reading DoorSensor::getReading() {
	return *mReading;
}

WaterTempSensor::WaterTempSensor() {
	mReading = new Reading();
	mReading->setMeasurement("water_temp");
	mReading->setUnit("deg_C");
}

WaterTempSensor::~WaterTempSensor() {
	delete mReading;
}

Reading WaterTempSensor::getReading() {
	return *mReading;
}

WaterLevelSensor::WaterLevelSensor() {
	mReading = new Reading();
	mReading->setMeasurement("water_level");
	mReading->setUnit("l");
}

WaterLevelSensor::~WaterLevelSensor() {
	delete mReading;
}

Reading WaterLevelSensor::getReading() {
	return *mReading;
}
