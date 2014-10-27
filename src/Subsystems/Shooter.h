#include <WPILib.h>
#include "../Components/Tachometer.h"
#include "../Components/TwoMotor.h"

#ifndef _SHOOTER_H_
#define _SHOOTER_H_

#define	minRPM		(250.)
#define	maxRPM		(3800.)
#define	kStartSpeed	(800.)
#define	kStartOut	(0.6)
#define	kP		(1.0/maxRPM)
#define	kI		(0.05/maxRPM)
#define	kD		(0.0)
#define	kF		(1.0/maxRPM)
#define	kPeriod		(0.1)
#define	kTolerance 	(0.03)

class Shooter : public Subsystem
{
private:
	TwoMotor<CANJaguar> *m_bottomMotor;
	Tachometer *m_bottomTach;
	PIDController *m_bottomPID;

	TwoMotor<CANJaguar> *m_topMotor;
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
	Shooter( TwoMotor<CANJaguar> *bottomMotor, Tachometer *bottomTach,
		 TwoMotor<CANJaguar> *topMotor, Tachometer *topTach );
	~Shooter();

	void Set( float bottomSpeed, float topSpeed );

	void Start();
	void Stop();
	void Run();
	bool IsMoving();
	bool IsUpToSpeed();
};


#endif // _SHOOTER_H_
