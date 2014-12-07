#import "WPILib.h"

#ifndef AUXDRIVE_H
#define AUXDRIVE_H

class AuxDrive {
	Jaguar* winchMotor;
	Joystick* joystick;

public:
	DigitalInput* winchLimSwitchHigh;
	DigitalInput* winchLimSwitchLow;
	AuxDrive(Joystick*);

	void WinchDrive(float);
	void WinchStop();

	void DebugTick(unsigned int);

	void Stop();
};
#endif
