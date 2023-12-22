#include "AM_MotorOperator.h"

AM_MotorOperator::AM_MotorOperator()
{
}

void AM_MotorOperator::begin()
{
    _begin();
}

void AM_MotorOperator::update()
{
    unsigned long current_time = millis();
    if (current_time - last_set_target_time >= timeout_duration_ms)
    {
        _on_timeout_reached();
    }
}

void AM_MotorOperator::set_target(int target, int speed, int timeout_ms)
{
    // Set the target position, speed, and timeout for the motor operation
    last_set_target_time = millis(); // Assuming millis() returns the current time in milliseconds
    timeout_duration_ms = timeout_ms;

    motor_setpoint_target.setValue(target);

    // Record the time when the target was set

    // Additional code to handle the motor operation based on the new target and speed
}

// If there are any other member functions or utility functions, they should be implemented here.
