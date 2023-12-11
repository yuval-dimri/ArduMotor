#ifndef SPEEDUNITS_H
#define SPEEDUNITS_H

#include <Arduino.h>

enum class RotarySpeedUnit
{
    RPM,
    DEGREES_PER_SECOND,
};

enum class LinearSpeedUnit
{
    METERS_PER_SECOND,
    CM_PER_SECOND,
    FEET_PER_SECOND,
    INCHES_PER_SECOND
};

// Abstract Base Class
class Speed
{
public:
    float getValue() const { return value; }

protected:
    float value;
};

// Derived Class for Rotary Speed
class RotarySpeed : public Speed
{
public:
    RotarySpeed(float value, RotarySpeedUnit unit) : Speed(value), unit(unit) {}

    RotarySpeedUnit getUnit() const { return unit; }

private:
    RotarySpeedUnit unit;
};

// Derived Class for Linear Speed
class LinearSpeed : public Speed
{
public:
    LinearSpeed(float value, LinearSpeedUnit unit) : Speed(value), unit(unit) {}

    LinearSpeedUnit getUnit() const { return unit; }

private:
    LinearSpeedUnit unit;
};

#endif // SPEEDUNITS_H