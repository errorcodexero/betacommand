#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driver;

public:
	OI();
	~OI();
	float GetX();
	float GetY();
	float GetTwist();
	float GetThrottle();
};

#endif
