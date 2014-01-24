#include "RobotController.h"
#include "../Utils/RobotMath.h"
#include <cmath>

#define PI 3.14159

float abs(float);

RobotController::RobotController(Driver* d, Joystick* j) {
	driver = d;
	joystick = j;
}

void debugOut(Joystick* joy) {
	SmartDashboard::PutNumber("JoyDeg", joy->GetDirectionDegrees());
	SmartDashboard::PutNumber("JoyMag", joy->GetMagnitude());
	SmartDashboard::PutNumber("JoyX", joy->GetX(Joystick::kRightHand));
	SmartDashboard::PutNumber("JoyY", joy->GetY(Joystick::kRightHand));
	SmartDashboard::PutNumber("JoyZ", joy->GetZ());
	SmartDashboard::PutNumber("Throttle", joy->GetThrottle());
	SmartDashboard::PutNumber("Twist", joy->GetTwist());
}

void RobotController::TeleopTick() {
	debugOut(joystick);
	//	Hybrid method (Excel proven)
	float directionDeg = joystick->GetDirectionDegrees();
	//	Joystick returns trig-correct values, no need to correct them
	float directionRads = directionDeg * PI / 180.0;
	//	Temporary 0.32 to compensate for motor startup
	float magnitude = Clamp(0.0, 1.0, joystick->GetMagnitude());
	if(magnitude > 0.025) {
		magnitude += 0.32;
	}
	
	//	Input curve fitting
	//	Square magnitude for better "feels" at low speeds
	magnitude = pow(magnitude, 1.5);
	
	float x = cos(directionRads) * magnitude;
	float y = sin(directionRads) * magnitude;
	//	TODO Reduce low turn sensitivity
	
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

