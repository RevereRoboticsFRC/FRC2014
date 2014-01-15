#include "WPILib.h"
#include "Drive/RobotController.h"
#include "Utils/Logger.h"
#include "Drive/Driver.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The IterativeRobot class is the base of a robot application that will automatically call your
 * Periodic methods for each packet based on the mode.
 */ 
class RobotDemo : public IterativeRobot
{
	Logger* logger;
	RobotController* controller;
	Driver* driver;

public:
	RobotDemo()
	{
		logger = new Logger(FINE, "RevereBot");
		driver = new Driver(1, 2);
		controller = new RobotController(driver, new Joystick(1));
		
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
	driver->Stop();
	driver->SetDisabled(true);
	driver->SetSafetyEnabled(true);
}

/**
 * Periodic code for disabled mode should go here.
 * 
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in disabled mode.
 */
void RobotDemo::DisabledPeriodic() {
	m_watchdog.Feed();
	
}

/**
 * Initialization code for autonomous mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters autonomous mode.
 */
void RobotDemo::AutonomousInit() {
	logger->Info("Auton mode init.");
	driver->Stop();
	driver->SetDisabled(false);
	driver->SetSafetyEnabled(false);
}

/**
 * Periodic code for autonomous mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in autonomous mode.
 */
void RobotDemo::AutonomousPeriodic() {
	m_watchdog.Feed();
	driver->Drive(0.25, 0.25);
}

/**
 * Initialization code for teleop mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters teleop mode.
 */
void RobotDemo::TeleopInit() {
	logger->Info("Teleop mode init.");
	driver->Stop();
	driver->SetDisabled(false);
	driver->SetSafetyEnabled(true);
	driver->SetExpiration(0.5);
}

/**
 * Periodic code for teleop mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in teleop mode.
 */
void RobotDemo::TeleopPeriodic() {
	m_watchdog.Feed();
	controller->TeleopTick();
}

/**
 * Initialization code for test mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters test mode.
 */
void RobotDemo::TestInit() {
	logger->Info("Test mode init.");
	driver->Stop();
}

/**
 * Periodic code for test mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in test mode.
 */
void RobotDemo::TestPeriodic() {
	m_watchdog.Feed();
}

/*
 * Destructor
 */
	~RobotDemo() {
		logger->All("Main Destructor");
		delete controller;
		delete driver;
		delete logger;
	}

};

START_ROBOT_CLASS(RobotDemo);

