#include "OI.h"
#include "Commands/HoldMode.h"
#include "Commands/PassBall.h"
#include "Commands/CatchMode.h"
#include "Commands/CollectMode.h"
#include "Commands/PrepareToShoot.h"
#include "Commands/ShootBall.h"
#include "Commands/StopMotors.h"

OI::OI()
{
    driver = new Joystick(0);

#ifdef GAMEPAD
    buttonA = new JoystickButton(driver, 1);
    buttonB = new JoystickButton(driver, 2);
    buttonX = new JoystickButton(driver, 3);
    buttonY = new JoystickButton(driver, 4);
    leftButton = new JoystickButton(driver, 5);
    rightButton = new JoystickButton(driver, 6);

    buttonA->WhenPressed(new HoldMode());
    buttonB->WhileHeld(new PassBall());
    buttonX->WhenPressed(new CollectMode());
    buttonY->WhenPressed(new CatchMode());
    leftButton->WhenPressed(new PrepareToShoot());
    rightButton->WhenPressed(new ShootBall());
#endif

#ifdef FLIGHTSTICK
    button1 = new JoystickButton(driver, 1);	// trigger
    button2 = new JoystickButton(driver, 2);
    button3 = new JoystickButton(driver, 3);
    button4 = new JoystickButton(driver, 4);
    button5 = new JoystickButton(driver, 5);
    button6 = new JoystickButton(driver, 6);
    // button7 = new JoystickButton(driver, 7);

    button1->WhenPressed(new ShootBall());
    button2->WhenPressed(new StopMotors());
    button3->WhenPressed(new CollectMode());
    button4->WhenPressed(new CatchMode());
    button5->WhenPressed(new HoldMode());
    button6->WhileHeld(new PassBall());
    // button7->WhenPressed(new PrepareToShoot());
#endif
}

OI::~OI()
{
#ifdef GAMEPAD
    delete rightButton;
    delete leftButton;
    delete buttonY;
    delete buttonX;
    delete buttonB;
    delete buttonA;
#endif
#ifdef FLIGHTSTICK
    // delete button7;
    delete button6;
    delete button5;
    delete button4;
    delete button3;
    delete button2;
    delete button1;
#endif
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
#ifdef GAMEPAD
    return driver->GetRawAxis(4);
#endif
#ifdef FLIGHTSTICK
    return driver->GetRawAxis(3);
#endif
}

float OI::GetThrottle()
{
#ifdef GAMEPAD
    return driver->GetThrottle();
#endif
#ifdef FLIGHTSTICK
    return (1.0 - driver->GetRawAxis(2)) / 2.;
#endif
}
