#include "StopCollector.h"
#include "../Robot.h"


StopCollector::StopCollector() : Command("StopCollector") { }

StopCollector::~StopCollector() { }

void StopCollector::Initialize()
{
    if (Robot::collector) Robot::collector->Set(0.0);
}

void StopCollector::Execute()
{
    return;
}

bool StopCollector::IsFinished()
{
    return true;
}

void StopCollector::End()
{
    return;
}

void StopCollector::Interrupted()
{
    return;
}

