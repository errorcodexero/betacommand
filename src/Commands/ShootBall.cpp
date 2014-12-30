#include "ShootBall.h"
#include "CatchMode.h"
#include "CloseFingers.h"
#include "LowerInjector.h"
#include "LowerInjectorAndOpenFingers.h"
#include "RaiseInjector.h"
#include "LowerBridge.h"
#include "PrepareToShoot.h"
#include "RaiseBridge.h"
#include "StopCollector.h"
#include "StartShooter.h"
#include "StopShooter.h"


ShootBall::ShootBall() : CommandGroup("ShootBall")
{
    // get into the right configuration, start wheels
    // (if they're not already spinning)
    AddSequential(new PrepareToShoot());

    // launch ball
    AddSequential(new RaiseInjector());

    // stop wheels, return to catch configuration
    AddSequential(new CatchMode());
}

ShootBall::~ShootBall()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

