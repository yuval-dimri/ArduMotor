#ifndef COMPOSEDSENSORS_H
#define COMPOSEDSENSORS_H

#include <unordered_map>
#include <memory>
#include "Sensor.h" // Include the Sensor abstract class

enum class SensorType
{
    ENCODER,
    LIMIT_SWITCH,
    // ... other sensor types
};

class ComposedSensors
{
public:
    void addSensor(SensorType type, std::unique_ptr<Sensor> sensor)
    {
        sensors[type] = std::move(sensor);
    }

    void readSensors()
    {
        for (auto &pair : sensors)
        {
            pair.second->read();
        }
    }

    // ... other methods as needed ...

private:
    std::unordered_map<SensorType, std::unique_ptr<Sensor>> sensors;
};

#endif // COMPOSEDSENSORS_H
