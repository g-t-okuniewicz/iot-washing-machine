/*
 * Sensors.h
 *
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include <string>

class Reading {
public:
	Reading();
	virtual ~Reading();
	virtual std::string getMeasurement();
	virtual std::string getUnit();
	virtual std::string getValue();
	virtual void setMeasurement(std::string measurement);
	virtual void setUnit(std::string unit);
	virtual void setValue(std::string value);
protected:
	std::string measurement;
	std::string unit;
	std::string value;
};

class Sensor {
	//friend class Reading;
public:
	Sensor();
	virtual ~Sensor();
	virtual Reading getReading();
protected:
	Reading* mReading;
};

class DoorSensor : public Sensor {
	//friend class Reading;
public:
	DoorSensor();
	virtual ~DoorSensor();
	virtual Reading getReading();
};

class WaterTempSensor : public Sensor {
	//friend class Reading;
public:
	WaterTempSensor();
	virtual ~WaterTempSensor();
	virtual Reading getReading();
};

class WaterLevelSensor : public Sensor {
	//friend class Reading;
public:
	WaterLevelSensor();
	virtual ~WaterLevelSensor();
	virtual Reading getReading();
};

#endif /* SENSORS_H_ */
