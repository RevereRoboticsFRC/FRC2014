#include "TickTask.h"
#import "../Drive/AuxDrive.h"

#ifndef HWinchUpTickTask
#define HWinchUpTickTask

class WinchUpTickTask: public TickTask {
	AuxDrive* auxDrive;
	bool fullUp;
public:
	inline WinchUpTickTask(unsigned int, AuxDrive*, bool);
	inline void Tick();
	inline int GetId();
	inline ~WinchUpTickTask();
};

WinchUpTickTask::WinchUpTickTask(unsigned int i, AuxDrive* ad, bool fup) :
	TickTask(i) {
	startTick = i;
	tickCount = 0;
	auxDrive = ad;
	fullUp = fup;
	printf("WinchUpTickTask Constructor\n");
	printf("UPPPPPPPP!!!!\n");
	if (fup) {
		printf("MOAR!!!!!\n");
	}
}

void WinchUpTickTask::Tick() {
	tickCount++;
	if (isDone) {
		printf("Finished on tick %d\n", tickCount);
		return;
	}
	//	Temporary for now
	if (fullUp) {
		if(!auxDrive->winchLimSwitchHigh->Get()) {
			printf("Driving winch full up at -1.0 during tick %d\n", tickCount);
			auxDrive->WinchDrive(-1.0);
			return;
		}
	} else {
		unsigned int len = 30; //	600 ms
		if (tickCount < len) {
			if (tickCount % 5) {
				printf("Driving winch at -1.0 during tick %d\n", tickCount);
			}
			auxDrive->WinchDrive(-1.0);
			return;
		}
	}
	printf("Stopping winch at tick %d\n", tickCount);
	auxDrive->WinchStop();
	isDone = true;
}

int WinchUpTickTask::GetId() {
	return 1;
}

WinchUpTickTask::~WinchUpTickTask() {
	printf("WinchUpTickTask Destructor\n");
	auxDrive->Stop();
}
#endif
