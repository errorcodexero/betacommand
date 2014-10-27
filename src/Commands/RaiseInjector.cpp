#include "RaiseInjector.h"


RaiseInjector::RaiseInjector() : Command("RaiseInjector") { }

RaiseInjector::~RaiseInjector() { }

void RaiseInjector::Initialize()
{
    if (Robot::injector) Robot::injector->Set(true);
}

void RaiseInjector::Execute()
{
    return;
}

bool RaiseInjector::IsFinished()
{
    return !(Robot::injector && Robot::injector->IsMoving());
}

void RaiseInjector::End()
{
    return;
}

void RaiseInjector::Interrupted()
{
    return;
}

