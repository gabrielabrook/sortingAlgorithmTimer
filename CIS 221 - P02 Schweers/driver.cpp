// ********************************************************************************
// Name: Gabriela Schweers
// Date: 12/6/2022 - 12/7/2022
// Desc: A C++ program that heuristically compares the execution time of 
//		 bubble sort, selection sort, and insertion sort using file sizes of 
//       various input sizes.
// ********************************************************************************

// EXTERNAL LIBRARIES AND DEPENDENCIES
#include "stopwatch.h"		// header file for StopWatch class
#include "dataHousing.h"	// header file for DataHouse class
#include <iostream>		
#include <conio.h>
using namespace std;

// MAIN
int main() {
	// Instantiate the DataHouse class
	DataHouse myDataHouse;
	
	// Read files, performs sort via call inside class to class function
	myDataHouse.getFiles();

	// Once everything is ran, processed, and outputted...
	cout << "ANALYSIS COMPLETE... PRESS ANY KEY TO CONTINUE." << endl;

	// EXIT TO OS
	cout << "Press any key to continue";
	_getch();
	return 0;
}
		  




