# C/C++ (Arduino) API client

This application allows users to send and receive information about a user's health condition.

## Overview
This API client was generated by the [OpenAPI Generator](https://openapi-generator.tech) project. By using the [OpenAPI spec](https://openapis.org) from a remote server, you can easily generate an API client.

- API version: 1.0
- Package version: 
- Build package: org.openapitools.codegen.languages.Esp32Microcontroller
For more information, please visit [https://spilab.es](https://spilab.es)

- API namespace: org.openapitools.server.src.resources
- Model namespace: org.openapitools.server.src.models

## Installation

### Prerequisites

Install [Arduino IDE] via (https://www.arduino.cc/en/main/software).

### Build

- If you are using Arduino IDE, place your project in your "Arduino" folder (located in Documents/Arduino by default) along with your installed libraries.
- Unpack "Esp32Microcontroller-server" content inside a folder with the same name as main program:
    - ./Arduino
        - Esp32_MQTT
            - Esp32_MQTT.ino
            - src
            - README.md
            - libraries
- Install required Arduino Libraries:
    - WiFi
    - PubSubClient
    - ArduinoJson
- Main sketch have some TODOs you have to complete before running the code (e.g: WiFi and MQTT configuration or changes in the import statements).
- Build and program your Esp32 microcontroller via Arduino IDE.

## Important notes

- This API is generated for M5StickC Microcontroller (Esp32). It works with other versions of Esp32 Microcontroller, just comment or delete M5StickC library and those methods that use it.
- Because it uses MQTT, you need to host a broker where the messages will be sent. Also, it is recommended to implement a client which will send requests.
    A common request is something like the following JSON:
        {
        "resource": "Event",
            "method": "postEvent",
            "sender": "1",
            "params": {
                "event": {
                "id": 1,
                "title": "Football Match!",
                "description": "Football Match at 11:00 in City Soccer Stadium",
                    "location":{
                        "latitude": 38.514377,
                        "longitude":-6.844325,
                        "radius": 200
                    }
                }
            }
        }

## Author

info@spilab.es

