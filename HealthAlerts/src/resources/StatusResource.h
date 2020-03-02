/**
 * Health Alerts
 * This application allows users to send and receive information about a user's health condition.
 *
 * OpenAPI spec version: 1.0
 * Contact: info@spilab.es
 *
 * NOTE: This class is auto generated by OpenAPI-Generator unset.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * StatusResource.h
 *
 * 
 */

#ifndef StatusResource_H_
#define StatusResource_H_

// import models
#include "../models/User.h"

// import services
#include "../services/MqttService.h"

// import utils
#include "../utils/JsonUtil.h"

// Temperature sensor
#include <Wire.h>
#include "../utils/DHT12.h"

namespace org {
namespace openapitools {
namespace server {
namespace src {
namespace resources {

using namespace org::openapitools::server::src::models;

class StatusResource {

    MqttService *mqttService;
    DHT12 dht12; 
    char* topicResponse = "HealthAlertsAndroid";

public:
    StatusResource(MqttService *_mqttService);

	void getBodyTemperature (int &sender);
    void getTemperature (int &sender);
    void getUser (int &sender);

};

}
}
}
}
}

#endif /* StatusResource_H_ */

