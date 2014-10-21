// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"

#include<WPILib.h>

#ifndef _TWOMOTOR_H_
#define _TWOMOTOR_H_

class TwoMotor : public SpeedController, public MotorSafety
{
public:
    TwoMotor( Talon *m, Talon *s );
    virtual ~TwoMotor();
    virtual void Set( float value, uint8_t syncGroup=0 );
    virtual float Get();
    virtual void Disable();

    virtual void PIDWrite( float output );

    virtual void SetExpiration(float timeout);
    virtual float GetExpiration();
    virtual bool IsAlive();
    virtual void StopMotor();
    virtual void SetSafetyEnabled(bool enabled);
    virtual bool IsSafetyEnabled();
    virtual void GetDescription(char *desc);

private:
    Talon *master;
    Talon *slave;
};

#endif // _TWOMOTOR_H_
