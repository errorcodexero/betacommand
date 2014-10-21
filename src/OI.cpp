#include "OI.h"

OI::OI()
{
    driver = new Joystick(0);
}

OI::~OI()
{
    delete driver;
}

float OI::GetX()
{
    return driver->GetX();
}

float OI::GetY()
{
    return driver->GetY();
}

float OI::GetTwist()
{
    return driver->GetTwist();
}

float OI::GetThrottle()
{
    return driver->GetThrottle();
}
