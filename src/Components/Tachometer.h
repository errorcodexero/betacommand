// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"
#pragma once
#include <WPILib.h>
#include <OSAL/Synchronized.h>
#include <OSAL/Task.h>

// The Tachometer determines wheel speed by measuring the interval
// between rising edges of the Hall effect sensor output.

class Tachometer : public PIDSource, public LiveWindowSendable
{
public:
    Tachometer( uint32_t channel );
    virtual ~Tachometer();

    uint32_t GetInterval( void );
    virtual double PIDGet( void );

    // Sendable
    virtual void InitTable(ITable* subtable);
    virtual ITable* GetTable();
    virtual std::string GetSmartDashboardType();

    // LiveWindowSendable
    virtual void StartLiveWindowMode();
    virtual void StopLiveWindowMode();
    virtual void UpdateTable();

private:
    DigitalInput sensor;
    ITable* table;
    NTReentrantSemaphore tachSem;

    uint32_t lastTime;
    uint32_t lastInterval;
    bool sampleValid;
    bool intervalValid;

    static void InterruptHandler( uint32_t mask, void *param );
    void HandleInterrupt( void );
};
