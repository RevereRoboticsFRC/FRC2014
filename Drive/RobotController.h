#import "Driver.h"
#import "WPILib.h"

class RobotController {
	Driver* driver;
	Joystick* joystick;
public:
	RobotController(Driver*, Joystick*);
	void TeleopTick();
};
