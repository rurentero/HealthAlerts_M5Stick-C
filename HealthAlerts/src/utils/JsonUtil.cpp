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
    Json Parser. Takes key-values from a DynamicJsonDocument and creates the object.
    Source file.
*/

#include "JsonUtil.h"

using namespace org::openapitools::server::src;


Event JsonUtil::parseEvent(DynamicJsonDocument &json){
    Event _event(
        json["params"]["event"]["id"], 
        json["params"]["event"]["title"], 
        json["params"]["event"]["description"], 
        parseInnerLocation((JsonObject) json["params"]["event"]["location"])
        );

    return _event;
}

Location JsonUtil::parseLocation(DynamicJsonDocument &json){
    Location _location(
        json["params"]["location"]["latitude"], 
        json["params"]["location"]["longitude"], 
        json["params"]["location"]["radius"]
        );

    return _location;
}

User JsonUtil::parseUser(DynamicJsonDocument &json){
    User _user(
        json["params"]["user"]["id"], 
        json["params"]["user"]["details"]
        );

    return _user;
}



Event JsonUtil::parseInnerEvent(const JsonObject &json){
    Event _event(json["id"], json["title"], json["description"], parseInnerLocation((JsonObject) json["location"]));

    return _event;
}

Location JsonUtil::parseInnerLocation(const JsonObject &json){
    Location _location(json["latitude"], json["longitude"], json["radius"]);

    return _location;
}

User JsonUtil::parseInnerUser(const JsonObject &json){
    User _user(json["id"], json["details"]);

    return _user;
}



std::vector<Event> JsonUtil::parseEventArray(DynamicJsonDocument &json){
    std::vector<Event> array;
    JsonArray jsonArray = json["params"]["EventArray"];
    for (int i = 0; i < jsonArray.size(); ++i)
    {
        Event item = parseInnerEvent((JsonObject) jsonArray[i]);
        array.push_back(item);
    }
    return array;
}

std::vector<Location> JsonUtil::parseLocationArray(DynamicJsonDocument &json){
    std::vector<Location> array;
    JsonArray jsonArray = json["params"]["LocationArray"];
    for (int i = 0; i < jsonArray.size(); ++i)
    {
        Location item = parseInnerLocation((JsonObject) jsonArray[i]);
        array.push_back(item);
    }
    return array;
}

std::vector<User> JsonUtil::parseUserArray(DynamicJsonDocument &json){
    std::vector<User> array;
    JsonArray jsonArray = json["params"]["UserArray"];
    for (int i = 0; i < jsonArray.size(); ++i)
    {
        User item = parseInnerUser((JsonObject) jsonArray[i]);
        array.push_back(item);
    }
    return array;
}



const char* JsonUtil::serializeEvent(Event &obj){
    String json;
    DynamicJsonDocument doc(capacity);

    
    doc["id"] = obj.getId();
    
    
    doc["title"] = obj.getTitle();
    
    
    doc["description"] = obj.getDescription();
    

    Location _event = obj.getLocation();
    serializeInnerLocation(doc, _event, "location");
    // TODO Arrays?

    serializeJson(doc, json);
    return json.c_str();
}

const char* JsonUtil::serializeLocation(Location &obj){
    String json;
    DynamicJsonDocument doc(capacity);

    
    doc["latitude"] = obj.getLatitude();
    
    
    doc["longitude"] = obj.getLongitude();
    
    
    doc["radius"] = obj.getRadius();
    
    // TODO Arrays?

    serializeJson(doc, json);
    return json.c_str();
}

const char* JsonUtil::serializeUser(User &obj){
    String json;
    DynamicJsonDocument doc(capacity);

    
    doc["id"] = obj.getId();
    
    
    doc["details"] = obj.getDetails();
    
    // TODO Arrays?

    serializeJson(doc, json);
    return json.c_str();
}



void JsonUtil::serializeInnerEvent(DynamicJsonDocument &doc, Event &obj, char* nestedVarName){
    JsonObject aux = doc.createNestedObject(nestedVarName);

    
    aux["id"] = obj.getId();
    
    
    aux["title"] = obj.getTitle();
    
    
    aux["description"] = obj.getDescription();
    

    Location _location = obj.getLocation();
    serializeInnerLocation(doc, _location, "location");

}

void JsonUtil::serializeInnerLocation(DynamicJsonDocument &doc, Location &obj, char* nestedVarName){
    JsonObject aux = doc.createNestedObject(nestedVarName);

    
    aux["latitude"] = obj.getLatitude();
    
    
    aux["longitude"] = obj.getLongitude();
    
    
    aux["radius"] = obj.getRadius();
    

}

void JsonUtil::serializeInnerUser(DynamicJsonDocument &doc, User &obj, char* nestedVarName){
    JsonObject aux = doc.createNestedObject(nestedVarName);

    
    aux["id"] = obj.getId();
    
    
    aux["details"] = obj.getDetails();
    

}



const char* JsonUtil::serializeEventArray(std::vector<Event> &obj){
    String json;
    DynamicJsonDocument doc(capacity);

    for (int i = 0; i < obj.size(); ++i)
    {
        JsonObject doc_I = doc.createNestedObject();
        doc_I["id"] = obj[i].getId();
        
        doc_I["title"] = obj[i].getTitle();
        
        doc_I["description"] = obj[i].getDescription();
        
        
        
        Location aux = obj[i].getLocation();
        serializeInnerLocation(doc, aux, "location");
    }

    serializeJson(doc, json);
    return json.c_str();
}

const char* JsonUtil::serializeLocationArray(std::vector<Location> &obj){
    String json;
    DynamicJsonDocument doc(capacity);

    for (int i = 0; i < obj.size(); ++i)
    {
        JsonObject doc_I = doc.createNestedObject();
        doc_I["latitude"] = obj[i].getLatitude();
        
        doc_I["longitude"] = obj[i].getLongitude();
        
        doc_I["radius"] = obj[i].getRadius();
        
    }

    serializeJson(doc, json);
    return json.c_str();
}

const char* JsonUtil::serializeUserArray(std::vector<User> &obj){
    String json;
    DynamicJsonDocument doc(capacity);

    for (int i = 0; i < obj.size(); ++i)
    {
        JsonObject doc_I = doc.createNestedObject();
        doc_I["id"] = obj[i].getId();
        
        doc_I["details"] = obj[i].getDetails();
        
    }

    serializeJson(doc, json);
    return json.c_str();
}