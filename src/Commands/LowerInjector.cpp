#include "LowerInjector.h"
#include "../Robot.h"


LowerInjector::LowerInjector() : Command("LowerInjector") { }

LowerInjector::~LowerInjector() { }

void LowerInjector::Initialize()
{
    if (Robot::injector1) Robot::injector1->Set(DoubleSolenoid::kReverse);
    if (Robot::injector2) Robot::injector2->Set(DoubleSolenoid::kReverse);
}

void LowerInjector::Execute()
{
    return;
}

bool LowerInjector::IsFinished()
{
    return !( (Robot::injector1 && Robot::injector1->IsMoving()) ||
	      (Robot::injector2 && Robot::injector2->IsMoving()) );
}

void LowerInjector::End()
{
    return;
}

void LowerInjector::Interrupted()
{
    return;
}

