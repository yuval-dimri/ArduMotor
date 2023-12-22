#ifndef AM_SENSOR_H
#define AM_SENSOR_H

#include <Arduino.h>

class AM_Sensor
{
public:
    AM_Sensor();

    // Method to initialize the sensor
    void begin();

    // Method to read the current value from the sensor
    double readValue();

    // Method to check if the sensor is operational
    bool isOperational();

private:
    double sensorValue;
    bool operationalStatus;

    // Private method to update sensor data
    void updateSensorData();
};

#endif // AM_SENSOR_H
