// FIRST Team 1425 "Error Code Xero"
// for FRC 2013 game "Ultimate Ascent"
#pragma once
#include "WPILib.h"

// turn-rate gyro connected to an analog input channel

class RateGyro : public AnalogInput {
private:
	float m_zero;

public:
	explicit RateGyro(uint32_t channel);

	void Zero();
	float GetRate();	// in degrees per second

private:
	void InitChannel();
};
