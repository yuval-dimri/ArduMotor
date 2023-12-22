#ifndef AM_PWM_OUTPUT_H
#define AM_PWM_OUTPUT_H

#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

class AM_PwmOutputPin
{
public:
    virtual void init() = 0;

    void write_us(uint16_t microseconds);
    void write_percents(uint16_t percents);
    void set_min_max_output_us(uint16_t min_us, uint16_t max_us);

private:
    uint16_t _current_us_value;
    uint16_t _min_us;
    uint16_t _max_us;

    uint16_t _pin;
    virtual void _write_micros(uint16_t microseconds) = 0;
    virtual void _digital_write(bool value) = 0;
};

#endif // AM_PWM_OUTPUT_H
