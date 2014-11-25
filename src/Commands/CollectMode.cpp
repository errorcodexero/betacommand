#include "CollectMode.h"
#include "StopShooter.h"
#include "LowerInjectorAndOpenFingers.h"
#include "LowerBridge.h"
#include "StartCollector.h"


CollectMode::CollectMode() : CommandGroup("CollectMode")
{
    AddParallel(new StopShooter());
    AddSequential(new LowerInjectorAndOpenFingers());
    AddSequential(new StartCollector());
    AddSequential(new LowerBridge());
}

CollectMode::~CollectMode()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

