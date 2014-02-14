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
<<<<<<< HEAD
=======
	//	SmartDashboard::PutBoolean("WinchLimSwitchHigh", switchHigh);
	//	SmartDashboard::PutBoolean("WinchLimSwitchLow", switchLow);
>>>>>>> 518f0d8c4364f0b96190d45bcc827e46d6224afc
	if ((switchHigh && f < 0.0) || (switchLow && f > 0.0)) {
		winchMotor->StopMotor();
	} else {
		winchMotor->SetSpeed(f);
	}
}

void AuxDrive::WinchStop() {
	winchMotor->StopMotor();
}

<<<<<<< HEAD
void AuxDrive::DebugTick(unsigned int tickCount) {
=======
void AuxDrive::TeleopTick(unsigned int tickCount) {
>>>>>>> 518f0d8c4364f0b96190d45bcc827e46d6224afc
	bool switchHigh = winchLimSwitchHigh->Get();
	bool switchLow = winchLimSwitchLow->Get();
	SmartDashboard::PutBoolean("WinchLimSwitchHigh", switchHigh);
	SmartDashboard::PutBoolean("WinchLimSwitchLow", switchLow);
<<<<<<< HEAD
	SmartDashboard::PutNumber("WinchSpeed", winchMotor->Get());
=======
>>>>>>> 518f0d8c4364f0b96190d45bcc827e46d6224afc
}

void AuxDrive::Stop() {
	WinchStop();
}
