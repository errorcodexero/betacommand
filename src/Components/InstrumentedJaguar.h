// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include <WPILib.h>
#include <string>

class InstrumentedJaguar : public CANJaguar
{
private:
    std::string m_V, m_I;
    Notifier *m_notifier;

public:
    explicit InstrumentedJaguar( uint8_t deviceNumber );
    virtual ~InstrumentedJaguar();

    // SpeedController interface
    virtual float Get();
    virtual void Set(float value, uint8_t syncGroup=0);
    virtual void Disable();

    // PIDOutput interface
    virtual void PIDWrite(float output);

    void update();

    static void timerEventHandler( void *param );
};
