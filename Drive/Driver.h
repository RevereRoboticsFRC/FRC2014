#include "WPILib.h"

class Driver {
	Victor* m_rightMotor;
	Victor* m_leftMotor;
	bool disabled;
	
public:
	Driver(int leftPort, int rightPort);
	void Drive(float left, float right);
	
	void Stop();
	
	void SetSafetyEnabled(bool);
	bool IsSafetyEnabled();
	
	void SetExpiration(float);
	float GetExpiration();
	
};
