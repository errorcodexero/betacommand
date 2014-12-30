#include "OI.h"
#include "Commands/HoldMode.h"
#include "Commands/PassBall.h"
#include "Commands/CatchMode.h"
#include "Commands/CollectMode.h"
#include "Commands/PrepareToShoot.h"
#include "Commands/ShootBall.h"
#include "Commands/StopMotors.h"
#include <cstdio>

std::map<OI::ControlMode, OI::ControlMap> OI::driverControlMap = {
    {
	OI::kGamePad,
	{
	    {
		{ OI::kXAxis,        0 },
		{ OI::kYAxis,        1 },
		{ OI::kThrottleAxis, 3 },
		{ OI::kTwistAxis,    4 },
	    },
	    {
		{ OI::kHoldModeButton,       1 },
		{ OI::kPassBallButton,       2 },
		{ OI::kCollectModeButton,    3 },
		{ OI::kCatchModeButton,      4 },
		{ OI::kPrepareToShootButton, 5 },
		{ OI::kShootBallButton,      6 },
	    }
	}
    },
    {
	OI::kFlightStick,
	{
	    {
		{ OI::kXAxis,        0 },
		{ OI::kYAxis,        1 },
		{ OI::kThrottleAxis, 2 },
		{ OI::kTwistAxis,    3 },
	    },
	    {
		{ OI::kShootBallButton,      1 },
		{ OI::kStopMotorsButton,     2 },
		{ OI::kCollectModeButton,    3 },
		{ OI::kCatchModeButton,      4 },
		{ OI::kHoldModeButton,       5 },
		{ OI::kPassBallButton,       6 },
		{ OI::kPrepareToShootButton, 7 },
	    },
	}
    },
};

OI::OI()
{
    stopMotorsButton     = new ControllerButton(this, kDriver, kStopMotorsButton);
    stopMotorsButton->WhenPressed(new StopMotors());

    holdModeButton       = new ControllerButton(this, kDriver, kHoldModeButton);
    holdModeButton->WhenPressed(new HoldMode());

    catchModeButton      = new ControllerButton(this, kDriver, kCatchModeButton);
    catchModeButton->WhenPressed(new CatchMode());

    collectModeButton    = new ControllerButton(this, kDriver, kCollectModeButton);
    collectModeButton->WhenPressed(new CollectMode());

    passBallButton       = new ControllerButton(this, kDriver, kPassBallButton);
    passBallButton->WhileHeld(new PassBall());

    prepareToShootButton = new ControllerButton(this, kDriver, kPrepareToShootButton);
    prepareToShootButton->WhenPressed(new PrepareToShoot());

    shootBallButton      = new ControllerButton(this, kDriver, kShootBallButton);
    shootBallButton->WhenPressed(new ShootBall());
}

OI::~OI()
{
    delete shootBallButton;
    delete prepareToShootButton;
    delete passBallButton;
    delete collectModeButton;
    delete catchModeButton;
    delete holdModeButton;
    delete stopMotorsButton;
}

OI::ControlMode OI::GetControllerType(int stick)
{
    return (DriverStation::GetInstance()->GetStickAxisCount(stick) >= 6)
    		? kGamePad : kFlightStick;
}

float OI::GetX()
{
    int axis = driverControlMap[GetControllerType(0)].axisMap[kXAxis];
    return DriverStation::GetInstance()->GetStickAxis(0, axis);
}

float OI::GetY()
{
    int axis = driverControlMap[GetControllerType(0)].axisMap[kYAxis];
    return DriverStation::GetInstance()->GetStickAxis(0, axis);
}

float OI::GetTwist()
{
    int axis = driverControlMap[GetControllerType(0)].axisMap[kTwistAxis];
    return DriverStation::GetInstance()->GetStickAxis(0, axis);
}

float OI::GetThrottle()
{
    ControlMode mode = GetControllerType(0);
    int axis = driverControlMap[mode].axisMap[kThrottleAxis];
    float throttle = DriverStation::GetInstance()->GetStickAxis(0, axis);
    // flight stick throttle ranges from 1.0 to -1.0;
    // map it to 0.0 to 1.0 range to match game pad
    if (mode == kFlightStick) {
	throttle = (1.0 - throttle) / 2.;
    }
    return throttle;
}

float OI::GetControllerAxis(Controller controller, AxisFunction function)
{
    if (controller == kDriver) {
	int axis = driverControlMap[GetControllerType(0)].axisMap[function];
	return DriverStation::GetInstance()->GetStickAxis(0, axis);
    } else {
	return 0.0;
    }
}

bool OI::GetControllerButton(Controller controller, ButtonFunction function)
{
    if (controller == kDriver) {
	if (driverControlMap[GetControllerType(0)].buttonMap.count(function)) {
	    int button = driverControlMap[GetControllerType(0)].buttonMap[function];
	    return DriverStation::GetInstance()->GetStickButton(0, button);
	}
	// no button mapped to this function on the current controller
	return false;
    } else {
	return false;
    }
}

