#include "OpenLoopPercentsController.h"

OpenLoopPercentsController::OpenLoopPercentsController(int maxSpeed, float smoothing)
    : _max_speed(max_speed), _smoothing(smoothing)
{
}

void OpenLoopPercentsController::set_goal(float percents)
{
    _setpoint = constrain(percents, 0, 1);
    _distance_to_setpoint = _setpoint - _current_percents;
    _current_movement_duration = _distance_to_setpoint / (_max_speed / 100f);

    set_goal(percents, _current_movement_duration);
}

void OpenLoopPercentsController::set_goal(float percents, unsigned int duration)
{
    _setpoint = constrain(percents, 0, 1);
    _current_movement_duration = _distance_to_setpoint / (_max_speed / 100f);
    _time_to_reach_setpoint = millis() + _current_movement_duration;
}

float OpenLoopPercentsController::update()
{

    float distance = _setpoint - _current_percents;
    float direction = distance > 0 ? 1 : -1;
}
