class Sensor
{
public:
    virtual void read() = 0;
    virtual ~Sensor() {} // Virtual destructor for polymorphic cleanup
};