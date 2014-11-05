#include "RaiseBridge.h"
#include "../Robot.h"


RaiseBridge::RaiseBridge() : Command("RaiseBridge") { }

RaiseBridge::~RaiseBridge() { }

void RaiseBridge::Initialize()
{
    if (Robot::bridge) Robot::bridge->Set(DoubleSolenoid::kReverse);
}

void RaiseBridge::Execute()
{
    return;
}

bool RaiseBridge::IsFinished()
{
    return !(Robot::bridge && Robot::bridge->IsMoving());
}

void RaiseBridge::End()
{
    return;
}

void RaiseBridge::Interrupted()
{
    return;
}

