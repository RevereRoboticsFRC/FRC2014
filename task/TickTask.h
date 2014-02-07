#import "TickAction.h"
/*
 * Task.h
 *
 *  Created on: Feb 5, 2014
 *      Author: Vince
 */
#ifndef HTickTask
#define HTickTask
class TickTask {

public:
	bool isDone;
	unsigned int startTick;
	unsigned int tickCount;

	TickTask(unsigned int i) {
		startTick = i;
		isDone = false;
	}

	virtual void Tick() = 0;
	virtual int GetId() = 0;
	virtual ~TickTask() {
	}
};
#endif
