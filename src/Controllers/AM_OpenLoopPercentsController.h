#ifndef OPENLOOPPERCENTSCONTROLLER_H
#define OPENLOOPPERCENTSCONTROLLER_H

class OpenLoopPercentsController
{
public:
    /*
    max_speed: percents / second
    smoothing: % of movement to spend on acceleration and deceleration
    */
    OpenLoopPercentsController(int max_speed, float smoothing);
    void set_percents(float percents);
    float update();

private:
    float _setpoint;
    float _distance_to_setpoint;
    float _current_percents;

    unsigned int _current_movement_duration;
    unsigned long _time_to_reach_setpoint;

    float _maxSpeed;
    float _smoothing;
    float _speed;
};

#endif // OPENLOOPPERCENTSCONTROLLER_H
