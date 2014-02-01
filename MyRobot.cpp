#include "WPILib.h"
#include "Drive/RobotController.h"
#include "Utils/Logger.h"
#include "Utils/RobotMath.h"
#include "Drive/Driver.h"

#define VERSION "1.01"
#define TEAM_NUMBER "Team 5249"
#define TICK_LENGTH 20.0

//Test comment

class RevereRobot: public IterativeRobot {

	Logger* logger;
	RobotController* controller;
	Driver* driver;
	//	Sanity timer
//	Timer* timer;

	unsigned int modeTickCount;

public:
	RevereRobot() {
		logger = new Logger(FINE, "RevereBot");
		driver = new Driver(1, 2);
		controller = new RobotController(logger, driver, new Joystick(1));
//		timer = new Timer();
		ResetTick();

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
//		driver->SetDisabled(true);
		driver->SetSafetyEnabled(true);
		ResetTick();
		logger->Info("Finished disabled mode init.");
	}

	/**
	 * Periodic code for disabled mode.
	 * Do nothing but feed the doggy.
	 */
	void RevereRobot::DisabledPeriodic() {
		OnTick();
	}

	/**
	 * Initialization code for autonomous mode.
	 */
	void RevereRobot::AutonomousInit() {
		logger->Info("Auton mode init.");
		driver->Stop();
//		driver->SetDisabled(false);
		driver->SetSafetyEnabled(false);
		ResetTick();
		logger->Info("Finished auton mode init.");
	}

	/**
	 * Periodic code for autonomous mode.
	 */
	void RevereRobot::AutonomousPeriodic() {
		OnTick();
		driver->Drive(0.25, 0.25);
	}

	/**
	 * Initialization code for teleop mode.
	 */
	void RevereRobot::TeleopInit() {
		logger->Info("Teleop mode init.");
		driver->Stop();
//		driver->SetDisabled(false);
		driver->SetSafetyEnabled(true);
		driver->SetExpiration(0.5);
		ResetTick();
		logger->Info("Finished teleop mode init.");
	}

	/**
	 * Periodic code for teleop mode.
	 */
	void RevereRobot::TeleopPeriodic() {
		OnTick();
		controller->TeleopTick(modeTickCount);
	}

	/**
	 * Initialization code for test mode.
	 */
	void RevereRobot::TestInit() {
		logger->Info("Test mode init.");
		driver->Stop();
//		driver->SetDisabled(false);
		driver->SetSafetyEnabled(true);
		driver->SetExpiration(0.5);
		ResetTick();
		logger->Info("Finished test mode init.");
	}

	/**
	 * Periodic code for test mode.
	 */
	void RevereRobot::TestPeriodic() {
		OnTick();
		//	Temporary: Test motors same speed for 1 second
		if (IsInRange(0.0, 1.0, TicksToSeconds(modeTickCount))) {
			driver->Drive(0.25, 0.25);
		}
		//	Stop for 1 second
		if (IsInRange(1.0, 2.0, TicksToSeconds(modeTickCount))) {
			driver->Stop();
		}
		//	Then go backwards 1 second
		else if (IsInRange(2.0, 3.0, TicksToSeconds(modeTickCount))) {
			driver->Drive(-0.25, -0.25);
		}
		//	Then stop for another second
		else if (IsInRange(4.0, 5.0, TicksToSeconds(modeTickCount))) {
			driver->Stop();
		}
		//	Teleop
//		else {
//			//	Can't just call TeleopPeriodic(), will cause double-ticking!
//			controller->TeleopTick();
//		}

	}

	/**
	 * Updates the tick system. Should be called by all xxxPeriodic() methods.
	 */
	void RevereRobot::OnTick() {
		//	We don't care about overflow behavior because it would take 4,294,967,295 ticks of 20ms 
		//  each to overflow, giving us 85,899,345.9 seconds (or 23,860 hours, which is 994 days, or 3 years)
		//	of continuous operation per mode.
		//	16 bits would only give 65,535 ticks, or about 20 minutes of operation. 
		modeTickCount++;

		m_watchdog.Feed();
	}

	unsigned int RevereRobot::SecondsToTicks(float seconds) {
		//	Ensure seconds is non-negative and flip sign if that's the case (should we really do this?)
		if (seconds < 0.0) {
			seconds *= -1.0;
		}
		//	   seconds->millis->ticks
		return (unsigned int) (seconds * 1000.0 / TICK_LENGTH);
	}

	float RevereRobot::TicksToSeconds(unsigned int ticks) {
		//	Ticks will always be negative! Yay!
		//	   ticks->millis->seconds
		return ticks * TICK_LENGTH / 1000.0;
	}

	/**
	 * Resets the tick system for the mode change. Should be called by all xxxInit() methods.
	 */
	void RevereRobot::ResetTick() {
		modeTickCount = 0;
//		timer->Stop();
//		timer->Reset();
//		timer->Start();
	}

	/**
	 * Destructor
	 */
	RevereRobot::~RevereRobot() {
		logger->All("Main Destructor");
		delete controller;
		controller = NULL;
		delete driver;
		driver = NULL;
		delete logger;
		logger = NULL;
//		delete timer;
//		timer = NULL;
	}

};

START_ROBOT_CLASS(RevereRobot)
;

