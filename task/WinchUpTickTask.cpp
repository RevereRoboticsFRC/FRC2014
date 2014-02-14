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
	if (auxDrive->winchLimSwitchHigh->Get()) {
		printf("Stopping winch at tick %d\n", tickCount);
		auxDrive->WinchStop();
		isDone = true;
		return;
	}
	//	Temporary for now
	if (fullUp) {
<<<<<<< HEAD
		printf("Driving winch full up at -0.75 during tick %d\n", tickCount);
		auxDrive->WinchDrive(-0.5);
		return;
=======
		if(!auxDrive->winchLimSwitchHigh->Get()) {
			printf("Driving winch full up at -0.75 during tick %d\n", tickCount);
			auxDrive->WinchDrive(-0.75);
			return;
		}
>>>>>>> 518f0d8c4364f0b96190d45bcc827e46d6224afc
	} else {
		unsigned int len = 20; //	400 ms
		if (tickCount < len) {
			if (tickCount % 5) {
				printf("Driving winch at -1.0 during tick %d\n", tickCount);
			}
			auxDrive->WinchDrive(-1.0);
			return;
		} else {
			printf("Stopping winch at tick %d\n", tickCount);
			auxDrive->WinchStop();
			isDone = true;
			return;
		}
	}
}

int WinchUpTickTask::GetId() {
	return 1;
}

WinchUpTickTask::~WinchUpTickTask() {
	printf("WinchUpTickTask Destructor\n");
	auxDrive->Stop();
}
#endif
