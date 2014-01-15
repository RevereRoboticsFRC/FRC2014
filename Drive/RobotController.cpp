#include "RobotController.h"
#include "../Utils/RobotMath.h"

RobotController::RobotController(Driver* d, Joystick* j) {
	driver = d;
	joystick = j;
}

void RobotController::TeleopTick() {
	//	Magnitude varies between 0.0 and 1.0, but due to joystick error may exceed 1.0
	float magnitude = Clamp(0.0, 1.0, joystick->GetMagnitude());
	//	Direction varies between +/-0.0 and +/-180 degrees: -90 is left, +90 right.
	float directionDeg = joystick->GetDirectionDegrees();

	//	TODO: Input curve mapping and tank drive logic/math goes here
	
	//	Test for now: Drive straight
	//	Invert magnitude if y is negative (past +/-90 towards +/-180)
	if(directionDeg > 90.0 || directionDeg < -90.0) {
		magnitude = -magnitude;
	}
	driver->Drive(magnitude, magnitude);
}

