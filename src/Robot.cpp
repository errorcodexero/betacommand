// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include "WPILib.h"
#include "Robot.h"

// Initialize a single static instance of all of your subsystems to NULL
Talon* Robot::leftMotor1 = NULL;
Talon* Robot::leftMotor2 = NULL;
TwoMotor* Robot::leftMotors = NULL;

Talon* Robot::rightMotor1 = NULL;
Talon* Robot::rightMotor2 = NULL;
TwoMotor* Robot::rightMotors = NULL;

Talon* Robot::rearMotor1 = NULL;
Talon* Robot::rearMotor2 = NULL;
TwoMotor* Robot::rearMotors = NULL;

RateGyro* Robot::gyro = NULL;

DriveBase* Robot::driveBase = NULL;

SlowSolenoid* Robot::bridge = NULL;
Victor* Robot::collector = NULL;

SlowSolenoid* Robot::fingers = NULL;
SlowSolenoid* Robot::injector = NULL;

CANJaguar* Robot::topWheel1 = NULL;
CANJaguar* Robot::topWheel2 = NULL;

Tachometer* Robot::topTach = NULL;

CANJaguar* Robot::bottomWheel1 = NULL;
CANJaguar* Robot::bottomWheel2 = NULL;

Tachometer* Robot::bottomTach = NULL;

LiveWindow* Robot::lw = NULL;
OI* Robot::oi = NULL;
Command* Robot::autonomousCommand = NULL;

// Define where all the components are connected
static constexpr int PWM_LEFT_1  = 0;
static constexpr int PWM_LEFT_2  = 1;
static constexpr int PWM_RIGHT_1 = 2;
static constexpr int PWM_RIGHT_2 = 3;
static constexpr int PWM_REAR_1  = 4;
static constexpr int PWM_REAR_2  = 5;
static constexpr int PWM_COLLECTOR = 6;

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
    lw = LiveWindow::GetInstance();

    leftMotor1 = new Talon(PWM_LEFT_1);
    lw->AddActuator("DriveBase", "Left1",  leftMotor1);
    leftMotor2 = new Talon(PWM_LEFT_2);
    lw->AddActuator("DriveBase", "Left2",  leftMotor2);
    leftMotors  = new TwoMotor(leftMotor1, leftMotor2);

    rightMotor1 = new Talon(PWM_RIGHT_1);
    lw->AddActuator("DriveBase", "Right1", rightMotor1);
    rightMotor2 = new Talon(PWM_RIGHT_2);
    lw->AddActuator("DriveBase", "Right2", rightMotor2);
    rightMotors = new TwoMotor(rightMotor1, rightMotor2);

    rearMotor1 = new Talon(PWM_REAR_1);
    lw->AddActuator("DriveBase", "Rear1",  rearMotor1);
    rearMotor2 = new Talon(PWM_REAR_2);
    lw->AddActuator("DriveBase", "Rear2",  rearMotor2);
    rearMotors  = new TwoMotor(rearMotor1, rearMotor2);

    gyro = new RateGyro(ANALOG_GYRO);
    lw->AddSensor("DriveBase", "Gyro", gyro);

    driveBase = new DriveBase(leftMotors, rightMotors, rearMotors, gyro);

    collector = new Victor(PWM_COLLECTOR);
    bridge = new SlowSolenoid(SOL_BRIDGE, 2.5, 1.8, true);

    fingers = new SlowSolenoid(SOL_FINGERS, 0.2, 0.2, false);

    injector = new SlowSolenoid(SOL_INJECTOR, 0.5, 0.5, false);

    topWheel1 = new CANJaguar(CAN_TOP1);
    topWheel2 = new CANJaguar(CAN_TOP2);
    topTach = new Tachometer(DIN_TOP);

    bottomWheel1 = new CANJaguar(CAN_BOTTOM1);
    bottomWheel2 = new CANJaguar(CAN_BOTTOM2);
    bottomTach = new Tachometer(DIN_BOTTOM);

    oi = new OI();

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
    lw->Run();
}

START_ROBOT_CLASS(Robot);

