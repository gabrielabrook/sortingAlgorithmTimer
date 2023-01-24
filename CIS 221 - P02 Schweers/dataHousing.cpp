// ***********************************************************************************
// Title: Implementation file for "dataHousing.h"
// ***********************************************************************************

#include "dataHousing.h"	// header file for THIS CLASS
#include "stopwatch.h"		// header file for STOPWATCH CLASS (using functions defined in said class)
#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <fstream>
using namespace std;

// DEFINES
#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

// CONSTRUCTOR
DataHouse::DataHouse() {
	num = 0;				// temp value
	size = 0;				// ^
	num500Array = NULL;		// will get set later
	num5kArray = NULL;		// ^
	num25kArray	= NULL;		// ^
	num100kArray = NULL;	// ^
}

// DESTRUCTOR
DataHouse::~DataHouse() {
	delete[] num500Array;
	delete[] num5kArray;
	delete[] num25kArray;
	delete[] num100kArray;
}

void DataHouse::getFiles() {
	// LOCAL VARS
	ifstream in_file1;	// file for NumFile500
	ifstream in_file2;	// file for NumFile5k
	ifstream in_file3;	// file for NumFile25k
	ifstream in_file4;	// file for NumFile100k

	// FILE OPENER FOR NUMFILE500
	in_file1.open("NumFile500.txt");
	if (in_file1.is_open() == true) {
		while (in_file1 >> num) {
			size = size + 1;
		}

		in_file1.clear();                   // clear the eof flag after reaching end of file
		in_file1.seekg(0, ios::beg);        // returning to start of file to now store numerical values in .txt file to array
		num500Array = new int[size];		// allocates appropiate memory for array (error given if new int[size] written in constructor before fucnt.)
		cout << "Populating Arrays... (" << size << " elements) (" << endl;
		for (int i = 0; i < size; ++i) {
			in_file1 >> num500Array[i];
		}
		in_file1.close();
		sortArray(num500Array, size);		// send to function to get sorted & obtain times
	} else {
		cout << "The file could not be opened...";
	}
	
	// FILE OPENER FOR NUMFILE5k
	size = 0;	// resetting vars for next file...
	num = 0;	// ^

	in_file2.open("NumFile5k.txt");
	if (in_file2.is_open() == true) {
		while (in_file2 >> num) {
			size = size + 1;
		}

		in_file2.clear();                 
		in_file2.seekg(0, ios::beg);    
		num5kArray = new int[size];	
		cout << "Populating Arrays... (" << size << " elements) (" << endl;
		for (int i = 0; i < size; ++i) {
			in_file2 >> num5kArray[i];
		}
		in_file2.close();
		sortArray(num5kArray, size);
	} else {
		cout << "The file could not be opened...";
	}
	
	// FILE OPENER FOR NUMFILE25k
	size = 0;	// resetting vars for next file...
	num = 0;	// ^

	in_file3.open("NumFile25k.txt");
	if (in_file3.is_open() == true) {
		while (in_file3 >> num) {
			size = size + 1;
		}

		in_file3.clear();                 
		in_file3.seekg(0, ios::beg);        
		num25kArray = new int[size];		
		cout << "Populating Arrays... (" << size << " elements) (" << endl;
		for (int i = 0; i < size; ++i) {
			in_file3 >> num25kArray[i];
		}
		in_file3.close();
		sortArray(num25kArray, size);	
	} else {
		cout << "The file could not be opened...";
	}

	// FILE OPENING FOR NUMFILE100k
	size = 0;	// resetting vars for next file...
	num = 0;	// ^

	in_file4.open("NumFile100k.txt");
	if (in_file4.is_open() == true) {
		while (in_file4 >> num) {
			size = size + 1;
		}

		in_file4.clear();                 
		in_file4.seekg(0, ios::beg);        
		num100kArray = new int[size];		
		cout << "Populating Arrays... (" << size << " elements) (" << endl;
		for (int i = 0; i < size; ++i) {
			in_file4 >> num100kArray[i];
		}
		in_file4.close();
		sortArray(num100kArray, size);
	} else {
		cout << "The file could not be opened...";
	}
}

void DataHouse::sortArray(int* tempArray, int size) {
	// Create instance of StopWatch class inside this (DataHouse) class
	StopWatch myClassStopWatch;

	cout << "Sorting..." << endl;

	// LOCAL VARS
	int timeBubble;						// holds bubble sorting time
	int timeInsertion;					// holds insertion sorting time
	int timeSelection;					// holds selection sorting time
	int* unsortedArray;					// saves unsorted array to new array of pointers
	unsortedArray = new int[size];		// sets array to same size as passed through array

	for (int i = 0; i < size; i++) {	// sets array to unsorted passed through array
		unsortedArray[i] = tempArray[i];
	}

	// BUBBLE SORT
	bool swap = TRUE;
	while (swap == TRUE) {
		swap = FALSE;
		myClassStopWatch.Start();
		for (int i = 0; i <= size - 2; i++) {
			int j = i + 1;
			if (tempArray[i] > tempArray[j]) {
				int temp = tempArray[j];
				tempArray[j] = tempArray[i];
				tempArray[i] = temp;
				swap = TRUE;
			}
		}
		
	}
	timeBubble = myClassStopWatch.Stop();	// record time

	// INSERTION SORT
	for (int i = 0; i < size; i++) {		// resets tempArray back to being unsorted
		tempArray[i] = unsortedArray[i];
	}

	int currentValue;
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		currentValue = tempArray[i];
		myClassStopWatch.Start();
		while (tempArray[j] > currentValue && j >= 0) {
			tempArray[j + 1] = tempArray[j];
			j--;
		}
		tempArray[j + 1] = currentValue;
	}
	timeInsertion = myClassStopWatch.Stop();	// record time
	
	// SELECTION SORT
	for (int i = 0; i < size; i++) {			// reset tempArray back to being unsorted
		tempArray[i] = unsortedArray[i];
	}

	for (int i = 0; i < size - 1; i++) {
		int currentMin = i;
		myClassStopWatch.Start();
		for (int j = i + 1; j < size; j++) {
			if (tempArray[j] < tempArray[currentMin])
				currentMin = j;
		}

		int tempNum = tempArray[i];
		tempArray[i] = tempArray[currentMin];
		tempArray[currentMin] = tempNum;
	}
	timeSelection = myClassStopWatch.Stop();	// record time

	// Selection Sort
	cout << "SORTS COMPLETE!" << endl;
	cout << "Elapsed Time (Bubble Sort)" << setw(6) << ": ";
	myClassStopWatch.DisplayTimerInfo(timeBubble);
	
	cout << "Elapsed Time (Insertion Sort) : ";
	myClassStopWatch.DisplayTimerInfo(timeInsertion);
	
	cout << "Elapsed Time (Selection Sort) : ";
	myClassStopWatch.DisplayTimerInfo(timeSelection);	
	cout << endl;
}