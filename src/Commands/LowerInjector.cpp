#include "LowerInjector.h"


LowerInjector::LowerInjector() : Command("LowerInjector") { }

LowerInjector::~LowerInjector() { }

void LowerInjector::Initialize()
{
    if (Robot::injector) Robot::injector->Set(false);
}

void LowerInjector::Execute()
{
    return;
}

bool LowerInjector::IsFinished()
{
    return !(Robot::injector && Robot::injector->IsMoving());
}

void LowerInjector::End()
{
    return;
}

void LowerInjector::Interrupted()
{
    return;
}

