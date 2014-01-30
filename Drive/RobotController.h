#import "Driver.h"
#import "WPILib.h"
#import "AuxDrive.h"

class RobotController {
	Driver* driver;
	Joystick* joystick;
	AuxDrive* auxDrive;
	void Drive();
	void TankSpin();
	void Winch();
public:
	RobotController(Driver*, Joystick*);
	void TeleopTick(unsigned int);
};
