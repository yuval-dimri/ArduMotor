#include "Adafruit_PWM_Output_Pin.h"

AM_PwmOutputPin_ArduinoPin::AM_PwmOutputPin_ArduinoPin(Servo &servo, uint8_t pin)
    : _servo(servo), _pin(pin)
{
    _servo.attach(_pin);
}

void AM_PwmOutputPin_ArduinoPin::_write_micros(uint16_t microseconds)
{
    _servo.writeMicroseconds(microseconds);
}

void AM_PwmOutputPin_ArduinoPin::_digital_write(bool value)
{
    _servo.detach(_pin);
    pinMode(_pin, output);

    digitalWrite(_pin, value);
}
