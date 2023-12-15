#include "AM_Servo.h"

AM_Servo::AM_Servo(int motor_pin)
    : servo_pwm_pin(motor_pin),
      _servo()
{
    servo_target_range_us[0] = 1100; // minimum microseconds
    servo_target_range_us[1] = 1900; // maximum microseconds
}
void AM_Servo::_begin()
{
    _servo.attach(servo_pwm_pin); // Still need to call attach in the constructor body
}

void AM_Servo::set_us_range(int min_us, int max_us)
{
    servo_target_range_us[0] = min_us;
    servo_target_range_us[1] = max_us;
}

void AM_Servo::_update()
{
    int current_time = millis();
    if (current_time - last_servo_step_time_ms > servo_step_interval_ms)
    { // time for next step
        last_servo_step_time_ms = current_time;

        // Calculate the remaining distance to the target
        int remaining_distance = servo_target_us - current_position_us;

        // Check if we need to decelerate
        if (abs(remaining_distance) < deceleration_distance)
        {
            // Decelerate by reducing the speed
            current_speed -= acceleration;
        }
        else
        {
            // Accelerate until the max speed is reached
            if (current_speed < max_speed)
            {
                current_speed += acceleration;
            }
        }

        // Ensure the speed does not exceed max_speed or go negative
        current_speed = constrain(current_speed, 0, max_speed);

        // Update the position based on the current speed
        if (remaining_distance < 0)
        {
            current_position_us -= current_speed;
        }
        else
        {
            current_position_us += current_speed;
        }

        // Ensure the position does not exceed the target
        if ((remaining_distance < 0 && current_position_us < servo_target_us) ||
            (remaining_distance > 0 && current_position_us > servo_target_us))
        {
            current_position_us = servo_target_us;
        }

        _servo.writeMicroseconds(current_position_us);
    }
}

void AM_Servo::_set_target(int target)
{
    // Convert the target (0-100) to microseconds range and set the _servo position
    int us = map(target, 0, 100, servo_target_range_us[0], servo_target_range_us[1]);
    servo_target_us = us;
}
