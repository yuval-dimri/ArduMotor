#ifndef ARDUMOTOR_H
#define ARDUMOTOR_H

#include <Arduino.h>
#include <memory>
#include "Motor.h" // Include the Motor abstract class
#include "ComposedSensors.h"
#include "SensorType.h"

class ArduMotor
{
public:
    // Constructor
    explicit ArduMotor(Motor &motor);

    // Function to add sensors
    void addSensor(sensor &sensor);

    // Motor control methods
    void motorGo(float speed);                     // -1 - 1
    void motorGo(float speed, float acceleration); // -1 - 1, rot / s^2

    void stopMotor();

    // Delegate sensor reading to ComposedSensors
    void readSensors();

private:
    Motor *motor;
    ComposedSensors composedSensors;
};

#endif // ARDUMOTOR_H
