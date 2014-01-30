#import "WPILib.h"

class AuxDrive {
	Jaguar* winchMotor;
	
public:
	AuxDrive();
	
	void WinchDrive(float);
	void WinchStop();
	
	void Tick();
};
