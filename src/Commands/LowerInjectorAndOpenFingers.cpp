#include "LowerInjectorAndOpenFingers.h"
#include "LowerInjector.h"
#include "OpenFingers.h"


LowerInjectorAndOpenFingers::LowerInjectorAndOpenFingers() :
    CommandGroup("LowerInjectorAndOpenFingers")
{
    AddSequential(new LowerInjector());
    AddSequential(new OpenFingers());
}

LowerInjectorAndOpenFingers::~LowerInjectorAndOpenFingers() { }

