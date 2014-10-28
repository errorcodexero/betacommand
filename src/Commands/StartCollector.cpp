#include "StartCollector.h"
#include "../Robot.h"


StartCollector::StartCollector() : Command("StartCollector") { }

StartCollector::~StartCollector() { }

void StartCollector::Initialize()
{
    if (Robot::collector) Robot::collector->Set(1.0);
}

void StartCollector::Execute()
{
    return;
}

bool StartCollector::IsFinished()
{
    return true;
}

void StartCollector::End()
{
    return;
}

void StartCollector::Interrupted()
{
    return;
}

