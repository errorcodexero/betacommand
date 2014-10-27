#include "HoldMode.h"
#include "StopShooter.h"
#include "LowerInjector.h"
#include "CloseFingers.h"
#include "RaiseBridge.h"
#include "StopCollector.h"


HoldMode::HoldMode() : CommandGroup("HoldMode")
{
    AddParallel(new StopShooter());
    AddParallel(new RaiseBridge());
    AddParallel(new StopCollector());
    AddSequential(new CloseFingers());
    AddSequential(new LowerInjector());
    AddSequential(new WaitForChildren(5.0));
}

HoldMode::~HoldMode()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

