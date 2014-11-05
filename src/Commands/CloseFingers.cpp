#include "CloseFingers.h"
#include "../Robot.h"


CloseFingers::CloseFingers() : Command("CloseFingers") { }

CloseFingers::~CloseFingers() { }

void CloseFingers::Initialize()
{
    if (Robot::fingers) Robot::fingers->Set(true);
}

void CloseFingers::Execute()
{
    return;
}

bool CloseFingers::IsFinished()
{
    return !(Robot::fingers && Robot::fingers->IsMoving());
}

void CloseFingers::End()
{
    return;
}

void CloseFingers::Interrupted()
{
    return;
}

