#ifndef ARDUMOTOR_H
#define ARDUMOTOR_H

#include <Arduino.h>
#include <vector>
#include "Motor.h"  // Define a common motor interface
#include "Sensor.h" // Define a common sensor interface

class ArduMotor
{
public:
    // Constructors
    ArduMotor(Motor *motor) : motor(motor) {}

    // Add a sensor to the ArduMotor
    void addSensor(Sensor *sensor)
    {
        sensors.push_back(sensor);
    }

    // Motor control methods
    void setSpeed(float speed)
    {
        motor->setSpeed(speed);
    }
    void setDirection(bool direction)
    {
        motor->setDirection(direction);
    }
    void stopMotor()
    {
        motor->stop();
    }

    // Sensor interaction methods
    void readSensors()
    {
        for (auto &sensor : sensors)
        {
            sensor->read();
        }
    }

    // ... Other methods as needed ...

private:
    Motor *motor;                  // Motor interface
    std::vector<Sensor *> sensors; // Collection of sensor interfaces
};

#endif // ARDUMOTOR_H
