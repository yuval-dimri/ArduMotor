#ifndef AM_MOTOROPERATOR_H
#define AM_MOTOROPERATOR_H

#include "Units.h"

class AM_MotorOperator
{
public:
    AM_MotorOperator(AM_motor motor, AM_Units target_units, AM_Units speed_units);

private:
    AM_Units target_units;
    AM_Units speed_units;

    unsigned long last_set_target_time;

    void begin(),
        update(),
        set_target(int target, int speed, int timeout);
};

#endif // AM_MOTOROPERATOR_H
