#include "CloseFingersAndRaiseInjector.h"
#include "CloseFingers.h"
#include "RaiseInjector.h"


CloseFingersAndRaiseInjector::CloseFingersAndRaiseInjector() :
    CommandGroup("CloseFingersAndRaiseInjector")
{
    AddSequential(new CloseFingers());
    AddSequential(new RaiseInjector());
}

CloseFingersAndRaiseInjector::~CloseFingersAndRaiseInjector() { }

