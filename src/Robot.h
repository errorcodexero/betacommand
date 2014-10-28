// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#ifndef _ROBOT_H_
#define _ROBOT_H_

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
#include "Commands/CollectMode.h"
#include "Commands/DriveCommand.h"
#include "Commands/HoldMode.h"
#include "Commands/LowerBridge.h"
#include "Commands/LowerInjector.h"
#include "Commands/LowerInjectorAndOpenFingers.h"
#include "Commands/OpenFingers.h"
#include "Commands/PassMode.h"
#include "Commands/RaiseBridge.h"
#include "Commands/RaiseInjector.h"
#include "Commands/ReverseCollector.h"
#include "Commands/StartCollector.h"
#include "Commands/StopCollector.h"
#include "Commands/StopShooter.h"
#include "Commands/TimedDrive.h"

class Robot: public IterativeRobot
{
public:
	static OI *oi;

	static Compressor* compressor;

	static Victor* leftMotor1;
	// static Victor* leftMotor2;
	// static TwoMotor<Victor>* leftMotors;
	static Victor* rightMotor1;
	// static Victor* rightMotor2;
	// static TwoMotor<Victor>* rightMotors;
	static Victor* rearMotor1;
	// static Victor* rearMotor2;
	// static TwoMotor<Victor>* rearMotors;
	static RateGyro* gyro;
	static DriveBase* driveBase;

	static SlowSolenoid* bridge;
	static Victor* collector;
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

	static CatchMode* catchMode;
	static CloseFingers* closeFingers;
	static CollectMode* collectMode;
	static DriveCommand* driveCommand;
	static HoldMode* holdMode;
	static LowerBridge* lowerBridge;
	static LowerInjector* lowerInjector;
	static LowerInjectorAndOpenFingers* lowerInjectorAndOpenFingers;
	static OpenFingers* openFingers;
	static PassMode* passMode;
	static RaiseBridge* raiseBridge;
	static RaiseInjector* raiseInjector;
	static ReverseCollector* reverseCollector;
	static StartCollector* startCollector;
	static StopCollector* stopCollector;
	static StopShooter* stopShooter;
	// static TimedDrive* timedDrive;

	static Command *autonomousCommand;

private:
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif // _ROBOT_H_
