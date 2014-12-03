#include "AutoCommand.h"
#include "CollectMode.h"
#include "LowerBridge.h"
#include "LowerInjectorAndOpenFingers.h"
#include "PrepareToShoot.h"
#include "RaiseInjector.h"
#include "StopShooter.h"
#include "TimedDrive.h"

AutoCommand::AutoCommand() : CommandGroup("AutoCommand")
{
    // spin up the shooter
    AddSequential(new PrepareToShoot());

    // shoot the first ball
    AddSequential(new RaiseInjector());

    // switch to collect mode
    AddSequential(new CollectMode());

    // drive in reverse to pick up ball
    AddSequential(new TimedDrive(0.0, 0.2, 0.0, 1.8));

    // switch to hold mode, spin up the shooter
    AddSequential(new PrepareToShoot());

    // shoot the second ball
    AddSequential(new RaiseInjector());

    // stop shooter, switch to catch/collect configuration
    AddParallel(new StopShooter());
    AddParallel(new LowerInjectorAndOpenFingers());
    AddSequential(new LowerBridge());

    // drive forward to cross line
    AddSequential(new TimedDrive(0.0, -0.3, 0.0, 3.0));
}

AutoCommand::~AutoCommand()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

