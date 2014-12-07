#include "TickTask.h"
#import "../Drive/AuxDrive.h"

#ifndef HWinchDownTickTask
#define HWinchDownTickTask

class WinchDownTickTask: public TickTask {
	AuxDrive* auxDrive;
	bool fullDown;
public:
	inline WinchDownTickTask(unsigned int, AuxDrive*, bool);
	inline void Tick();
	inline int GetId();
	inline ~WinchDownTickTask();
};

WinchDownTickTask::WinchDownTickTask(unsigned int i, AuxDrive* ad, bool fd) :
	TickTask(i) {
	startTick = i;
	tickCount = 0;
	auxDrive = ad;
	fullDown = fd;
	printf("WinchDownTickTask Constructor\n");
	if (fullDown) {
		printf("DOOOOOWWNNNNN!!!\n");
	}
}

void WinchDownTickTask::Tick() {
	tickCount++;
	if (isDone) {
		printf("Finished on tick %d\n", tickCount);
		return;
	}
	if (auxDrive->winchLimSwitchLow->Get()) {
		printf("Stopping winch at tick %d\n", tickCount);
		auxDrive->WinchStop();
		isDone = true;
	} else {
		if (fullDown) {
			if (tickCount % 5) {
				printf("Driving winch at +0.75 during tick %d\n", tickCount);
			}
			auxDrive->WinchDrive(0.75);
		} else {
			unsigned int len = 20; //	400 ms
			if (tickCount < len) {
				if (tickCount % 5) {
					printf("Driving winch at +1.0 during tick %d\n", tickCount);
				}
				auxDrive->WinchDrive(+1.0);
			} else {
				printf("Stopping winch at tick %d\n", tickCount);
				auxDrive->WinchStop();
				isDone = true;
			}
		}
	}
}

int WinchDownTickTask::GetId() {
	return 2;
}

WinchDownTickTask::~WinchDownTickTask() {
	printf("WinchDownTickTask Destructor\n");
	auxDrive->Stop();
}
#endif
