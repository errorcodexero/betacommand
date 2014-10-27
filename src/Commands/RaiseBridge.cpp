#include "RaiseBridge.h"


RaiseBridge::RaiseBridge() : Command("RaiseBridge") { }

RaiseBridge::~RaiseBridge() { }

void RaiseBridge::Initialize()
{
    if (Robot::bridge) Robot::bridge->Set(false);
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

