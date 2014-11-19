// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include "WPILib.h"

class OI
{
private:
	Joystick *driver;
	JoystickButton *buttonA;
	JoystickButton *buttonB;
	JoystickButton *buttonX;
	JoystickButton *buttonY;
	JoystickButton *leftButton;
	JoystickButton *rightButton;

public:
	OI();
	~OI();
	float GetX();
	float GetY();
	float GetTwist();
	float GetThrottle();
};
