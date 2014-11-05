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

SlowDoubleSolenoid::SlowDoubleSolenoid( uint32_t fwdChannel, uint32_t revChannel,
					float extendTime, float retractTime,
					DoubleSolenoid::Value initialPosition )
    : DoubleSolenoid( fwdChannel, revChannel )
{
    m_extendTime = extendTime;
    m_retractTime = retractTime;
    DoubleSolenoid::Set(initialPosition);
    switch (initialPosition) {
    case kForward:
	m_position = 1.0;
	break;
    case kReverse:
	m_position = 0.0;
	break;
    case kOff:
	m_position = 0.0;
	break;
    }
    m_startTime = 0;
    m_moving = false;
}

SlowDoubleSolenoid::~SlowDoubleSolenoid()
{
    ;
}

void SlowDoubleSolenoid::SetExtendTime( float extendTime )
{
    m_extendTime = extendTime;
}

void SlowDoubleSolenoid::SetRetractTime( float retractTime )
{
    m_retractTime = retractTime;
}

float SlowDoubleSolenoid::GetExtendTime()
{
    return m_extendTime;
}

float SlowDoubleSolenoid::GetRetractTime()
{
    return m_retractTime;
}

void SlowDoubleSolenoid::Set( DoubleSolenoid::Value value )
{
    UpdatePosition();
    DoubleSolenoid::Set(value);
    m_moving = (value != kOff);
}

DoubleSolenoid::Value SlowDoubleSolenoid::Get()
{
    return DoubleSolenoid::Get();
}

float SlowDoubleSolenoid::GetPosition()
{
    UpdatePosition();
    return m_position;
}

bool SlowDoubleSolenoid::IsMoving()
{
    UpdatePosition();
    return m_moving;
}

void SlowDoubleSolenoid::UpdatePosition()
{
    if (m_moving) {
	uint32_t now = GetFPGATime();
	float deltaTime = (now - m_startTime) * 1.0e-6;
	float newPosition;

	switch (Get()) {
	case kForward:
	    // extending
	    newPosition = m_position + deltaTime / m_extendTime;
	    if (newPosition > 1.0) {
		newPosition = 1.0;
		m_moving = false;
	    }
	    break;
	case kReverse:
	    // retracting
	    newPosition = m_position - deltaTime / m_retractTime;
	    if (newPosition < 0.0) {
		newPosition = 0.0;
		m_moving = false;
	    }
	    break;
	case kOff:
	    newPosition = m_position;
	    m_moving = false;
	    break;
	}
	m_position = newPosition;
	m_startTime = now;
    }
}

