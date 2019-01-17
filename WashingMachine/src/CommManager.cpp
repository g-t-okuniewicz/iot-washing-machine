/*
 * CommManager.cpp
 *
 */

#include "CommManager.h"

static const char *url = "localhost:8080/send-readings";

static void ev_handler(struct mg_connection *c, int ev, void *p);

void CommManager::sendReadings(std::vector<Reading> readings) {

	struct mg_mgr mgr;

	std::cout << "CommManager: Sending readings" << std::endl;
	std::string messageString;

	time_t now = time(0);
	tm *ltm = localtime(&now);

	char timestamp[8];
	sprintf(timestamp,
			"%02d:%02d:%02d",
			ltm->tm_hour,
			ltm->tm_min,
			ltm->tm_sec);

	for(unsigned int i=0; i<readings.size(); i++) {
		messageString.append("<reading>");
		messageString.append("<timestamp>");
		messageString.append(timestamp);
		messageString.append("</timestamp>");
		messageString.append("<measurement>");
		messageString.append(readings.at(i).getMeasurement());
		messageString.append("</measurement>");
		messageString.append("<value>");
		messageString.append(readings.at(i).getValue());
		messageString.append("</value>");
		messageString.append("<unit>");
		messageString.append(readings.at(i).getUnit());
		messageString.append("</unit>");
		messageString.append("</reading>");
	}

	std::cout << messageString << std::endl;

	const char *message = messageString.c_str();

	mg_mgr_init(&mgr, NULL);

	mg_connect_http(
			&mgr,
			ev_handler,
			url,
			"Content-Type: text/plain\r\n",
			message
			);

	mg_mgr_free(&mgr);
}

static void ev_handler(struct mg_connection *c, int ev, void *p) {

	/*
	 * Error handling
	 * A successful connection generates the following events:
	 * MG_EV_POLL, MG_EV_CONNECT, MG_EV_SEND, and MG_EV_CLOSE
	 * If the connection fails MG_EV_SEND is not generated.
	 */

	//std::cout << "Event: " << ev << std::endl;

	static bool data_sent = false;

	if(ev == MG_EV_SEND)
		data_sent = true;

	if(ev == MG_EV_CLOSE && !data_sent) {
		std::cout << "Connection failed, no data sent. Check your URL and make sure the server is online" << std::endl;
		exit(1);
	} else if (ev == MG_EV_CLOSE && data_sent) {
		std::cout << "Data sent" << std::endl;
		data_sent = false;
	}
}

