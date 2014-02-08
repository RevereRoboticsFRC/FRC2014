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
	winchLimSwitchHigh = new DigitalInput(1);
	winchLimSwitchLow = new DigitalInput(2);
	joystick = joy;
}

void AuxDrive::WinchDrive(float f) {
	f = Clamp(-1.0, 1.0, f);
	bool switchHigh = winchLimSwitchHigh->Get();
	bool switchLow = winchLimSwitchLow->Get();
	SmartDashboard::PutBoolean("WinchLimSwitchHigh", switchHigh);
	SmartDashboard::PutBoolean("WinchLimSwitchLow", switchLow);
	if ((switchHigh && f < 0.0) || (switchLow && f > 0.0)) {
		winchMotor->StopMotor();
	} else {
		winchMotor->SetSpeed(f);
	}
	SmartDashboard::PutNumber("WinchSpeed", winchMotor->Get());
}

void AuxDrive::WinchStop() {
	winchMotor->StopMotor();
}

void AuxDrive::TeleopTick(unsigned int tickCount) {
	
}

void AuxDrive::Stop() {
	WinchStop();
}
