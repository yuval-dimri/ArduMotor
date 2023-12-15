#ifndef SPEEDUNITS_H
#define SPEEDUNITS_H

#include <Arduino.h>

enum class SpeedUnits
{
    RPM,
    DEGREES_PER_SECOND,
    METERS_PER_SECOND,
    KILOMETERS_PER_HOUR,
    MILES_PER_HOUR,
    FEET_PER_SECOND,
    KNOTS, // Nautical miles per hour
    MACH   // Speed relative to the speed of sound ha ha ha
};

enum class PositionUnits
{
    MM,
    CM,
    METER,
    KILOMETER,
    INCHE,
    FEET,
    MILE,
};

class AM_Units
{
public:
    AM_SpeedUnit(float value, PositionUnits position_unit);
    AM_SpeedUnit(float value, SpeedUnits speed_units);

protected:
    float value;
};

class AM_SpeedUnit
{
public:
    AM_SpeedUnit(float value, SpeedUnit unit);
    AM_

        protected : float value;
};

class AM_PositionUnit
{
public:
    AM_SpeedUnit(float value, RotarySpeedUnit unit);

protected:
    float value;
};

#endif // SPEEDUNITS_H