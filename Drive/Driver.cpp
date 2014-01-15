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
	leftMotor->SetSpeed(Clamp(-1.0, 1.0, left));
	rightMotor->SetSpeed(Clamp(-1.0, 1.0, right));
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

void Driver::SetDisabled(bool b) {
	disabled = b;
}
bool Driver::IsDisabled() {
	return disabled;
}

void Driver::SetExpiration(float f) {
	leftMotor->SetExpiration(f);
	rightMotor->SetExpiration(f);
}

float Driver::GetExpiration() {
	return leftMotor->GetExpiration();
}
