#include "AutoCommand.h"
#include "ShootBall.h"
#include "CollectMode.h"
#include "TimedDrive.h"

AutoCommand::AutoCommand() : CommandGroup("AutoCommand")
{
    // shoot the first ball
    AddSequential(new ShootBall());

    // switch to collect mode
    AddSequential(new CollectMode());

    // drive in reverse to pick up ball
    AddSequential(new TimedDrive(0.0, 0.2, 0.0, 1.8));

    // switch to hold mode, shoot ball
    AddSequential(new ShootBall());

    // drive forward to cross line
    AddSequential(new TimedDrive(0.0, -0.3, 0.0, 3.0));
}

AutoCommand::~AutoCommand()
{
    // This class should be responsible for deleting the commands
    // that it instantiated in the constructor, but it appears that
    // this is actually handled in the parent class...
}

