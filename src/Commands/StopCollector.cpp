#include "StopCollector.h"


StopCollector::StopCollector() : Command("StopCollector") { }

StopCollector::~StopCollector() { }

void StopCollector::Initialize()
{
    if (Robot::collector) Robot::collector->Set(Relay::kOff);
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

