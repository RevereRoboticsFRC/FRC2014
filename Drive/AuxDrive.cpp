#import "AuxDrive.h"
#import "../Utils/RobotMath.h"
#import "WPILib.h"
/*
 * AuxDrive.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: Vince
 */

AuxDrive::AuxDrive() {
	winchMotor = new Jaguar(3);
	winchMotor->SetSafetyEnabled(false);
}

void AuxDrive::WinchDrive(float f) {
	f = Clamp(-1.0, 1.0, f);
	SmartDashboard::PutNumber("WinchSpd", -f);
	winchMotor->SetSpeed(-f);
}

void AuxDrive::WinchStop() {
	winchMotor->StopMotor();
}

void AuxDrive::Tick() {

}
