#include "OI.h"
#include "Commands/HoldMode.h"
#include "Commands/PassBall.h"
#include "Commands/CatchMode.h"
#include "Commands/CollectMode.h"
#include "Commands/StopShooter.h"
#include "Commands/ShootBall.h"

OI::OI()
{
    driver = new Joystick(0);
    buttonA = new JoystickButton(driver, 1);
    buttonB = new JoystickButton(driver, 2);
    buttonX = new JoystickButton(driver, 3);
    buttonY = new JoystickButton(driver, 4);
    leftButton = new JoystickButton(driver, 5);
    rightButton = new JoystickButton(driver, 6);

    buttonA->WhenPressed(new HoldMode());
    buttonB->WhenPressed(new PassBall());
    buttonX->WhenPressed(new CollectMode());
    buttonY->WhenPressed(new CatchMode());
    leftButton->WhenPressed(new StopShooter());
    rightButton->WhenPressed(new ShootBall());
}

OI::~OI()
{
    delete rightButton;
    delete leftButton;
    delete buttonY;
    delete buttonX;
    delete buttonB;
    delete buttonA;
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
