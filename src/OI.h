// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include "WPILib.h"
#include "GenericHID.h"
#include "Buttons/Button.h"
#include <map>

class ControllerButton;

class OI
{
public:
    OI();
    ~OI();

    typedef enum { kDriver, kGunner } Controller;
    typedef enum { kGamePad, kFlightStick } ControlMode;
    typedef enum { kXAxis, kYAxis, kTwistAxis, kThrottleAxis } AxisFunction;
    typedef enum { kStopMotorsButton, kHoldModeButton, kCatchModeButton, kCollectModeButton,
		   kPassBallButton, kPrepareToShootButton, kShootBallButton } ButtonFunction;

    ControlMode GetControllerType(int stick);

    float GetControllerAxis(Controller controller, AxisFunction function);
    bool GetControllerButton(Controller controller, ButtonFunction function);

    float GetX();
    float GetY();
    float GetTwist();
    float GetThrottle();

private:
    typedef struct {
	std::map< AxisFunction, int > axisMap;
	std::map< ButtonFunction, int > buttonMap;
    } ControlMap;

    static std::map< ControlMode, ControlMap > driverControlMap;

    ControllerButton *stopMotorsButton;
    ControllerButton *holdModeButton;
    ControllerButton *catchModeButton;
    ControllerButton *collectModeButton;
    ControllerButton *passBallButton;
    ControllerButton *prepareToShootButton;
    ControllerButton *shootBallButton;
};

class ControllerButton : public Button
{
private:
    OI *m_oi;
    OI::Controller m_controller;
    OI::ButtonFunction m_function;

public:
    ControllerButton(OI *oi, OI::Controller controller, OI::ButtonFunction function) :
	m_oi(oi),
	m_controller(controller),
	m_function(function)
    {
	;
    }

    virtual ~ControllerButton() {}

    virtual bool Get() {
	return m_oi->GetControllerButton(m_controller, m_function);
    }
};

