#include "StartShooter.h"
#include "../Robot.h"


StartShooter::StartShooter() : Command("StartShooter") { }

StartShooter::~StartShooter()
{
    Requires(Robot::shooter);
}

void StartShooter::Initialize()
{
    if (Robot::shooter) Robot::shooter->Start();
}

void StartShooter::Execute()
{
    if (Robot::shooter) Robot::shooter->Run();
}

bool StartShooter::IsFinished()
{
    return (Robot::shooter && Robot::shooter->IsUpToSpeed());
}

void StartShooter::End()
{
    return;
}

void StartShooter::Interrupted()
{
    if (Robot::shooter) Robot::shooter->Stop();
}

