#ifndef AM_MOTOROPERATOR_H
#define AM_MOTOROPERATOR_H

#include "AM_Setpoint.h"

class AM_Motor
{
public:
    AM_Motor();

private:
    AM_MotorSetpoint target_units;

    unsigned long last_set_target_time;
    unsigned int timeout_duration_ms;

    void begin();
    void update();
    void set_target(int target, int speed, int timeout_ms);

    void _on_timeout_reached();
};

#endif // AM_MOTOROPERATOR_H
