#include "RaiseKicker.h"
#include "../Robot.h"


RaiseKicker::RaiseKicker() : Command("RaiseKicker") { }

RaiseKicker::~RaiseKicker() { }

void RaiseKicker::Initialize()
{
    if (Robot::kicker) Robot::kicker->Set(true);
}

void RaiseKicker::Execute()
{
    return;
}

bool RaiseKicker::IsFinished()
{
    return !(Robot::kicker && Robot::kicker->IsMoving());
}

void RaiseKicker::End()
{
    return;
}

void RaiseKicker::Interrupted()
{
    return;
}

