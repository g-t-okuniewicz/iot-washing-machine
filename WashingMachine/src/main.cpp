/*
 * main.cpp
 *
 */

#include <iostream>
#include "SensorManager.h"
#include "FSM.h"

int main() {

	std::vector<Sensor*> sensors;

	DoorSensor* doorSensor = new DoorSensor();
	sensors.push_back(doorSensor);

	WaterLevelSensor* waterLevelSensor = new WaterLevelSensor();
	sensors.push_back(waterLevelSensor);

	WaterTempSensor* waterTempSensor = new WaterTempSensor();
	sensors.push_back(waterTempSensor);

	SensorManager* sensorManager = new SensorManager(&sensors);
	//sensorManager->readSensors();
	//sensorManager->sendReadings();

	FSM* fsm = new FSM(sensorManager);

	delete doorSensor;
	delete waterLevelSensor;
	delete waterTempSensor;
	delete fsm;

	return 0;
}
