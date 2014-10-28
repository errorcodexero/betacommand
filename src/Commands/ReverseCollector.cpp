#include "ReverseCollector.h"
#include "../Robot.h"


ReverseCollector::ReverseCollector() : Command("ReverseCollector") { }

ReverseCollector::~ReverseCollector() { }

void ReverseCollector::Initialize()
{
    if (Robot::collector) Robot::collector->Set(-1.0);
}

void ReverseCollector::Execute()
{
    return;
}

bool ReverseCollector::IsFinished()
{
    return true;
}

void ReverseCollector::End()
{
    return;
}

void ReverseCollector::Interrupted()
{
    return;
}

