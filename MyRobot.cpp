#include "WPILib.h"
#include "Drive/RobotController.h"
#include "Utils/Logger.h"
#include "Utils/RobotMath.h"
#include "Drive/Driver.h"
#include "task/TickTask.h"
#include "task/WinchUpTickTask.cpp"
#include "task/WinchDownTickTask.cpp"

#define VERSION "L'AQUEHJJJESHAA REHWERE 2.1"
#define TEAM_NUMBER "Team 5249"
static const float TICK_LENGTH_MS = 20.0;
static const float TICK_LENGTH_SEC = 0.02;
static const bool USE_SYNC_TICK = false;

//Test comment

class RevereRobot: public IterativeRobot {

	Logger* logger;
	RobotController* controller;
	Driver* driver;
	AuxDrive* auxDrive;
	Joystick* joystick;

	TickTask* currentTask;

	unsigned int modeTickCount;
	unsigned int lastNewDataTick;
	bool newData;

public:
	RevereRobot() {
		joystick = new Joystick(1);
		logger = new Logger(FINE, "RevereBot");
		driver = new Driver(1, 2);
		auxDrive = new AuxDrive(joystick);
		controller = new RobotController(logger, driver, auxDrive, joystick);
		ResetTick();

		//	Set update period to sync with robot control packets (20ms nominal)
		if (USE_SYNC_TICK) {
			SetPeriod(0.0);
		} else {
			SetPeriod(TICK_LENGTH_SEC);
		}

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
		logger->All("Zac Wilson had no part in this.");
		logger->All("=========================");
		logger->Info("Finished global init.");
	}

	/**
	 * Initialization code for disabled mode
	 */
	void RevereRobot::DisabledInit() {
		logger->Info("Disabled mode init.");
		driver->Stop();
		driver->SetSafetyEnabled(true);
		auxDrive->Stop();
		ResetTick();
		logger->Info("Finished disabled mode init.");
	}

	/**
	 * Periodic code for disabled mode.
	 * Do nothing but feed the doggy.
	 */
	void RevereRobot::DisabledPeriodic() {
		OnTick();
		driver->Stop();
		auxDrive->Stop();
	}

	/**
	 * Initialization code for autonomous mode.
	 */
	void RevereRobot::AutonomousInit() {
		logger->Info("Auton mode init.");
		driver->Stop();
		driver->SetSafetyEnabled(false);
		auxDrive->Stop();
		ResetTick();
		logger->Info("Finished auton mode init.");
	}

	/**
	 * Periodic code for autonomous mode.
	 */
	void RevereRobot::AutonomousPeriodic() {
		OnTick();

	}

	/**
	 * Initialization code for teleop mode.
	 */
	void RevereRobot::TeleopInit() {
		logger->Info("Teleop mode init.");
		driver->Stop();
		driver->SetSafetyEnabled(true);
		driver->SetExpiration(0.5);
		auxDrive->Stop();
		ResetTick();
		logger->Info("Finished teleop mode init.");
	}

	/**
	 * Periodic code for teleop mode.
	 */
	void RevereRobot::TeleopPeriodic() {
		OnTick();
		controller->TeleopTick(modeTickCount);
		auxDrive->TeleopTick(modeTickCount);
		if (joystick->GetRawButton(5)) {
			//	Lift up
			//	Only task this if we don't have another task running
			if (!(currentTask != NULL && !currentTask->isDone)) {
				currentTask = new WinchUpTickTask(modeTickCount, auxDrive);
			}
		}
		if (joystick->GetRawButton(3)) {
			//	Go all the way down
			//	Only task this if we don't have another task running
			if (!(currentTask != NULL && !currentTask->isDone)) {
				currentTask = new WinchDownTickTask(modeTickCount, auxDrive);
			}
		}
		if (joystick->GetRawButton(12)) {
			//	Go all the way up
		}
	}

	/**
	 * Initialization code for test mode.
	 */
	void RevereRobot::TestInit() {
		logger->Info("Test mode init.");
		driver->Stop();
		driver->SetSafetyEnabled(true);
		driver->SetExpiration(0.5);
		auxDrive->Stop();
		ResetTick();
		logger->Info("Finished test mode init.");
	}

	/**
	 * Periodic code for test mode.
	 */
	void RevereRobot::TestPeriodic() {
		OnTick();
		if (modeTickCount == 1) {
			driver->Stop();
			auxDrive->Stop();
		}
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

		if (currentTask != NULL) {
			currentTask->Tick();
			if (currentTask->isDone) {
				currentTask = NULL;
			}
		}

		if (USE_SYNC_TICK) {
			newData = true;
		} else {
			newData = m_ds->IsNewControlData();
		}
		if (newData) {
			lastNewDataTick = modeTickCount;
		} else {
			//	Protect ourselves from trying to make a negative positive-only value.
			if (modeTickCount < lastNewDataTick) {
				//	Complain. We don't time travel.
				logger->Fatal("WE'RE GOING BACK IN TIME NO NO NO Y U DO DIS.");
				driver->Stop();
				auxDrive->Stop();
			} else {
				unsigned int ticksSinceLastPacket = modeTickCount
						- lastNewDataTick;
				if (ticksSinceLastPacket > SecondsToTicks(1.0)
						&& ticksSinceLastPacket % 5 == 0) {
					logger->Warn(
							StrFormat(
									"Did not receive a new packet for %d seconds!",
									TicksToSeconds(ticksSinceLastPacket)));
					driver->Stop();
					auxDrive->Stop();
				}
			}
		}
		m_watchdog.Feed();
	}

	unsigned int RevereRobot::SecondsToTicks(float seconds) {
		//	Ensure seconds is non-negative and flip sign if that's the case (should we really do this?)
		if (seconds < 0.0) {
			seconds *= -1.0;
		}
		//	   seconds->millis->ticks
		return (unsigned int) (seconds * 1000.0 / TICK_LENGTH_MS);
	}

	float RevereRobot::TicksToSeconds(unsigned int ticks) {
		//	Ticks will always be negative! Yay!
		//	   ticks->millis->seconds
		return ticks * TICK_LENGTH_MS / 1000.0;
	}

	/**
	 * Resets the tick system for the mode change. Should be called by all xxxInit() methods.
	 */
	void RevereRobot::ResetTick() {
		if (currentTask != NULL) {
			currentTask = NULL;
		}
		modeTickCount = 0;
		lastNewDataTick = 0;
		newData = false;
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
		delete auxDrive;
		auxDrive = NULL;
		delete currentTask;
		currentTask = NULL;
	}

};

START_ROBOT_CLASS(RevereRobot)
;

