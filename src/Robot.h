// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include "WPILib.h"
#include "Commands/Command.h"
#include "OI.h"
#include "Components/TwoMotor.h"
#include "Components/RateGyro.h"
#include "Components/SlowSolenoid.h"
#include "Components/Tachometer.h"
#include "Components/TwoMotor.h"
#include "Subsystems/DriveBase.h"

#ifndef _ROBOT_H_
#define _ROBOT_H_

class Robot: public IterativeRobot
{
public:
	static OI *oi;
	static Talon* leftMotor1;
	static Talon* leftMotor2;
	static TwoMotor* leftMotors;
	static Talon* rightMotor1;
	static Talon* rightMotor2;
	static TwoMotor* rightMotors;
	static Talon* rearMotor1;
	static Talon* rearMotor2;
	static TwoMotor* rearMotors;
	static RateGyro* gyro;
	static DriveBase* driveBase;

	static SlowSolenoid* bridge;
	static Victor* collector;
	static SlowSolenoid* fingers;
	static SlowSolenoid* injector;
	static CANJaguar* topWheel1;
	static CANJaguar* topWheel2;
	static Tachometer* topTach;
	static CANJaguar* bottomWheel1;
	static CANJaguar* bottomWheel2;
	static Tachometer* bottomTach;

private:
	static Command *autonomousCommand;
	static LiveWindow *lw;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif // _ROBOT_H_
