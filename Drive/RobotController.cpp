#include "RobotController.h"
#include "../Utils/RobotMath.h"
#include <cmath>

#define PI 3.14159

float abs(float);

RobotController::RobotController(Driver* d, Joystick* j) {
	driver = d;
	joystick = j;
}

void RobotController::TeleopTick() {
	//	//	Polar method
	//	//	Magnitude varies between 0.0 and 1.0, but due to joystick error may exceed 1.0
	//	float magnitude = Clamp(0.0, 1.0, joystick->GetMagnitude());
	//	//	Direction varies between +/-0.0 and +/-180 degrees: -90 is left, +90 right.
	//	float directionDeg = joystick->GetDirectionDegrees();
	//	//	TODO: Input curve mapping
	//	
	//	//	Invert magnitude if y is negative (past +/-90 towards +/-180)
	//	if(directionDeg > 90.0 || directionDeg < -90.0) {
	//		magnitude = -magnitude;
	//	}
	//	driver->Drive(magnitude, magnitude);

	//	//	Cartesian method
	//	float joyX = Clamp(-1.0, 1.0, joystick->GetX(Joystick::kRightHand));
	//	float joyY = Clamp(-1.0, 1.0, joystick->GetY(Joystick::kRightHand));
	//	float magnitude = Clamp(0.0, 1.0, joystick->GetMagnitude());
	//	//	TODO: Input curve mapping
	//
	//	//	And tank drive logic/math goes here
	//	float u = (1 - abs(joyX)) * joyY + joyY;
	//	float v = (1 - abs(joyY)) * joyX + joyX;
	//	float right = (u + v)/2.0;
	//	float left  = (u - v)/2.0;
	//	driver->Drive(left, right);

	//	Hybrid method (Excel proven)
	float directionDeg = joystick->GetDirectionDegrees();
	directionDeg += 90.0;
	//	If we go past 180 degrees, wrap around to the negative complement (e.g. 190 -> -170)
	if(directionDeg > 180.0) {
		directionDeg = -180.0 + (directionDeg - 180.0);
	}
	float directionRads = directionDeg * PI / 180.0;
	float magnitude = Clamp(0.0, 1.0, joystick->GetMagnitude());
	float x = cos(directionRads) * magnitude;
	float y = sin(directionRads) * magnitude;
	float u = (1-abs(x))*y + y;
	float v = (1-abs(y))*x + x;
	float left = (u - v)/2.0;
	float right = (u + v)/2.0;
	driver->Drive(left, right);
}

float abs(float f) {
	if(f < 0.0) {
		return -f;
	}
	return f;
}

