#ifndef _STOPWATCH_
#define _STOPWATCH_

// INCLUDE(S)
#include <time.h> // for clock_t

class StopWatch {
private:
	clock_t startTime;			// holds start time
	clock_t stopTime;			// holds end time
	int totalTime;				// holds total elapsed time
	bool watchOn;				// true = stopwatch on
								// false = stopwatch off
public:
	StopWatch();				// default constructor
	void Start();				// starts the watch
	int Stop();					// ends the watch, returns totalTime to dataHouse.cpp
	void DisplayTimerInfo(int);	// displays total elapsed time to suer
};
#endif
