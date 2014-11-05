#include "LowerBridge.h"
#include "../Robot.h"


LowerBridge::LowerBridge() : Command("LowerBridge") { }

LowerBridge::~LowerBridge() { }

void LowerBridge::Initialize()
{
    if (Robot::bridge) Robot::bridge->Set(DoubleSolenoid::kForward);
}

void LowerBridge::Execute()
{
    return;
}

bool LowerBridge::IsFinished()
{
    return !(Robot::bridge && Robot::bridge->IsMoving());
}

void LowerBridge::End()
{
    return;
}

void LowerBridge::Interrupted()
{
    return;
}

