#include "AM_MotorSetpoint.h"

AM_MotorSetpoint::AM_MotorSetpoint(double position, PositionUnit position_unit, double speed, SpeedUnit speed_unit)
    : position(position), position_unit(position_unit), speed(speed), speed_unit(speed_unit) {}

void AM_MotorSetpoint::set_speed(double speed)
{
    speed = speed;
}

double AM_MotorSetpoint::get_speed() const
{
    return speed;
}

void AM_MotorSetpoint::set_speed_unit(SpeedUnit speed_unit)
{
    speed_unit = speed_unit;
}

SpeedUnit AM_MotorSetpoint::get_speed_unit() const
{
    return speed_unit;
}

void AM_MotorSetpoint::set_position(double position)
{
    position = position;
}

double AM_MotorSetpoint::get_position() const
{
    return position;
}

void AM_MotorSetpoint::set_position_unit(PositionUnit position_unit)
{
    position_unit = position_unit;
}

PositionUnit AM_MotorSetpoint::get_position_unit() const
{
    return position_unit;
}
