#import "WPILib.h"

class AuxDrive {
	Jaguar* winchMotor;
	DigitalInput* winchLimSwitchHigh;
	DigitalInput* winchLimSwitchLow;
	Joystick* joystick;
	
public:
	AuxDrive(Joystick*);
	
	void WinchDrive(float);
	void WinchStop();
	
	void TeleopTick(unsigned int);
	
	void Stop();
};
