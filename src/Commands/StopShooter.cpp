#include "StopShooter.h"
#include "../Robot.h"


StopShooter::StopShooter() : Command("StopShooter") { }

StopShooter::~StopShooter()
{
    Requires(Robot::shooter);
}

void StopShooter::Initialize()
{
    if (Robot::shooter) Robot::shooter->Stop();
}

void StopShooter::Execute()
{
    if (Robot::shooter) Robot::shooter->Run();
}

bool StopShooter::IsFinished()
{
    // return !(Robot::shooter && Robot::shooter->IsMoving());
    return true;
}

void StopShooter::End()
{
    return;
}

void StopShooter::Interrupted()
{
    return;
}

