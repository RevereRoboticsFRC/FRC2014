#include "RobotController.h"
#include "../Utils/RobotMath.h"
#include <cmath>

const float PI = 3.14159;
const float ANGLE_THRESH = 80.0;

float abs(float);

RobotController::RobotController(Logger* l, Driver* d, AuxDrive* a, Joystick* j) {
	driver = d;
	joystick = j;
	logger = l;
	auxDrive = a;
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
	if (tickCount % 5 == 0) {
		debugOut(joystick);
	}
	Drive();
}

void RobotController::Drive() {
	//	Hybrid method (Excel proven)
	float directionDeg = joystick->GetDirectionDegrees();

	SmartDashboard::PutNumber("CntrlDirectionRaw", directionDeg);

	//	TEMP TEST
	if (abs(directionDeg) <= ANGLE_THRESH) {
//		printf("LowDirection %f\n", directionDeg);
		//	-80 to +80
		//	Remap 0 to 80 to 0 to 45
		directionDeg = directionDeg / ANGLE_THRESH * 45.0;
	} else if (abs(directionDeg) < (180.0 - ANGLE_THRESH)) {
		//	Close to 90
		if (IsInRange(88, 92, abs(directionDeg))) {
//			printf("TankSpin\n");
			TankSpin();
		} else {
//			printf("MedDirection %f\n", directionDeg);
			//	-100 to -80 or +100 to +80
			//	Remap 80 to 100 to 45 to 135
			if (directionDeg > 0) {
				directionDeg = (directionDeg - 80) / 20.0 * 90.0 + 45.0;
			} else {
				directionDeg = (directionDeg + 80) / 20.0 * 90.0 - 45.0;
			}
		}
	} else {
		//	-180 to -100 or +180 to +100
		//	Remap 100 to 180 to 135 to 180
//		printf("HighDirection %f\n", directionDeg);
		if (directionDeg > 0) {
			directionDeg = (((directionDeg - 100.0) / ANGLE_THRESH) * 45.0)
					+ 135.0;
		} else {
			directionDeg = (((directionDeg + 100.0) / ANGLE_THRESH) * 45.0)
					- 135.0;
		}
	}

	SmartDashboard::PutNumber("CntrlDirectionAdj", directionDeg);

	//	Joystick returns trig-correct values, no need to correct them
	float directionRads = directionDeg * PI / -180.0;

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
	float right = (u - v) / 2.0;
	float left = (u + v) / 2.0;
	driver->Drive(-right, left);
}

void RobotController::TankSpin() {
	float x = Clamp(-1.0, 1.0, joystick->GetX(Joystick::kRightHand));
	// Right is + (CW), left is - (CCW)
	driver->Drive(x, x);
}
//
//void RobotController::Winch() {
//	float y = joystick->GetY(Joystick::kRightHand);
//	//	Forward is +, up
//	float mag = Clamp(-1.0, 1.0, y);
//	auxDrive->WinchDrive(mag);
//}

float abs(float f) {
	if (f < 0.0) {
		return -f;
	}
	return f;
}

