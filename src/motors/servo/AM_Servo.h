#ifndef AM_SERVO_H
#define AM_SERVO_H

#include <Servo.h>         // Include the Servo library if you're using the standard Arduino Servo library
#include "MotorOperator.h" // Include the base class

class AM_Servo : public AM_MotorOperator
{
public:
    AM_Servo(int motor_pin);

    /*
    set min - max microseconds value for the servo movement
    will map to a target of 0 - 100
    */
    set_us_range(int min_us, int max_us);

private:
    Servo servo;
    int servo_pwm_pin;
    int servo_target_range_us[2];

    int servo_target_us;
    int servo_step_interval_ms;
    int last_servo_step_time_ms;
    int servo_acceleration;

    void
    _begin();
    void _update();
    void _set_target(int target);
};

#endif // AM_SERVO_H
