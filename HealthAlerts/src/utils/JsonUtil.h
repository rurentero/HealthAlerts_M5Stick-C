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
    Json Parser. Converts and create objects from DynamicJsonDocument to a specific object defined in OpenAPI.
    This class only parses objects used in the field "params": "parse" methods recover objects directly from the field "params",
    while "parseInner" methods recover nested objects.

    This class hightly depends on ArduinoJson library from Arduino.
    Header file.
*/

#ifndef ORG_OPENAPITOOLS_SERVER_SRC_MODELS__H_
#define ORG_OPENAPITOOLS_SERVER_SRC_MODELS__H_

#include <Arduino.h>
#include <ArduinoJson.h>

#include "../models/Event.h"
#include "../models/Location.h"
#include "../models/User.h"

using namespace org::openapitools::server::src::models;

class JsonUtil {
    // Properties:
    static const size_t capacity = 1024; //Change accordingly to your data.
    // Methods
    public:
        // Parsing methods
    
        static Event parseEvent(DynamicJsonDocument &json);
        static Location parseLocation(DynamicJsonDocument &json);
        static User parseUser(DynamicJsonDocument &json);
    
        static Event parseInnerEvent(const JsonObject &json);
        static Location parseInnerLocation(const JsonObject &json);
        static User parseInnerUser(const JsonObject &json);
    
        static std::vector<Event> parseEventArray(DynamicJsonDocument &json);
        static std::vector<Location> parseLocationArray(DynamicJsonDocument &json);
        static std::vector<User> parseUserArray(DynamicJsonDocument &json);

        // Serializing methods
    
        static const char* serializeEvent(Event &obj);
        static const char* serializeLocation(Location &obj);
        static const char* serializeUser(User &obj);
    
        static void serializeInnerEvent(DynamicJsonDocument &json, Event &obj, char* nestedVarName);
        static void serializeInnerLocation(DynamicJsonDocument &json, Location &obj, char* nestedVarName);
        static void serializeInnerUser(DynamicJsonDocument &json, User &obj, char* nestedVarName);
    
        static const char* serializeEventArray(std::vector<Event> &obj);
        static const char* serializeLocationArray(std::vector<Location> &obj);
        static const char* serializeUserArray(std::vector<User> &obj);

    private:
        // Disallow creating an instance of this object
        JsonUtil() {};
};

#endif /* ORG_OPENAPITOOLS_SERVER_SRC_MODELS__H_ */