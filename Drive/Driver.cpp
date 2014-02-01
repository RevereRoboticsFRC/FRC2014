#include "Driver.h"
#include "../Utils/RobotMath.h"

Driver::Driver(int rightPortNum, int leftPortNum) {
	disabled = false;
	m_rightMotor = new Victor(rightPortNum);
	m_leftMotor = new Victor(leftPortNum);
	
}

void Driver::Drive(float rightSpeed, float leftSpeed) {
	if(disabled) {
		m_rightMotor->StopMotor();
		m_leftMotor->StopMotor();
		return;
	}
	rightSpeed = Clamp(-1.0, 1.0, rightSpeed);
	leftSpeed = Clamp(-1.0, 1.0, leftSpeed);
	SmartDashboard::PutNumber("motorSpdLeft", rightSpeed);
	SmartDashboard::PutNumber("motorSpdRight", leftSpeed);
	m_rightMotor->SetSpeed(-rightSpeed);
	m_leftMotor->SetSpeed(leftSpeed);
}

void Driver::Stop() {
	m_rightMotor->StopMotor();
	m_leftMotor->StopMotor();
}

void Driver::SetSafetyEnabled(bool enabled) {
	m_rightMotor->SetSafetyEnabled(enabled);
	m_leftMotor->SetSafetyEnabled(enabled);
}
bool Driver::IsSafetyEnabled() {
	return m_rightMotor->IsSafetyEnabled() && m_leftMotor->IsSafetyEnabled();
}

void Driver::SetExpiration(float f) {
	m_rightMotor->SetExpiration(f);
	m_leftMotor->SetExpiration(f);
}

float Driver::GetExpiration() {
	return m_rightMotor->GetExpiration();
}
