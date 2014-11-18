// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include <WPILib.h>
#include "OI.h"
#include "Components/TwoMotor.h"
#include "Components/RateGyro.h"
#include "Components/SlowSolenoid.h"
#include "Components/Tachometer.h"
#include "Components/TwoMotor.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Shooter.h"
#include "Commands/CatchMode.h"
#include "Commands/CloseFingers.h"
#include "Commands/CloseFingersAndRaiseInjector.h"
#include "Commands/CollectMode.h"
#include "Commands/DriveCommand.h"
#include "Commands/HoldMode.h"
#include "Commands/LowerBridge.h"
#include "Commands/LowerInjector.h"
#include "Commands/LowerInjectorAndOpenFingers.h"
#include "Commands/LowerKicker.h"
#include "Commands/OpenFingers.h"
#include "Commands/PassBall.h"
#include "Commands/RaiseBridge.h"
#include "Commands/RaiseInjector.h"
#include "Commands/RaiseKicker.h"
#include "Commands/ReverseCollector.h"
#include "Commands/ShootBall.h"
#include "Commands/StartCollector.h"
#include "Commands/StartShooter.h"
#include "Commands/StopCollector.h"
#include "Commands/StopShooter.h"
#include "Commands/AutoCommand.h"

class Robot: public IterativeRobot
{
public:
	static OI *oi;

	static Compressor* compressor;

	static Victor* leftMotor;
	static Victor* rightMotor;
	static Victor* rearMotor;
	static RateGyro* gyro;
	static DriveBase* driveBase;

	static Victor* collector;
	static SlowDoubleSolenoid* bridge;
	static SlowDoubleSolenoid* injector1;
	static SlowDoubleSolenoid* injector2;
	static SlowSolenoid* kicker;
	static SlowSolenoid* fingers;
	static CANJaguar* bottomMotor1;
	static CANJaguar* bottomMotor2;
	static TwoMotor<CANJaguar>* bottomMotors;
	static Tachometer* bottomTach;
	static CANJaguar* topMotor1;
	static CANJaguar* topMotor2;
	static TwoMotor<CANJaguar>* topMotors;
	static Tachometer* topTach;
	static Shooter* shooter;

	static Command* catchMode;
	static Command* closeFingers;
	static Command* closeFingersAndRaiseInjector;
	static Command* collectMode;
	static Command* driveCommand;
	static Command* holdMode;
	static Command* lowerBridge;
	static Command* lowerInjector;
	static Command* lowerInjectorAndOpenFingers;
	static Command* lowerKicker;
	static Command* openFingers;
	static Command* passBall;
	static Command* raiseBridge;
	static Command* raiseInjector;
	static Command* raiseKicker;
	static Command* reverseCollector;
	static Command* shootBall;
	static Command* startCollector;
	static Command* startShooter;
	static Command* stopCollector;
	static Command* stopShooter;
	static Command *autoCommand;

private:
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};
