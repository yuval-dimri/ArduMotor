#ifndef AM_SERVO_H
#define AM_SERVO_H

#include <Servo.h>
#include "AM_Motor.h"
#include "AM_PwmOutputPin.h"
#include "AM_OpenLoopPercentsController.h"
#include "AM_MotorSetpoint.h"

class AM_Servo : public AM_Motor
{
public:
    AM_Servo(AM_PwmOutputPin &pwm_output);
    void write_percents(float percents);
    void set_min_max_output_us(int min_us, int max_us);

    void update();

private:
    AM_PwmOutputPin &_pwm_output;
    AM_OpenLoopPercentsController _controller;
    float _output_percents;
};

#endif // AM_SERVO_H