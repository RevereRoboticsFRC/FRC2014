#import "Driver.h"
#import "WPILib.h"
#import "AuxDrive.h"
#import "../Utils/Logger.h"

class RobotController {
	Driver* driver;
	Joystick* joystick;
	Logger* logger;
	AuxDrive* auxDrive;
	void Drive();
	void TankSpin();
public:
	RobotController(Logger*, Driver*, AuxDrive*, Joystick*);
	void TeleopTick(unsigned int);
};
