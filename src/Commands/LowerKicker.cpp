#include "LowerKicker.h"
#include "../Robot.h"


LowerKicker::LowerKicker() : Command("LowerKicker") { }

LowerKicker::~LowerKicker() { }

void LowerKicker::Initialize()
{
    if (Robot::kicker) Robot::kicker->Set(false);
}

void LowerKicker::Execute()
{
    return;
}

bool LowerKicker::IsFinished()
{
    return !(Robot::kicker && Robot::kicker->IsMoving());
}

void LowerKicker::End()
{
    return;
}

void LowerKicker::Interrupted()
{
    return;
}

