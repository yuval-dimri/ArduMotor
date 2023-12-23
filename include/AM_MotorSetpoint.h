#ifndef AM_MOTORSETPOINT_H
#define AM_MOTORSETPOINT_H

#include <Arduino.h>

enum SpeedUnit
{
    RPM,
    DEGREES_PER_SECOND,
    METERS_PER_SECOND,
    KILOMETERS_PER_HOUR,
    MILES_PER_HOUR,
    FEET_PER_SECOND,
    KNOTS, // Nautical miles per hour
    MACH   // Speed relative to the speed of sound
};

enum PositionUnit
{
    MM,
    CM,
    METER,
    KILOMETER,
    INCH,
    FEET,
    MILE,
};

class AM_MotorSetpoint
{
public:
    AM_MotorSetpoint(double position, PositionUnit position_unit, double speed, SpeedUnit speed_unit);

    // Setters and Getters for position
    void set_position(double position);
    double get_position() const;
    void set_position_unit(PositionUnit pos_unit);
    PositionUnit get_position_unit() const;

    // Setters and Getters for speed
    void set_speed(double speed);
    double get_speed() const;
    void set_speed_unit(SpeedUnit speed_unit);
    SpeedUnit get_speed_unit() const;

private:
    double speed;
    double position;
    SpeedUnit speed_unit;
    PositionUnit position_unit;
};

#endif // AM_MOTORSETPOINT_H
