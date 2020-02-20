/**
 * HealthAlerts
 * 
 *
 *
 * NOTE: This class is auto generated by OpenAPI-Generator .
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#include <WiFi.h>
#include <PubSubClient.h>
// TODO If you are going to send and receive packages larger than 128B, MQTT_MAX_PACKET_SIZE needs to be changed in PubSubClient.h library. MQTT Max message size is 128B by default.
#include <M5StickC.h>
#include <ArduinoJson.h>

// import utils
#include "./src/utils/JsonUtil.h"

// import services
#include "./src/services/MqttService.h"

// import resources
#include "./src/resources/EventResource.h"
#include "./src/resources/StatusResource.h"

// import models
// TODO Change the relative path "../models/*" to "./src/models/*"
#include "./src/models/Event.h"
#include "./src/models/User.h"

using namespace org::openapitools::server::src::models;
using namespace org::openapitools::server::src::resources;

// TODO Put here the SSID and Password of your Wifi Network. MQTT server IP and port (default 1883). MQTT User and password if needed.
const char* ssid = "Gloin";
const char* password = "Gloin2014";
const char* mqttServer = "192.168.0.131";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

WiFiClient espClient;
PubSubClient client(espClient);

// declare and initialize MqttService
PubSubClient *clientPtr = &client;
MqttService mqttService(clientPtr);

// declare resource controllers
MqttService *mqttServicePtr = &mqttService;
EventResource EventResourceController(mqttServicePtr);
StatusResource StatusResourceController(mqttServicePtr);

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");

    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);

    while (!client.connected()) {
        Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
            Serial.println("connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }

    // Subscribe to topic
    // TODO Define here the topics you are going to subscribe to
    client.subscribe("mytopic/test");

    // Initialize the M5StickObject (for LCD notifications)
    // TODO comment the line below if you don't use the LCD.
    M5.begin();
    Wire.begin(0,26);
}

// ---- Function invoked every time a new message arrives to the topic.
void callback(char* topic, byte* payload, unsigned int length) {
    // PubSub Tasks
    Serial.print("MQTT. Message arrived in topic: ");
    Serial.println(topic);

    Serial.print("MQTT. Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();

    //Deserialize Json. Json stored in "doc" variable.
    Serial.println("Deserializating JSON");
    // Calculate your estimated Json capacity. If you don't know what capacity you should use, just use "lenght" (as parameter in this callback method) instead of "capacity"
    const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(3) + 2*JSON_OBJECT_SIZE(4) + 200;
    DynamicJsonDocument doc(capacity);
    DeserializationError err = deserializeJson(doc, payload, length);
    if (err) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(err.c_str());
    }

    Serial.print(F("Resource Type: "));
    const char* resource = doc["resource"];
    Serial.println(resource);
    Serial.print(F("Method: "));
    const char* method_ = doc["method"];
    Serial.println(method_);
    Serial.print(F("Sender ID: "));
    int sender = doc["sender"];
    Serial.println(sender);

    //----Resource selector
    if (strcmp(resource,"Event")==0) { 
        notify("New notification: Event");
        // Retrieve the received object from JSON.
        //Event _Event = JsonUtil::parseEvent(doc);

        //----Method selector
            if (strcmp(method_,"postEvent")==0) { 
                
                Event _event = JsonUtil::parseEvent(doc);
                
                
                EventResourceController.postEvent(_event,  sender);
            }
            else { // Default
                Serial.println("Resource method not supported.");
                mqttService.sendResponse("mytopic/testResponse","API Method not supported.");
            }

    }
    else if (strcmp(resource,"Status")==0) { 
        notify("New notification: Status");
        // Retrieve the received object from JSON.
        //Status _Status = JsonUtil::parseStatus(doc);

        //----Method selector
            if (strcmp(method_,"getUser")==0) { 
                
                
                StatusResourceController.getUser( sender);
            }
            else if (strcmp(method_,"getTemperature")==0) { 
                
                
                StatusResourceController.getTemperature( sender);
            }
            else { // Default
                Serial.println("Resource method not supported.");
                mqttService.sendResponse("mytopic/testResponse","API Method not supported.");
            }

    }
    else {  //Default
        Serial.println("API resource not supported.");
        mqttService.sendResponse("mytopic/testResponse","API Resource not supported.");
    }
    Serial.println("-----------------------");
}

void loop() {
    // MQTT listener
    client.loop();
    // wait for push button 
    if(digitalRead(M5_BUTTON_HOME) == LOW){ 
      while(digitalRead(M5_BUTTON_HOME) == LOW); 
      EventResourceController.sendAlert();
      printAlert();
    }
    // wait for push button
    if(digitalRead(M5_BUTTON_RST) == LOW){ 
      while(digitalRead(M5_BUTTON_RST) == LOW); 
      M5.Lcd.fillScreen(BLACK);
    }

    
}

// ---- M5StickC Utils
void notify(char* msg){
    // Show notification in LCD. M5 must be initialized.
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 10);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(1);
    M5.Lcd.printf(msg);
    M5.Lcd.fillCircle(40, 80, 30, BLUE);
}

void printAlert(){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 10);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(1);
    M5.Lcd.printf("Alert sent!");
    M5.Lcd.fillCircle(40, 80, 30, RED);
}
