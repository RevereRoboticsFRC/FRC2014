#include "RobotController.h"
#include "../Utils/RobotMath.h"
#include <cmath>

#define PI 3.14159

float abs(float);


RobotController::RobotController(Driver* d, Joystick* j) {
	driver = d;
	joystick = j;
	auxDrive = new AuxDrive();
}

void debugOut(Joystick* joy) {
	SmartDashboard::PutNumber("JoyDeg", joy->GetDirectionDegrees());
	SmartDashboard::PutNumber("JoyMag", joy->GetMagnitude());
	SmartDashboard::PutNumber("JoyX", joy->GetX(Joystick::kRightHand));
	SmartDashboard::PutNumber("JoyY", joy->GetY(Joystick::kRightHand));
	SmartDashboard::PutNumber("JoyZ", joy->GetZ());
	SmartDashboard::PutNumber("Throttle", joy->GetThrottle());
	SmartDashboard::PutNumber("Twist", joy->GetTwist());
	SmartDashboard::PutBoolean("Trigger", joy->GetRawButton(1));
	SmartDashboard::PutBoolean("ThumbRestButton", joy->GetRawButton(2));
}

void RobotController::TeleopTick(unsigned int tickCount) {
	if (tickCount % 25 == 0) {
		debugOut(joystick);
	}

	//	TEMP WINCH STUFFS
	if (joystick->GetRawButton(2)) {
		Winch();
	} else {
		auxDrive->WinchStop();
		if(joystick->GetRawButton(1)) {
//			TankSpin();
		} else {
//			Drive();
		}
	}
}

void RobotController::Drive() {
	//	Hybrid method (Excel proven)
	float directionDeg = joystick->GetDirectionDegrees();
	//	Joystick returns trig-correct values, no need to correct them
	float directionRads = directionDeg * PI / 180.0;
	
	//	Temporary 0.32 to compensate for motor startup
	float magnitude = joystick->GetMagnitude();
	if (magnitude > 0.15) {
		magnitude += 0.32;
	}
	//	Input curve fitting
	//	1.5 power magnitude for better "feels" at low speeds
	magnitude = pow(Clamp(0.0, 1.0, magnitude), 1.5);

	float x = cos(directionRads) * magnitude;
	float y = sin(directionRads) * magnitude;
	
	float u = (1 - abs(x)) * y + y;
	float v = (1 - abs(y)) * x + x;
	float left = (u - v) / 2.0;
	float right = (u + v) / 2.0;
	driver->Drive(left, right);
}

void RobotController::TankSpin() {
	float x = joystick->GetX(Joystick::kRightHand);
	//	Right is + (CW), left is - (CCW)
	float sign = (x > 0 ? 1.0 : -1.0);
	float mag = Clamp(0.0, 1.0, abs(x));
	driver->Drive(mag * sign, mag * -sign);
}

void RobotController::Winch() {
	float y = joystick->GetY(Joystick::kRightHand);
	//	Forward is +, up
	auxDrive->WinchDrive(Clamp(-1.0, 1.0, y));
}

float abs(float f) {
	if (f < 0.0) {
		return -f;
	}
	return f;
}

