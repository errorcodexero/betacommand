// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include <WPILib.h>
#include "InstrumentedJaguar.h"
#include <string>
#include <ostream>
#include <sstream>
#include <cstdio>

using namespace std;

InstrumentedJaguar::InstrumentedJaguar( uint8_t deviceNumber ) :
    CANJaguar(deviceNumber)
{
    std::ostringstream myName;
    myName << "Jag " << deviceNumber;
    m_V = myName.str() + " V";
    m_I = myName.str() + " I";
    SmartDashboard::PutNumber(m_V.c_str(), 0.);
    SmartDashboard::PutNumber(m_I.c_str(), 0.);
}

InstrumentedJaguar::~InstrumentedJaguar()
{
    ;
}

float InstrumentedJaguar::Get()
{
    float value = CANJaguar::Get();
    update();
    return value;
}

void InstrumentedJaguar::Set(float value, uint8_t syncGroup)
{
    CANJaguar::Set(value, syncGroup);
    update();
}

void InstrumentedJaguar::Disable()
{
    CANJaguar::Disable();
    update();
}

void InstrumentedJaguar::PIDWrite(float output)
{
    CANJaguar::PIDWrite(output);
    update();
}

void InstrumentedJaguar::update()
{
    SmartDashboard::PutNumber(m_V.c_str(), GetOutputVoltage());
    SmartDashboard::PutNumber(m_I.c_str(), GetOutputCurrent());
}
