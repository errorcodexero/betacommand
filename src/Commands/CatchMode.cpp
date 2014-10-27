#include "CatchMode.h"
#include "StopShooter.h"
#include "LowerInjector.h"
#include "CloseFingers.h"
#include "LowerBridge.h"
#include "StopCollector.h"


CatchMode::CatchMode() : CommandGroup("CatchMode")
{
    AddParallel(new StopShooter());
    AddParallel(new LowerBridge());
    AddParallel(new StopCollector());
    AddSequential(new CloseFingers());
    AddSequential(new LowerInjector());
    AddSequential(new WaitForChildren(5.0));
}

CatchMode::~CatchMode()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

