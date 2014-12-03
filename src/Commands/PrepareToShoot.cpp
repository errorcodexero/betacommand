#include "PrepareToShoot.h"
#include "CloseFingers.h"
#include "LowerInjector.h"
#include "LowerInjectorAndOpenFingers.h"
#include "RaiseInjector.h"
#include "LowerBridge.h"
#include "RaiseBridge.h"
#include "StopCollector.h"
#include "StartShooter.h"
#include "StopShooter.h"


PrepareToShoot::PrepareToShoot() : CommandGroup("PrepareToShoot")
{
    // start in hold configuration (all these should terminate immediately)
    AddParallel(new StopCollector());
    AddParallel(new RaiseBridge());
    AddSequential(new CloseFingers());
    AddSequential(new LowerInjector());
    AddSequential(new WaitForChildren(6.0));

    // start wheels, wait for spin up
    AddSequential(new StartShooter());
}

PrepareToShoot::~PrepareToShoot()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

