#include <Adafruit_PWMServoDriver.h>

AM_PwmOutputPin_PCA9685::AM_PwmOutputPin_PCA9685(Adafruit_PWMServoDriver &pwm_driver, uint8_t pin)
    : _pwm_driver(driver), _pin(pin)
{
    _isAdafruitPwm = true;
}

void AM_PwmOutputPin_PCA9685::init()
{
    // for now, should be initialised outside!
}

void AM_PwmOutputPin_PCA9685::_write_us(uint16_t microseconds)
{
    _pwm_driver.writeMicroseconds(_pin, microseconds)
}

void AM_PwmOutputPin_PCA9685::_digital_write(bool value)
{
    if (value)
        _pwm_driver.setPWM(_pin, 4096, 0); // turns pin fully on
    else
        _pwm_driver.setPWM(_pin, 0, 4096); // turns pin fully off
}
