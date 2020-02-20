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



#include "Location.h"

namespace org {
namespace openapitools {
namespace server {
namespace src {
namespace models {

//Constructors
Location::Location()
{
    latitude = 0.0;
    longitude = 0.0;
    radius = 0.0;
}
Location::Location(double _latitude, double _longitude, double _radius)
{
    latitude = _latitude;
    longitude = _longitude;
    radius = _radius;
}

// Setters & Getters
double Location::getLatitude()
{
    return latitude;
}

void Location::setLatitude(double value)
{
    latitude = value;
}

double Location::getLongitude()
{
    return longitude;
}

void Location::setLongitude(double value)
{
    longitude = value;
}

double Location::getRadius()
{
    return radius;
}

void Location::setRadius(double value)
{
    radius = value;
}


}
}
}
}
}

