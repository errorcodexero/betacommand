// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"
#pragma once
#include <WPILib.h>
#include "../Components/InstrumentedJaguar.h"
#include "../Components/Tachometer.h"
#include "../Components/TwoMotor.h"

class Shooter : public Subsystem
{
private:
	SpeedController *m_bottomMotor;
	Tachometer *m_bottomTach;
	PIDController *m_bottomPID;

	SpeedController *m_topMotor;
	Tachometer *m_topTach;
	PIDController *m_topPID;

	float m_P, m_I, m_D, m_F, m_period;
	float m_bottomSet, m_topSet;
	float m_bottomSpeed, m_topSpeed;

	enum {
	    STOPPED,
	    BOTTOM,
	    TOP,
	    BOTH,
	} m_state;

public:
	Shooter( SpeedController *bottomMotor, Tachometer *bottomTach,
		 SpeedController *topMotor, Tachometer *topTach );
	~Shooter();

	void Set( float bottomSet, float topSet );

	void Start();
	void Stop();
	void Run();
	bool IsMoving();
	bool IsUpToSpeed();
};

