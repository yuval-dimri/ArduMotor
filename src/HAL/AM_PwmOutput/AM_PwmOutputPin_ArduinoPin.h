#ifndef ADAFRUIT_PWM_OUTPUT_PIN_H
#define ADAFRUIT_PWM_OUTPUT_PIN_H

#include "AM_PwmOutputPin.h"
#include <Servo.h>

class AM_PwmOutputPin_ArduinoPin : public AM_PwmOutputPin
{
public:
    AM_PwmOutputPin_ArduinoPin(Servo &servo, uint8_t pin);

    void init() override;

private:
    Servo &_servo;

    void _write_micros(uint16_t microseconds) override;
    void _digital_write(bool value) override;
};

#endif // ADAFRUIT_PWM_OUTPUT_PIN_H
