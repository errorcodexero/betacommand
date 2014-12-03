// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include "WPILib.h"

#define FLIGHTSTICK

class OI
{
private:
	Joystick *driver;

#ifdef GAMEPAD
	JoystickButton *buttonA;
	JoystickButton *buttonB;
	JoystickButton *buttonX;
	JoystickButton *buttonY;
	JoystickButton *leftButton;
	JoystickButton *rightButton;
#endif

#ifdef FLIGHTSTICK
	JoystickButton *button1;
	JoystickButton *button2;
	JoystickButton *button3;
	JoystickButton *button4;
	JoystickButton *button5;
	JoystickButton *button6;
	// JoystickButton *button7;
#endif

public:
	OI();
	~OI();
	float GetX();
	float GetY();
	float GetTwist();
	float GetThrottle();
};
