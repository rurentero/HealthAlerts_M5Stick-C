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
 * Location.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_SERVER_SRC_MODELS_Location_H_
#define ORG_OPENAPITOOLS_SERVER_SRC_MODELS_Location_H_

#include <Arduino.h>


namespace org {
namespace openapitools {
namespace server {
namespace src {
namespace models {

/// <summary>
/// 
/// </summary>
class  Location {
    // Properties
    double latitude;
    double longitude;
    double radius;

    public:
        // Constructor
        Location();
        Location( double _latitude,  double _longitude,  double _radius);

        /////////////////////////////////////////////
        /// Location members

        /// <summary>
        /// 
        /// </summary>
        double getLatitude();
        void setLatitude(double value);

        /// <summary>
        /// 
        /// </summary>
        double getLongitude();
        void setLongitude(double value);

        /// <summary>
        /// 
        /// </summary>
        double getRadius();
        void setRadius(double value);


};

}
}
}
}
}

#endif /* ORG_OPENAPITOOLS_SERVER_SRC_MODELS_Location_H_ */
