#include "Driver.h"
#include "../Utils/RobotMath.h"

Driver::Driver(int leftPort, int rightPort) {
	disabled = false;
	leftMotor = new Victor(leftPort);
	rightMotor = new Victor(rightPort);
	
}

void Driver::Drive(float left, float right) {
	if(disabled) {
		leftMotor->StopMotor();
		rightMotor->StopMotor();
		return;
	}
	left = Clamp(-1.0, 1.0, left);
	right = Clamp(-1.0, 1.0, right);
	SmartDashboard::PutNumber("motorSpdLeft", left);
	SmartDashboard::PutNumber("motorSpdRight", right);
	leftMotor->SetSpeed(left);
	rightMotor->SetSpeed(right);
}

void Driver::Stop() {
	leftMotor->StopMotor();
	rightMotor->StopMotor();
}

void Driver::SetSafetyEnabled(bool enabled) {
	leftMotor->SetSafetyEnabled(enabled);
	rightMotor->SetSafetyEnabled(enabled);
}
bool Driver::IsSafetyEnabled() {
	return leftMotor->IsSafetyEnabled() && rightMotor->IsSafetyEnabled();
}

void Driver::SetExpiration(float f) {
	leftMotor->SetExpiration(f);
	rightMotor->SetExpiration(f);
}

float Driver::GetExpiration() {
	return leftMotor->GetExpiration();
}
