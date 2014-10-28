// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include "Robot.h"

// Initialize a single static instance of all of your (components and) subsystems to NULL
Compressor* Robot::compressor = NULL;

Victor* Robot::leftMotor1 = NULL;
// Victor* Robot::leftMotor2 = NULL;
// TwoMotor<Victor>* Robot::leftMotors = NULL;

Victor* Robot::rightMotor1 = NULL;
// Victor* Robot::rightMotor2 = NULL;
// TwoMotor<Victor>* Robot::rightMotors = NULL;

Victor* Robot::rearMotor1 = NULL;
// Victor* Robot::rearMotor2 = NULL;
// TwoMotor<Victor>* Robot::rearMotors = NULL;

RateGyro* Robot::gyro = NULL;

DriveBase* Robot::driveBase = NULL;

SlowSolenoid* Robot::bridge = NULL;
Victor* Robot::collector = NULL;

SlowSolenoid* Robot::fingers = NULL;
SlowSolenoid* Robot::injector = NULL;

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
static constexpr int PWM_LEFT_1  = 0;
// static constexpr int PWM_LEFT_2  = 0;
static constexpr int PWM_RIGHT_1 = 1;
// static constexpr int PWM_RIGHT_2 = 1;
static constexpr int PWM_REAR_1  = 2;
// static constexpr int PWM_REAR_2  = 2;
static constexpr int PWM_COLLECTOR = 3;

static constexpr int CAN_TOP1 = 5;
static constexpr int CAN_TOP2 = 6;
static constexpr int CAN_BOTTOM1 = 7;
static constexpr int CAN_BOTTOM2 = 8;

static constexpr int ANALOG_GYRO = 0;

static constexpr int DIN_TOP = 0;
static constexpr int DIN_BOTTOM = 1;

static constexpr int SOL_BRIDGE = 0;
static constexpr int SOL_FINGERS = 1;
static constexpr int SOL_INJECTOR = 2;

void Robot::RobotInit()
{
    LiveWindow* lw = LiveWindow::GetInstance();

    compressor = new Compressor();

    leftMotor1 = new Victor(PWM_LEFT_1);
    lw->AddActuator("DriveBase", "Left1",  leftMotor1);
    // leftMotor2 = new Victor(PWM_LEFT_2);
    // lw->AddActuator("DriveBase", "Left2",  leftMotor2);
    // leftMotors  = new TwoMotor<Victor>(leftMotor1, leftMotor2);

    rightMotor1 = new Victor(PWM_RIGHT_1);
    lw->AddActuator("DriveBase", "Right1", rightMotor1);
    // rightMotor2 = new Victor(PWM_RIGHT_2);
    // lw->AddActuator("DriveBase", "Right2", rightMotor2);
    // rightMotors = new TwoMotor<Victor>(rightMotor1, rightMotor2);

    rearMotor1 = new Victor(PWM_REAR_1);
    lw->AddActuator("DriveBase", "Rear1",  rearMotor1);
    // rearMotor2 = new Victor(PWM_REAR_2);
    // lw->AddActuator("DriveBase", "Rear2",  rearMotor2);
    // rearMotors  = new TwoMotor<Victor>(rearMotor1, rearMotor2);

    gyro = new RateGyro(ANALOG_GYRO);
    lw->AddSensor("DriveBase", "Gyro", gyro);

    // driveBase = new DriveBase(leftMotors, rightMotors, rearMotors, gyro);
    driveBase = new DriveBase(leftMotor1, rightMotor1, rearMotor1, gyro);

    collector = new Victor(PWM_COLLECTOR);
    lw->AddActuator("Collector", "Motor", collector);

    bridge = new SlowSolenoid(SOL_BRIDGE, 2.5, 1.8, true);
    lw->AddActuator("Collector", "Bridge", bridge);

    fingers = new SlowSolenoid(SOL_FINGERS, 0.2, 0.2, false);
    lw->AddActuator("Injector", "Fingers", fingers);

    injector = new SlowSolenoid(SOL_INJECTOR, 0.5, 0.5, false);
    lw->AddActuator("Injector", "Injector", injector);

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
    SmartDashboard::PutData("DriveCommand", driveCommand);

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

