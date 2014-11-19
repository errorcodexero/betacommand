#include "OpenFingers.h"
#include "../Robot.h"


OpenFingers::OpenFingers() : Command("OpenFingers") { }

OpenFingers::~OpenFingers() { }

void OpenFingers::Initialize()
{
    if (Robot::fingers) Robot::fingers->Set(true);
}

void OpenFingers::Execute()
{
    return;
}

bool OpenFingers::IsFinished()
{
    return !(Robot::fingers && Robot::fingers->IsMoving());
}

void OpenFingers::End()
{
    return;
}

void OpenFingers::Interrupted()
{
    return;
}

