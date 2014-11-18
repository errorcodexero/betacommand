// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"
#pragma once
#include <WPILib.h>
#include "../Components/RateGyro.h"
#include "../Components/RobotDrive3.h"
#include "../Commands/DriveCommand.h"

// robot drive base with three-wheeled holonomic drive

class DriveBase : public Subsystem {
private:
	SpeedController * m_left;
	SpeedController * m_right;
	SpeedController * m_rear;
	RobotDrive3     * m_drive3;
	RateGyro        * m_gyro;
	uint32_t          m_gyroZero;
	Command         * m_defaultCommand;
	bool              m_started;

public:
	DriveBase( SpeedController *left,
		   SpeedController *right,
		   SpeedController *rear,
		   RateGyro *gyro );

	~DriveBase();

	void InitDefaultCommand();

	void Stop();
	void Start();
	void Drive3( float x, float y, float twist );
};
