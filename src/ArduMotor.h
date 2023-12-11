#ifndef ARDUMOTOR_H
#define ARDUMOTOR_H

#include <Arduino.h>

class ArduMotor
{
public:
    // Constructor and Destructor
    ArduMotor() {}
    virtual ~ArduMotor() {}

    // Basic motor control functions
    virtual void setSpeed(int speed) = 0;          // Set the motor speed
    virtual void setDirection(bool direction) = 0; // Set the motor direction
    virtual void stop() = 0;                       // Stop the motor

    // Advanced control functions can be added here

    // Functions for integrating with sensors can be added here

    // Add any other common functions that all motor types should have
};

#endif // ArduMotor_h
