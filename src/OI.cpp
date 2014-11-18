#include "OI.h"
#include "Commands/HoldMode.h"
#include "Commands/PassBall.h"
#include "Commands/CatchMode.h"
#include "Commands/CollectMode.h"

OI::OI()
{
    driver = new Joystick(0);
    buttonA = new JoystickButton(driver, 0);
    buttonB = new JoystickButton(driver, 1);
    buttonX = new JoystickButton(driver, 2);
    buttonY = new JoystickButton(driver, 3);

    buttonA->WhenPressed(new HoldMode());
    buttonB->WhenPressed(new PassBall());
    buttonX->WhenPressed(new CatchMode());
    buttonY->WhenPressed(new CollectMode());
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
 // return driver->GetTwist();
    return driver->GetRawAxis(4);
}

float OI::GetThrottle()
{
    return driver->GetThrottle();
}
