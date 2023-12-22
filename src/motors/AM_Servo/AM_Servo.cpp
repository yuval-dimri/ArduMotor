#include "AM_Servo.h"

AM_Servo::AM_Servo(AM_PwmOutputPin &pwm_output)
    : _pwm_output(pwm_output),
      _controller()
{
}

AM_Servo::_init()
{
    _pwm_output.init();
    _controller.init();
}

void AM_Servo::write_percents(float percents)
{
    _controller.set_percents(percents);
}

void AM_Servo::set_min_max_output_us(int min_us, int max_us)
{
    _min_us = min_us;
    _max_us = max_us;
}

void AM_Servo::update()
{
    _output_percents = _controller.update(_setpoint);
    _pwm_output.write_percents(_output_percents)
}
