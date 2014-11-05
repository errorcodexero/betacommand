// FIRST Team 1425 "Error Code Xero"
// for FRC 2014 post-season "Aerial Assist"

#include <WPILib.h>

#ifndef _SLOW_SOLENOID_H_
#define _SLOW_SOLENOID_H_

class SlowSolenoid : public Solenoid
{
public:
	explicit SlowSolenoid(uint32_t channel, float extendTime, float retractTime, bool initialPosition = false);
	virtual ~SlowSolenoid();
	virtual void SetExtendTime(float extendTime);
	virtual void SetRetractTime(float retractTime);
	virtual float GetExtendTime();
	virtual float GetRetractTime();
	virtual void Set(bool on);
	virtual bool Get();
	virtual float GetPosition();
	virtual bool IsMoving();

private:
	float m_extendTime;
	float m_retractTime;
	float m_position;
	uint32_t m_startTime;
	bool m_moving;

	void UpdatePosition();
};

class SlowDoubleSolenoid : public DoubleSolenoid
{
public:
	explicit SlowDoubleSolenoid(uint32_t fwdChannel, uint32_t revChannel, float extendTime, float retractTime, DoubleSolenoid::Value initialPosition = kOff);
	virtual ~SlowDoubleSolenoid();
	virtual void SetExtendTime(float extendTime);
	virtual void SetRetractTime(float retractTime);
	virtual float GetExtendTime();
	virtual float GetRetractTime();
	virtual void Set(DoubleSolenoid::Value value);
	virtual DoubleSolenoid::Value Get();
	virtual float GetPosition();
	virtual bool IsMoving();

private:
	float m_extendTime;
	float m_retractTime;
	float m_position;
	uint32_t m_startTime;
	bool m_moving;

	void UpdatePosition();
};

#endif // _SLOW_SOLENOID_H_

