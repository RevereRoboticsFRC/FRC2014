#import "Driver.h"
#import "WPILib.h"
#import "AuxDrive.h"
#import "../Utils/Logger.h"

class RobotController {
	Driver* driver;
	Joystick* joystick;
	AuxDrive* auxDrive;
	Logger* logger;
	void Drive();
	void TankSpin();
	void Winch();
public:
	RobotController(Logger*, Driver*, Joystick*);
	void TeleopTick(unsigned int);
};
