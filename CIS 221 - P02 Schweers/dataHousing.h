#ifndef _DATAHOUSING_
#define _DATAHOUSING_

class DataHouse {
private:
	int num;					// for iterating through file
	int size;					// holds size of file (depending on file)
	int* num500Array;			// holds the NumFile500.txt contents
	int* num5kArray;			// holds the NumFile5k.txt contents
	int* num25kArray;			// holds the NumFile25k.txt contents
	int* num100kArray;			// holds the NumFile100k.txt contents

public:
	DataHouse();				// constructor
	~DataHouse();				// deallocates memory from pointer arrays
	void getFiles();			// obtains file sizes and populates array with contents
	void sortArray(int*, int);	// sorts array and outputs times
};
#endif