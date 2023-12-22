#include "AM_PwmOutputPin.h"

// Constructor
AM_PwmOutputPin::AM_PwmOutputPin(int min_us, int max_us)
    : _min_us(min_us), _max_us(max_us), _current_us_value(min_us)
{
    _min_us = 1000;
    _max_us = 2000;
}

// Write a value in microseconds
void AM_PwmOutputPin::write_us(int microseconds)
{
    _current_us_value = constrainValue(microseconds, _min_us, _max_us);
    _write_micros(_current_us_value); // implemented in child classes
}

void AM_PwmOutputPin::write_percents(float percents)
{
    percents = constrain(percents, 0, 100);
    int value = _min_us + (percents * (_max_us - _min_us) / 100f);
    write_us(value);
}

void AM_PwmOutputPin::set_min_max_output_us(int min_us, int max_us)
{
    _min_us = min_us;
    _max_us = max_us;
    write_us(_current_us_value);
}
