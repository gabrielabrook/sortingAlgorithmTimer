// ***********************************************************************************
// Title: Implementation file for "stopwatch.h"
// ***********************************************************************************

#include "stopwatch.h" // header file
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

// DEFAULT CONSTRUCTOR
StopWatch::StopWatch() {
	startTime = 0;
	stopTime = 0;
	totalTime = 0;
	watchOn = false; // off by default
}

// METHOD TO START WATCH
void StopWatch::Start() {
	if (!watchOn) {				// checks if watch is on (can't start if it's already on)
		startTime = clock();	// given by time.h
		watchOn = true;			// turn watch on
	}
}

// METHOD TO STOP WATCH
int StopWatch::Stop() {
	if (watchOn) {
		stopTime = clock();		// given by time.h
		watchOn = false;		// turn watch off
		return totalTime = (stopTime - startTime) / (CLOCKS_PER_SEC/1000); // CLOCKS_PER_SEC from time.h
	}
}

// METHOD TO DISPLAY TOTAL ELAPSED TIME
void StopWatch::DisplayTimerInfo(int sortTime) {
	cout << sortTime << " milliseconds" << endl;
}