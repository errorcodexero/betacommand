#include "StopMotors.h"
#include "LowerKicker.h"
#include "StopCollector.h"
#include "StopShooter.h"


StopMotors::StopMotors() : CommandGroup("StopMotors")
{
    // start in hold configuration
    // all these should terminate almost immediately
    AddParallel(new LowerKicker());
    AddParallel(new StopCollector());
    AddParallel(new StopShooter());
}

StopMotors::~StopMotors()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

