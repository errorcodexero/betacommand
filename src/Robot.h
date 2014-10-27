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
#include "Subsystems/Shooter.h"

#ifndef _ROBOT_H_
#define _ROBOT_H_

class Robot: public IterativeRobot
{
public:
	static OI *oi;

	static Compressor* compressor;

	static Talon* leftMotor1;
	static Talon* leftMotor2;
	static TwoMotor<Talon>* leftMotors;
	static Talon* rightMotor1;
	static Talon* rightMotor2;
	static TwoMotor<Talon>* rightMotors;
	static Talon* rearMotor1;
	static Talon* rearMotor2;
	static TwoMotor<Talon>* rearMotors;
	static RateGyro* gyro;
	static DriveBase* driveBase;

	static SlowSolenoid* bridge;
	static Relay* collector;
	static SlowSolenoid* fingers;
	static SlowSolenoid* injector;
	static CANJaguar* bottomMotor1;
	static CANJaguar* bottomMotor2;
	static TwoMotor<CANJaguar>* bottomMotors;
	static Tachometer* bottomTach;
	static CANJaguar* topMotor1;
	static CANJaguar* topMotor2;
	static TwoMotor<CANJaguar>* topMotors;
	static Tachometer* topTach;
	static Shooter* shooter;

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
