/*
 * CommManager.h
 *
 */

#ifndef COMMMANAGER_H_
#define COMMMANAGER_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include "Sensors.h"
#include "mongoose.h"

class CommManager {
public:
	void sendReadings(std::vector<Reading> readings);
};



#endif /* COMMMANAGER_H_ */
