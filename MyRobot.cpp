#include "WPILib.h"
#include "Drive/RobotController.h"
#include "Utils/Logger.h"
#include "Drive/Driver.h"

#define VERSION "1.0 "
#define TEAM_NUMBER "Team 5249"


//Test comment

class RevereRobot: public IterativeRobot {

	Logger* logger;
	RobotController* controller;
	Driver* driver;
	//	Sanity timer
	Timer* timer;

public:
	RevereRobot() {
		logger = new Logger(FINE, "RevereBot");
		driver = new Driver(1, 2);
		controller = new RobotController(driver, new Joystick(1));
		timer = new Timer();
		
		//	Set update period to sync with robot control packets (20ms nominal)
		SetPeriod(0);
	}

	/**
	 * Robot-wide initialization. This will be called on robot startup and will only be called once.
	 */
	void RevereRobot::RobotInit() {
		logger->Info("Robot global init.");
		logger->All("==== REVERE FRC 2014 ====");
		logger->All(TEAM_NUMBER);
		logger->All(VERSION);
		logger->All(__DATE__);
		logger->All(__TIME__);
		logger->All("=========================");

		logger->Info("Finished global init.");
	}

	/**
	 * Initialization code for disabled mode
	 */
	void RevereRobot::DisabledInit() {
		logger->Info("Disabled mode init.");
		driver->Stop();
		driver->SetDisabled(true);
		driver->SetSafetyEnabled(true);
		logger->Info("Finished disabled mode init.");
	}

	/**
	 * Periodic code for disabled mode.
	 * Do nothing but feed the doggy.
	 */
	void RevereRobot::DisabledPeriodic() {
		m_watchdog.Feed();
	}

	/**
	 * Initialization code for autonomous mode.
	 */
	void RevereRobot::AutonomousInit() {
		logger->Info("Auton mode init.");
		driver->Stop();
		driver->SetDisabled(false);
		driver->SetSafetyEnabled(false);
		timer->Stop();
		timer->Reset();
		timer->Start();
		logger->Info("Finished auton mode init.");
	}

	/**
	 * Periodic code for autonomous mode.
	 */
	void RevereRobot::AutonomousPeriodic() {
		//For testing, allowing disable autonomous after one second
		//	Timer takes seconds as the argument
		if (timer->HasPeriodPassed(1.0)) {
			driver->SetDisabled(true);
		}
		m_watchdog.Feed();
		//Drive forward at one quarter speed 
		driver->Drive(0.25, 0.25);
	}

	/**
	 * Initialization code for teleop mode.
	 */
	void RevereRobot::TeleopInit() {
		logger->Info("Teleop mode init.");
		driver->Stop();
		driver->SetDisabled(false);
		driver->SetSafetyEnabled(true);
		driver->SetExpiration(0.5);
		logger->Info("Finished teleop mode init.");
	}

	/**
	 * Periodic code for teleop mode.
	 */
	void RevereRobot::TeleopPeriodic() {
		m_watchdog.Feed();
		controller->TeleopTick();
	}

	/**
	 * Initialization code for test mode.
	 */
	void RevereRobot::TestInit() {
		logger->Info("Test mode init.");
		driver->Stop();
		driver->SetDisabled(false);
		driver->SetSafetyEnabled(true);
		driver->SetExpiration(0.5);
		timer->Stop();
		timer->Reset();
		timer->Start();
		logger->Info("Finished test mode init.");
	}

	/**
	 * Periodic code for test mode.
	 */
	void RevereRobot::TestPeriodic() {
		//	Temporary: Test motors same speed for 1 second
		if(!timer->HasPeriodPassed(1.0)) {
			driver->Drive(0.25, 0.25);
		}
		//	Stop for 1 second
		else if(!timer->HasPeriodPassed(2.0)) {
			driver->Stop();
		}
		//	Then go backwards 1 second
		else if(!timer->HasPeriodPassed(3.0)) {
			driver->Drive(-0.25, -0.25);
		}
		//	Then stop for another second
		else if(!timer->HasPeriodPassed(4.0)){
			driver->Stop();
		}
		//	Teleop
		else {
			TeleopPeriodic();
		}
		
	}

	/**
	 * Destructor
	 */
	~RevereRobot() {
		logger->All("Main Destructor");
		delete controller;
		controller = NULL;
		delete driver;
		driver = NULL;
		delete logger;
		logger = NULL;
		delete timer;
		timer = NULL;
	}

};

START_ROBOT_CLASS(RevereRobot)
;

