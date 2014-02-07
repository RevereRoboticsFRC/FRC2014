#include "TickTask.h"
#import "../Drive/AuxDrive.h"

#ifndef HWinchDownTickTask
#define HWinchDownTickTask

class WinchDownTickTask: public TickTask {
	AuxDrive* auxDrive;
public:
	inline WinchDownTickTask(unsigned int, AuxDrive*);
	inline void Tick();
	inline ~WinchDownTickTask();
};

WinchDownTickTask::WinchDownTickTask(unsigned int i, AuxDrive* ad) :
	TickTask(i) {
	startTick = i;
	tickCount = 0;
	auxDrive = ad;
	printf("WinchDownTickTask Constructor\n");
	printf("DOOOOOWWNNNNN!!!\n");
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
		if (tickCount % 5) {
			printf("Driving winch at +1.0 during tick %d\n", tickCount);
		}
		auxDrive->WinchDrive(1.0);
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
