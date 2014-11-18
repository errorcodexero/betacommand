#include "CollectMode.h"
#include "StopShooter.h"
#include "LowerInjectorAndOpenFingers.h"
#include "LowerBridge.h"
#include "StartCollector.h"


CollectMode::CollectMode() : CommandGroup("CollectMode")
{
    AddParallel(new StopShooter());
    AddParallel(new LowerInjectorAndOpenFingers());
    AddSequential(new LowerBridge());
    AddSequential(new StartCollector());
}

CollectMode::~CollectMode()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

