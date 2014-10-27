#include "LowerInjectorAndOpenFingers.h"


LowerInjectorAndOpenFingers::LowerInjectorAndOpenFingers() :
    CommandGroup("LowerInjectorAndOpenFingers")
{
    AddSequential(new LowerInjector());
    AddSequential(new OpenFingers());
}

LowerInjectorAndOpenFingers::~LowerInjectorAndOpenFingers() { }

