#ifndef ARDUMOTOR_H
#define ARDUMOTOR_H

#include <Arduino.h>
#include "AM_MotorOperator.h"
#include "sensors/AM_Sensor.h" // Assuming am_sensor.h is in the same directory

class ArduMotor
{
public:
    // Constructor
    ArduMotor(AM_MotorOperator &motor_operator);

    // Function to add sensors
    void add_sensor(AM_Sensor &sensor);

    // Motor control methods
    void set_target(int target);
    void set_target(int target, int speed);
    void set_target(int target, int speed, unsigned int timeout);

    void stop_motor();

    // Delegate sensor reading to composed_sensors
    void read_sensors();

private:
    AM_MotorOperator &motor_operator; // Using reference as passed in constructor
    AM_Sensor sensor;                 // Assuming ComposedSensors is a type managing multiple sensors
};

#endif // ARDUMOTOR_H
