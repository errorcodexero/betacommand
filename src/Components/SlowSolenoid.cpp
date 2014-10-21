// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include "SlowSolenoid.h"

SlowSolenoid::SlowSolenoid( uint32_t channel, float extendTime, float retractTime,
				bool initialPosition )
    : Solenoid( channel )
{
    m_extendTime = extendTime;
    m_retractTime = retractTime;
    if (initialPosition) {
	Solenoid::Set(true);
	m_position = 1.0;
    } else {
	Solenoid::Set(false);
	m_position = 0.0;
    }
    m_startTime = 0;
    m_moving = false;
}

SlowSolenoid::~SlowSolenoid()
{
    ;
}

void SlowSolenoid::SetExtendTime( float extendTime )
{
    m_extendTime = extendTime;
}

void SlowSolenoid::SetRetractTime( float retractTime )
{
    m_retractTime = retractTime;
}

float SlowSolenoid::GetExtendTime()
{
    return m_extendTime;
}

float SlowSolenoid::GetRetractTime()
{
    return m_retractTime;
}

void SlowSolenoid::Set( bool on )
{
    UpdatePosition();
    Solenoid::Set(on);
    m_moving = true;
}

bool SlowSolenoid::Get()
{
    return Solenoid::Get();
}

float SlowSolenoid::GetPosition()
{
    UpdatePosition();
    return m_position;
}

bool SlowSolenoid::IsMoving()
{
    UpdatePosition();
    return m_moving;
}

void SlowSolenoid::UpdatePosition()
{
    if (m_moving) {
	uint32_t now = GetFPGATime();
	float deltaTime = (now - m_startTime) * 1.0e-6;
	float newPosition;

	if (Get()) {
	    // extending
	    newPosition = m_position + deltaTime / m_extendTime;
	    if (newPosition > 1.0) {
		newPosition = 1.0;
		m_moving = false;
	    }
	} else {
	    // retracting
	    newPosition = m_position - deltaTime / m_retractTime;
	    if (newPosition < 0.0) {
		newPosition = 0.0;
		m_moving = false;
	    }
	}
	m_position = newPosition;
	m_startTime = now;
    }
}

