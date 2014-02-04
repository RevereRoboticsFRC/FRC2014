#import "AuxDrive.h"
#import "../Utils/RobotMath.h"
#import "WPILib.h"
/*
 * AuxDrive.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Vince
 */

AuxDrive::AuxDrive(Joystick* joy) {
	winchMotor = new Jaguar(3);
	winchMotor->SetSafetyEnabled(false);
	winchLimSwitchHigh = new DigitalInput(3);
	winchLimSwitchLow = new DigitalInput(8);
	joystick = joy;
}

void AuxDrive::WinchDrive(float f) {
	f = Clamp(-1.0, 1.0, f);
	SmartDashboard::PutNumber("WinchSpd", -f);
	bool switchHigh = winchLimSwitchHigh->Get();
	bool switchLow = winchLimSwitchLow->Get();
	SmartDashboard::PutBoolean("WinchLimSwitchHigh", switchHigh);
	SmartDashboard::PutBoolean("WinchLimSwitchLow", switchLow);
	
	winchMotor->SetSpeed(f);
}

void AuxDrive::WinchStop() {
	winchMotor->StopMotor();
}

void AuxDrive::TeleopTick(unsigned int tickCount) {
	if(joystick->GetRawButton(2)) {
		WinchDrive(joystick->GetY(Joystick::kRightHand));
	}
}

void AuxDrive::Stop() {
	WinchStop();
}
