#include "WPILib.h"
#include "Utils/Logger.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The IterativeRobot class is the base of a robot application that will automatically call your
 * Periodic methods for each packet based on the mode.
 */ 
class RobotDemo : public IterativeRobot
{
	Logger* logger;
	
	RobotDrive* myRobot; 	// robot drive system
	Joystick* stick; 		// only joystick

public:
	RobotDemo()
	{
		logger = new Logger(FINE, "RevereBot");
		myRobot = new RobotDrive(1, 2);
		stick = new Joystick(1);
		
		myRobot->SetExpiration(0.1);
		this->SetPeriod(0); 			//Set update period to sync with robot control packets (20ms nominal)
	}
	
/**
 * Robot-wide initialization code should go here.
 * 
 * Use this method for default Robot-wide initialization which will
 * be called when the robot is first powered on.  It will be called exactly 1 time.
 */
void RobotDemo::RobotInit() {
	logger->Info("Robot global init.");
	myRobot->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	myRobot->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	
	logger->Info("Done init.");
}

/**
 * Initialization code for disabled mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters disabled mode. 
 */
void RobotDemo::DisabledInit() {
	logger->Info("Disabled mode init.");
}

/**
 * Periodic code for disabled mode should go here.
 * 
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in disabled mode.
 */
void RobotDemo::DisabledPeriodic() {
}

/**
 * Initialization code for autonomous mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters autonomous mode.
 */
void RobotDemo::AutonomousInit() {
	logger->Info("Auton mode init.");
}

/**
 * Periodic code for autonomous mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in autonomous mode.
 */
void RobotDemo::AutonomousPeriodic() {
}

/**
 * Initialization code for teleop mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters teleop mode.
 */
void RobotDemo::TeleopInit() {
	logger->Info("Teleop mode init.");
}

/**
 * Periodic code for teleop mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in teleop mode.
 */
void RobotDemo::TeleopPeriodic() {
//	float directionDegrees = stick->GetDirectionDegrees();
//	float directionMagnitude = stick->GetMagnitude();
//	
//	SmartDashboard::PutNumber("Degress", directionDegrees);
//	SmartDashboard::PutNumber("Mag", directionMagnitude);
//	
//	//	Filter values lower than 0.06 for mag
//	if(directionMagnitude < 0.06) {
//		myRobot->Drive(0, 0);
//		return;
//	}
//	
//	myRobot->Drive(directionMagnitude, directionDegrees/360.0);
//	myRobot->ArcadeDrive(directionMagnitude, directionDegrees, false); 
}

/**
 * Initialization code for test mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters test mode.
 */
void RobotDemo::TestInit() {
	logger->Info("Test mode init.");
}

/**
 * Periodic code for test mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in test mode.
 */
void RobotDemo::TestPeriodic() {
}

/*
 * Destructor
 */
	~RobotDemo() {
		logger->All("Main Destructor");
		delete stick;
		delete myRobot;
		delete logger;
	}

};

START_ROBOT_CLASS(RobotDemo);

