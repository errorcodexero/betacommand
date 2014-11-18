// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"
#pragma once
#include<WPILib.h>

template <class MotorController>
class TwoMotor : public SpeedController, public MotorSafety
{
private:
    MotorController *master;
    MotorController *slave;

public:
    TwoMotor( MotorController *m, MotorController *s ) {
	master = m;
	slave = s;
    };

    virtual ~TwoMotor() {
	;
    };

    virtual void Set( float value, uint8_t syncGroup=0 ) {
	master->Set(value, syncGroup);
	slave->Set(value, syncGroup);
    };

    virtual float Get() {
	return master->Get();
    }

    virtual void Disable() {
	master->Disable();
	slave->Disable();
    };

    virtual void PIDWrite( float output ) {
	master->PIDWrite(output);
	slave->PIDWrite(output);
    };

    virtual void SetExpiration(float timeout) {
	master->SetExpiration(timeout);
	slave->SetExpiration(timeout);
    };

    virtual float GetExpiration() {
	return master->GetExpiration();
    };

    virtual bool IsAlive() {
	return master->IsAlive() && slave->IsAlive();
    };

    virtual void StopMotor() {
	master->StopMotor();
	slave->StopMotor();
    };

    virtual void SetSafetyEnabled(bool enabled) {
	master->SetSafetyEnabled(enabled);
	slave->SetSafetyEnabled(enabled);
    };

    virtual bool IsSafetyEnabled() {
	return master->IsSafetyEnabled();
    };

    virtual void GetDescription(char *desc) {
	master->GetDescription(desc);
    };
};
