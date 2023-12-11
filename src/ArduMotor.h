#ifndef ARDUMOTOR_H
#define ARDUMOTOR_H

#include <Arduino.h>
#include "Motor.h"           // Include the Motor abstract class
#include "ComposedSensors.h" // Include the ComposedSensors class

class ArduMotor
{
public:
    // Constructor
    explicit ArduMotor(Motor *motor) : motor(motor) {}

    // Function to add sensors
    void addSensor(SensorType type, std::unique_ptr<Sensor> sensor)
    {
        composedSensors.addSensor(type, std::move(sensor));
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

    // Delegate sensor reading to ComposedSensors
    void readSensors()
    {
        composedSensors.readSensors();
    }

private:
    Motor *motor;
    ComposedSensors composedSensors;
};

#endif // ARDUMOTOR_H
