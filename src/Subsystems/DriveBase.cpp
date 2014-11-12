// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"

#include "DriveBase.h"

DriveBase::DriveBase( SpeedController *left,
		      SpeedController *right,
		      SpeedController *rear,
		      RateGyro *gyro ) : Subsystem("DriveBase"),
    m_left(left),
    m_right(right),
    m_rear(rear),
    m_drive3(new RobotDrive3(rear, right, left)),
    m_gyro(gyro),
    m_gyroZero(0),
    m_defaultCommand(),
    m_started(false)
{
    Stop();
}

DriveBase::~DriveBase()
{
    SetDefaultCommand(NULL);
    Scheduler::GetInstance()->Remove(m_defaultCommand);
    delete m_defaultCommand;
    m_defaultCommand = NULL;

    Stop();

    delete m_drive3;
}
    
void DriveBase::InitDefaultCommand()
{
    if (!m_defaultCommand) {
	m_defaultCommand = new DriveCommand();
	SetDefaultCommand(m_defaultCommand);
    }
}

void DriveBase::Stop()
{
printf("DriveBase::Stop\n");

    // stop and disable all motors
#if 0
    // Disabling the PWM outputs is confusing because it looks like
    // the controllers are disconnected (blinking).  Just set the
    // outputs to zero instead.
    m_drive3->SetLeftRightMotorOutputs(0.0, 0.0);
#else
    m_drive3->StopMotor();
#endif
    // watchdogs not needed while stopped
    m_drive3->SetSafetyEnabled(false);
    dynamic_cast<MotorSafety*>(m_rear)->SetSafetyEnabled(false);
    dynamic_cast<MotorSafety*>(m_right)->SetSafetyEnabled(false);
    dynamic_cast<MotorSafety*>(m_left)->SetSafetyEnabled(false);
    // remember that we're stopped
    m_started = false;
}

void DriveBase::Start()
{
    if (!m_started) {
printf("DriveBase::Start\n");
	// set the watchdog timers to something long enough to
	// avoid panic in the presence of short-term network dropouts
	m_drive3->SetExpiration(2.0);
	dynamic_cast<MotorSafety*>(m_rear)->SetExpiration(2.0);
	dynamic_cast<MotorSafety*>(m_right)->SetExpiration(2.0);
	dynamic_cast<MotorSafety*>(m_left)->SetExpiration(2.0);

	// set all motors to 0.0 in order to feed their watchdogs
	m_drive3->SetLeftRightMotorOutputs(0.0, 0.0);

	// now enable the watchdogs
	m_drive3->SetSafetyEnabled(true);
#if 0 // we don't really need watchdogs on the individual motors
	dynamic_cast<MotorSafety*>(m_rear)->SetSafetyEnabled(true);
	dynamic_cast<MotorSafety*>(m_right)->SetSafetyEnabled(true);
	dynamic_cast<MotorSafety*>(m_left)->SetSafetyEnabled(true);
#endif

	// remember that we're started
	m_started = true;
    }
}

void DriveBase::Drive3( float x, float y, float twist )
{
    if (!m_started) Start();

    // Reduce the sensitivity to the "twist" control.
    // Add gyro compensation (adjust the "200" for best PID response).
    // Also reverse the direction, since our drive base is a mirror
    // image of what RobotDrive3 expects.
    twist = -( twist / 1.5 + m_gyro->GetRate() / 200. );

    // limit the twist range to avoid normalization problems
    if (twist < -1.0) twist = -1.0;
    if (twist > 1.0) twist = 1.0;

    m_drive3->HolonomicDrive_Cartesian( x, y, twist );
}

