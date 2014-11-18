// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"
#pragma once
#include <WPILib.h>
#include <ErrorBase.h>
#include <RobotDrive.h>

class SpeedController;

// RobotDrive extension for 3-wheel holonomic drive

class RobotDrive3 : public RobotDrive
{
public:
    RobotDrive3(uint32_t frontMotorChannel, uint32_t rearLeftMotorChannel,
		uint32_t rearRightMotorChannel);
    RobotDrive3(SpeedController *frontMotor, SpeedController *rearLeftMotor,
		SpeedController *rearRightMotor);
    RobotDrive3(SpeedController &frontMotor, SpeedController &rearLeftMotor,
		SpeedController &rearRightMotor);

    void HolonomicDrive_Cartesian(float x, float y, float rotation );

private:
    double m_lastSpeeds[kMaxNumberOfMotors];
    DISALLOW_COPY_AND_ASSIGN(RobotDrive3);
};
