#include "ReverseCollector.h"


ReverseCollector::ReverseCollector() : Command("ReverseCollector") { }

ReverseCollector::~ReverseCollector() { }

void ReverseCollector::Initialize()
{
    if (Robot::collector) Robot::collector->Set(Relay::kReverse);
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

