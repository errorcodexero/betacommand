// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include <WPILib.h>
#include <OSAL/Synchronized.h>
#include <OSAL/Task.h>
#include "Tachometer.h"

Tachometer::Tachometer( uint32_t channel ) :
    SensorBase(),
    PIDSource(),
    LiveWindowSendable(),
    table(NULL),
    sensor(channel),
    lastTime(0),
    lastInterval(0),
    sampleValid(false),
    intervalValid(false)
{
    sensor.RequestInterrupts( Tachometer::InterruptHandler, this );
    sensor.EnableInterrupts();
}


Tachometer::~Tachometer()
{
    sensor.CancelInterrupts();
}


void
Tachometer::InterruptHandler( uint32_t mask, void *param )
{
    static_cast<Tachometer *>(param)->HandleInterrupt();
}


void
Tachometer::HandleInterrupt()
{
    // stupid floating point!
    uint32_t when = (uint32_t) (sensor.ReadRisingTimestamp() * 1e6 + 0.5);

    {
	NTSynchronized LOCK(tachSem);

	if (sampleValid) {
	    uint32_t interval = when - lastTime;
	    if (interval < 200000) {	// 200mS
		lastInterval = interval;
		intervalValid = true;
	    }
	}
	lastTime = when;
	sampleValid = true;
    }
}


uint32_t
Tachometer::GetInterval()
{
    NTSynchronized LOCK(tachSem);

    if (intervalValid) {
	// check if interval is _still_ valid
	uint32_t now = GetFPGATime();
	uint32_t interval = now - lastTime;
	if (interval < 200000) {	// 200mS
	    return lastInterval;
	} else {
	    intervalValid = false;
	}
    }
    return 0;
}


double
Tachometer::PIDGet()
{
    uint32_t interval = GetInterval();
    if (interval) {
	return 60.e-6 / interval;
    } else {
	return 0.;
    }
}

void Tachometer::UpdateTable() {
    if (table != NULL) {
	table->PutNumber("Speed", PIDGet());
    }
}

void Tachometer::StartLiveWindowMode() { }

void Tachometer::StopLiveWindowMode() { } 

std::string Tachometer::GetSmartDashboardType() {
    return "Tachometer";
}

void Tachometer::InitTable(ITable *subTable) {
    table = subTable;
    UpdateTable();
}

ITable * Tachometer::GetTable() {
    return table;
}


