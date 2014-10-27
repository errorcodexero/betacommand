#include "PassMode.h"
#include "StopShooter.h"
#include "LowerInjectorAndOpenFingers.h"
#include "LowerBridge.h"
#include "StopCollector.h"


PassMode::PassMode() : CommandGroup("PassMode")
{
    AddParallel(new StopShooter());
    AddParallel(new LowerInjectorAndOpenFingers());
    AddParallel(new LowerBridge());
    AddParallel(new StopCollector());
}

PassMode::~PassMode()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

