// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"

#include <WPILib.h>
#include "TwoMotor.h"

TwoMotor::TwoMotor( Talon *m, Talon *s )
    : SpeedController(), MotorSafety()
{
    master = m;
    slave = s;
}

TwoMotor::~TwoMotor()
{
}

void TwoMotor::Set( float value, uint8_t syncGroup )
{
    master->Set( value, syncGroup );
    slave->Set( value, syncGroup );
}

float TwoMotor::Get()
{
    return master->Get();
}

void TwoMotor::Disable()
{
    master->Disable();
    slave->Disable();
}

void TwoMotor::PIDWrite( float output )
{
    master->PIDWrite( output );
    slave->PIDWrite( output );
}

void TwoMotor::SetExpiration( float timeout )
{
    master->SetExpiration(timeout);
    slave->SetExpiration(timeout);
}

float TwoMotor::GetExpiration()
{
    return master->GetExpiration();
}

bool TwoMotor::IsAlive()
{
    return master->IsAlive() && slave->IsAlive();
}

void TwoMotor::StopMotor()
{
    master->StopMotor();
    slave->StopMotor();
}

void TwoMotor::SetSafetyEnabled( bool enabled )
{
    master->SetSafetyEnabled(enabled);
    slave->SetSafetyEnabled(enabled);
}

bool TwoMotor::IsSafetyEnabled()
{
    return master->IsSafetyEnabled();
}

void TwoMotor::GetDescription( char *desc )
{
    master->GetDescription(desc);
}

