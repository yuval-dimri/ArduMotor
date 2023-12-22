#ifndef ADAFRUIT_PWM_OUTPUT_PIN_H
#define ADAFRUIT_PWM_OUTPUT_PIN_H

#include "AM_PwmOutputPin.h"
#include <Adafruit_PWMServoDriver.h>

class AdafruitPwmOutputPin : public AM_PwmOutputPin
{
public:
    AdafruitPwmOutputPin(Adafruit_PWMServoDriver &driver, uint8_t pin);

    void init() override;

private:
    Adafruit_PWMServoDriver &_pwm_driver;

    void _write_micros(uint16_t microseconds) override;
    void _digital_write(bool value) override;
};

#endif // ADAFRUIT_PWM_OUTPUT_PIN_H
