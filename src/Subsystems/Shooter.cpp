#include "Shooter.h"

#define	kMinSet		(250.)
#define	kMaxSet		(4200.)
#define	kMinSpeed	(120.)
#define	kStartSpeed	(800.)
#define	kStartOut	(0.6)
#define	kP		(1.0/kMaxSet)
#define	kI		(0.05/kMaxSet)
#define	kD		(0.0)
#define	kF		(0.5/kMaxSet)
#define	kPeriod		(0.1)
#define	kTolerance 	(1.0)

Shooter::Shooter( TwoMotor<CANJaguar> *bottomMotor, Tachometer *bottomTach,
		  TwoMotor<CANJaguar> *topMotor, Tachometer *topTach )
    : Subsystem("Shooter")
{
    m_P = kP;
    m_I = kI;
    m_D = kD;
    m_F = kF;
    m_period = kPeriod;

    m_bottomMotor = bottomMotor;
    m_bottomTach = bottomTach;
    m_bottomPID = new PIDController( m_P, m_I, m_D, m_F, bottomTach, bottomMotor, m_period );
    m_bottomPID->SetInputRange( kMinSet, kMaxSet );
    m_bottomPID->SetOutputRange( 0.0, 1.0 );
    m_bottomPID->SetTolerance( kTolerance );

    m_topMotor = topMotor;
    m_topTach = topTach;
    m_topPID = new PIDController( m_P, m_I, m_D, m_F, topTach, topMotor, m_period );
    m_topPID->SetInputRange( kMinSet, kMaxSet );
    m_topPID->SetOutputRange( 0.0, 1.0 );
    m_topPID->SetTolerance( kTolerance );

    m_bottomSet = 0.;
    SmartDashboard::PutNumber("Bottom Set", m_bottomSet);
    m_topSet = 0.;
    SmartDashboard::PutNumber("Top Set", m_topSet);

    m_bottomSpeed = 0.;
    SmartDashboard::PutNumber("Bottom Speed", m_bottomSpeed);
    m_topSpeed = 0.;
    SmartDashboard::PutNumber("Top Speed", m_topSpeed);

    m_state = STOPPED;
}

Shooter::~Shooter()
{
    m_bottomPID->Disable();
    delete m_bottomPID;

    m_topPID->Disable();
    delete m_topPID;
}

void Shooter::Set( float bottomSpeed, float topSpeed )
{
    m_bottomSet = bottomSpeed;
    SmartDashboard::PutNumber("Bottom Set", m_bottomSet);
    m_topSet = topSpeed;
    SmartDashboard::PutNumber("Top Set", m_topSet);
}

void Shooter::Start()
{
    if (m_state == STOPPED) {
	m_bottomMotor->Set( kStartOut );
	m_state = BOTTOM;
    }
}

void Shooter::Stop()
{
    m_bottomPID->Disable();
    m_bottomMotor->Set(0.0);
    // m_bottomMotor->Disable();

    m_topPID->Disable();
    m_topMotor->Set(0.0);
    // m_topMotor->Disable();

    m_state = STOPPED;
}

void Shooter::Run()
{
    m_bottomSet = SmartDashboard::GetNumber("Bottom Set");
    m_bottomPID->SetSetpoint(m_bottomSet);
    m_topSet = SmartDashboard::GetNumber("Top Set");
    m_topPID->SetSetpoint(m_topSet);

    m_bottomSpeed = m_bottomTach->PIDGet();
    SmartDashboard::PutNumber("Bottom Speed", m_bottomSpeed);
    m_topSpeed = m_topTach->PIDGet();
    SmartDashboard::PutNumber("Top Speed", m_topSpeed);

    switch (m_state) {
    case STOPPED:
	m_bottomMotor->Set( 0.0 );
	m_topMotor->Set( 0.0 );
	break;

    case BOTTOM:
	// TBD: watch motor current, not motor speed?
	if (m_bottomSpeed < kStartSpeed) {
	    m_bottomMotor->Set( kStartOut );
	    m_topMotor->Set( 0.0 );
	} else {
	    m_bottomPID->Enable();
	    m_topMotor->Set( kStartOut );
	    m_state = TOP;
	} 
	break;

    case TOP:
	// TBD: watch motor current, not motor speed?
	if (m_topSpeed < kStartSpeed) {
	    m_topMotor->Set( kStartOut );
	} else {
	    m_topPID->Enable();
	    m_state = BOTH;
	}
	break;

    case BOTH:
	// PID running on both wheels
	break;
    }
}

bool Shooter::IsUpToSpeed()
{
    return (m_state == BOTH) && m_bottomPID->OnTarget() && m_topPID->OnTarget();
}

bool Shooter::IsMoving()
{
    return (m_bottomSpeed > kMinSpeed) || (m_topSpeed > kMinSpeed);
}

