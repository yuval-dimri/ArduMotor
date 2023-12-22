#ifndef COMPOSEDSENSORS_H
#define COMPOSEDSENSORS_H

#include <memory>
#include "AM_Sensor.h" // Include the Sensor abstract class

enum class SensorType
{
    ENCODER,
    LIMIT_SWITCH,
};

class AM_Sensor
{
public:
    AM_Sensor();

    void addSensor(SensorType type, std::unique_ptr<Sensor> sensor);
    void readSensors();

private:
};

#endif // COMPOSEDSENSORS_H
