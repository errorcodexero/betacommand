// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include <WPILib.h>
class OI; // #include "OI.h"
#include "Components/InstrumentedJaguar.h"
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
#include "Commands/PrepareToShoot.h"
#include "Commands/RaiseBridge.h"
#include "Commands/RaiseInjector.h"
#include "Commands/RaiseKicker.h"
#include "Commands/ReverseCollector.h"
#include "Commands/ShootBall.h"
#include "Commands/StartCollector.h"
#include "Commands/StartShooter.h"
#include "Commands/StopCollector.h"
#include "Commands/StopMotors.h"
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
	static InstrumentedJaguar* bottomMotor1;
	static InstrumentedJaguar* bottomMotor2;
	static TwoMotor<InstrumentedJaguar>* bottomMotors;
	static Tachometer* bottomTach;
	static InstrumentedJaguar* topMotor1;
	static InstrumentedJaguar* topMotor2;
	static TwoMotor<InstrumentedJaguar>* topMotors;
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
	static Command* prepareToShoot;
	static Command* raiseBridge;
	static Command* raiseInjector;
	static Command* raiseKicker;
	static Command* reverseCollector;
	static Command* shootBall;
	static Command* startCollector;
	static Command* startShooter;
	static Command* stopCollector;
	static Command* stopMotors;
	static Command* stopShooter;
	static Command* autoCommand;

private:
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestInit();
	virtual void TestPeriodic();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();

	void ReportPower();
};
