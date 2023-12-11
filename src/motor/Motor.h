// Abstract base class for Motor
class Motor
{
public:
    virtual void setSpeed(float speed) = 0;
    virtual void setDirection(bool direction) = 0;
    virtual void stop() = 0;
    virtual ~Motor() {} // Virtual destructor for polymorphic cleanup
};