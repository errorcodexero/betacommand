#include "PassBall.h"
#include "StopShooter.h"
#include "LowerInjectorAndOpenFingers.h"
#include "LowerBridge.h"
#include "ReverseCollector.h"
#include "RaiseKicker.h"
#include "LowerKicker.h"
#include "StopCollector.h"


PassBall::PassBall() : CommandGroup("PassBall")
{
    AddParallel(new StopShooter());
    AddParallel(new LowerInjectorAndOpenFingers());
    AddParallel(new LowerBridge());
    AddParallel(new ReverseCollector());
    AddSequential(new WaitForChildren(3.0));
    AddSequential(new RaiseKicker());
    AddSequential(new LowerKicker());
    AddSequential(new WaitCommand(3.0));
    AddSequential(new StopCollector());
}

PassBall::~PassBall()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}
