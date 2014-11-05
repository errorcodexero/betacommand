#include "RaiseInjector.h"
#include "../Robot.h"


RaiseInjector::RaiseInjector() : Command("RaiseInjector") { }

RaiseInjector::~RaiseInjector() { }

void RaiseInjector::Initialize()
{
    if (Robot::injector1) Robot::injector1->Set(DoubleSolenoid::kForward);
    if (Robot::injector2) Robot::injector2->Set(DoubleSolenoid::kForward);
}

void RaiseInjector::Execute()
{
    return;
}

bool RaiseInjector::IsFinished()
{
    return !( (Robot::injector1 && Robot::injector1->IsMoving()) ||
	      (Robot::injector2 && Robot::injector2->IsMoving()) );
}

void RaiseInjector::End()
{
    return;
}

void RaiseInjector::Interrupted()
{
    return;
}

