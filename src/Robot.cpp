// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include "Robot.h"

// Initialize a single static instance of all of your (components and) subsystems to NULL
Compressor* Robot::compressor = NULL;

Victor* Robot::leftMotor = NULL;
Victor* Robot::rightMotor = NULL;
Victor* Robot::rearMotor = NULL;

RateGyro* Robot::gyro = NULL;

DriveBase* Robot::driveBase = NULL;

SlowDoubleSolenoid* Robot::bridge = NULL;
Victor* Robot::collector = NULL;
SlowDoubleSolenoid* Robot::injector1 = NULL;
SlowDoubleSolenoid* Robot::injector2 = NULL;
SlowSolenoid* Robot::ejector = NULL;
SlowSolenoid* Robot::fingers = NULL;

CANJaguar* Robot::bottomMotor1 = NULL;
CANJaguar* Robot::bottomMotor2 = NULL;
TwoMotor<CANJaguar>* Robot::bottomMotors = NULL;

Tachometer* Robot::bottomTach = NULL;

CANJaguar* Robot::topMotor1 = NULL;
CANJaguar* Robot::topMotor2 = NULL;
TwoMotor<CANJaguar>* Robot::topMotors = NULL;

Tachometer* Robot::topTach = NULL;

Shooter* Robot::shooter = NULL;

OI* Robot::oi = NULL;

// Initialize a single static instance of your commands to NULL
CatchMode* Robot::catchMode = NULL;
CloseFingers* Robot::closeFingers = NULL;
CollectMode* Robot::collectMode = NULL;
DriveCommand* Robot::driveCommand = NULL;
HoldMode* Robot::holdMode = NULL;
LowerBridge* Robot::lowerBridge = NULL;
LowerInjector* Robot::lowerInjector = NULL;
LowerInjectorAndOpenFingers* Robot::lowerInjectorAndOpenFingers = NULL;
OpenFingers* Robot::openFingers = NULL;
PassMode* Robot::passMode = NULL;
RaiseBridge* Robot::raiseBridge = NULL;
RaiseInjector* Robot::raiseInjector = NULL;
ReverseCollector* Robot::reverseCollector = NULL;
StartCollector* Robot::startCollector = NULL;
StopCollector* Robot::stopCollector = NULL;
StopShooter* Robot::stopShooter = NULL;
// TimedDrive* Robot::timedDrive = NULL;
Command* Robot::autonomousCommand = NULL;

// Define where all the components are connected
static constexpr int PWM_LEFT  = 0;
static constexpr int PWM_RIGHT = 1;
static constexpr int PWM_REAR  = 2;
static constexpr int PWM_COLLECTOR = 3;

static constexpr int CAN_TOP1 = 1;
static constexpr int CAN_TOP2 = 2;
static constexpr int CAN_BOTTOM1 = 3;
static constexpr int CAN_BOTTOM2 = 4;

static constexpr int ANALOG_GYRO = 0;

static constexpr int DIN_TOP = 0;
static constexpr int DIN_BOTTOM = 1;

static constexpr int SOL_BRIDGE_DOWN = 0;
static constexpr int SOL_BRIDGE_UP = 1;
static constexpr int SOL_INJECTOR_DOWN_1 = 2;
static constexpr int SOL_INJECTOR_DOWN_2 = 3;	// dummy
static constexpr int SOL_INJECTOR_UP_1 = 4;
static constexpr int SOL_INJECTOR_UP_2 = 5;
static constexpr int SOL_EJECTOR = 6;
static constexpr int SOL_FINGERS = 7;

void Robot::RobotInit()
{
    LiveWindow* lw = LiveWindow::GetInstance();

    compressor = new Compressor();

    leftMotor = new Victor(PWM_LEFT);
    lw->AddActuator("DriveBase", "Left",  leftMotor);

    rightMotor = new Victor(PWM_RIGHT);
    lw->AddActuator("DriveBase", "Right", rightMotor);

    rearMotor = new Victor(PWM_REAR);
    lw->AddActuator("DriveBase", "Rear",  rearMotor);

    gyro = new RateGyro(ANALOG_GYRO);
    lw->AddSensor("DriveBase", "Gyro", gyro);

    driveBase = new DriveBase(leftMotor, rightMotor, rearMotor, gyro);

    collector = new Victor(PWM_COLLECTOR);
    lw->AddActuator("Collector", "Motor", collector);

    bridge = new SlowDoubleSolenoid(SOL_BRIDGE_DOWN, SOL_BRIDGE_UP, 2.5, 1.8, DoubleSolenoid::kReverse);
    lw->AddActuator("Collector", "Bridge", bridge);

    injector1 = new SlowDoubleSolenoid(SOL_INJECTOR_UP_1, SOL_INJECTOR_DOWN_1, 0.75, 1.8, DoubleSolenoid::kReverse);
    lw->AddActuator("Injector", "Injector1", injector1);
    injector2 = new SlowDoubleSolenoid(SOL_INJECTOR_UP_2, SOL_INJECTOR_DOWN_2, 0.75, 1.8, DoubleSolenoid::kReverse);
    lw->AddActuator("Injector", "Injector2", injector2);

    ejector = new SlowSolenoid(SOL_EJECTOR, 0.2, 0.2, false);
    lw->AddActuator("Ejector", "Ejector", ejector);

    fingers = new SlowSolenoid(SOL_FINGERS, 0.2, 0.2, true);
    lw->AddActuator("Injector", "Fingers", fingers);

    bottomMotor1 = new CANJaguar(CAN_BOTTOM1);
    lw->AddActuator("BottomWheel", "Motor1", bottomMotor1);

    bottomMotor2 = new CANJaguar(CAN_BOTTOM2);
    lw->AddActuator("BottomWheel", "Motor2", bottomMotor2);

    bottomMotors = new TwoMotor<CANJaguar>(bottomMotor1, bottomMotor2);

    bottomTach = new Tachometer(DIN_BOTTOM);
    lw->AddSensor("BottomWheel", "Tach", bottomTach);

    topMotor1 = new CANJaguar(CAN_TOP1);
    lw->AddActuator("TopWheel", "Motor1", topMotor1);

    topMotor2 = new CANJaguar(CAN_TOP2);
    lw->AddActuator("TopWheel", "Motor2", topMotor2);

    topMotors = new TwoMotor<CANJaguar>(topMotor1, topMotor2);

    topTach = new Tachometer(DIN_TOP);
    lw->AddSensor("TopWheel", "Tach", topTach);

    shooter = new Shooter(bottomMotors, bottomTach, topMotors, topTach);

    oi = new OI();

    catchMode = new CatchMode();
    SmartDashboard::PutData("CatchMode", catchMode);

    closeFingers = new CloseFingers();
    SmartDashboard::PutData("CloseFingers", closeFingers);

    collectMode = new CollectMode();
    SmartDashboard::PutData("CollectMode", collectMode);

    driveCommand = new DriveCommand();
    // SmartDashboard::PutData("DriveCommand", driveCommand);

    holdMode = new HoldMode();
    SmartDashboard::PutData("HoldMode", holdMode);

    lowerBridge = new LowerBridge();
    SmartDashboard::PutData("LowerBridge", lowerBridge);

    lowerInjector = new LowerInjector();
    SmartDashboard::PutData("LowerInjector", lowerInjector);

    lowerInjectorAndOpenFingers = new LowerInjectorAndOpenFingers();
    SmartDashboard::PutData("LowerInjectorAndOpenFingers", lowerInjectorAndOpenFingers);

    openFingers = new OpenFingers();
    SmartDashboard::PutData("OpenFingers", openFingers);

    passMode = new PassMode();
    SmartDashboard::PutData("PassMode", passMode);

    raiseBridge = new RaiseBridge();
    SmartDashboard::PutData("RaiseBridge", raiseBridge);

    raiseInjector = new RaiseInjector();
    SmartDashboard::PutData("RaiseInjector", raiseInjector);

    reverseCollector = new ReverseCollector();
    SmartDashboard::PutData("ReverseCollector", reverseCollector);

    startCollector = new StartCollector();
    SmartDashboard::PutData("StartCollector", startCollector);

    stopCollector = new StopCollector();
    SmartDashboard::PutData("StopCollector", stopCollector);

    stopShooter = new StopShooter();
    SmartDashboard::PutData("StopShooter", stopShooter);

    // timedDrive = new TimedDrive();
    // SmartDashboard::PutData("TimedDrive", timedDrive);

    // autonomousCommand = new AutoCommand();
}

void Robot::AutonomousInit()
{
    if (autonomousCommand) autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to 
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (autonomousCommand) autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
    LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);

