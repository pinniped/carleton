/* This program reads in a input file containing at most 100
 * valid professor IDs. Each occurence of each professor ID
 * from the file is then tallied and sorted (by highest
 * occurence first). The sorted data is then output to a file
 * specified by the user in the form of a table.*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Constants
const int MAX_DATA_LINES = 100;
const int STOPPER = -1;

// Given a number, returns true if it is between 10000
// and 99999 inclusive (if it has 5 digits)
bool validProfId(int number) {
	return (number >= 10000) && (number <= 99999);
}

// Given an array of integers, and its size, initializes
// its values to the provided number value.
void initializeArray(int array[], int arraySize, int value) {
	for (int i = 0; i < arraySize; i++) {
		array[i] = value;
	}
}

// Given an array of professors and tallies of the same size,
// a valid professor ID, and the current number of professor IDs
// stored in the professor array, looks through the professor array
// to find a matching ID. If one is found, the matching tally 
// is incremented. Otherwise, the next unused element of professor
// is used to store the professor ID and its tally is incremented
// by 1. If the last element professor needs to be accessed,
// program terminates.
void tallyProfessor(int professor[], int tally[], int profID, int& profCount) {
	// Process prof id and increment tally accordingly
	for (int i = 0; i <= profCount ; i++) { // 
		// Exits program if the number of valid lines have exceeded the expected
		if (professor[i] == STOPPER) {
			cout << "There are too many different professors." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			exit(EXIT_FAILURE);
		}
		
		// Tally the appropriate professor ID
		if (tally[i] == 0 || (professor[i] == profID)) {
			if (tally[i] == 0) {
				professor[i] = profID;
				profCount++;
			}
			tally[i]++;
			break;
		}
	}
}

// Given an array of professor IDs, its corresponding array
// of tallies, and the number of professor IDs in the professor 
// array, bubblesorts the tally array by its content in
// increasing order. When a swap of tally elements are made, the
// professor element of the same index is swapped in the same manner.
void bubbleSortTally(int professor[], int tally[], int profCount) {
	// Determines if a swap occurred during a traversal of the array to be sorted
	bool swapOccurred;
	// Saves value for swapping used in bubble sort
	int temp;

	do {
		swapOccurred = false;

		for (int i = 0; i < profCount - 1; i++) {
			if (tally[i] > tally[i+1]) { // If current pair of elements are out of order
				// Swap tally element pair
				temp = tally[i];
				tally[i] = tally[i+1];
				tally[i+1] = temp;
				
				// Swap professor element pair
				temp = professor[i];
				professor[i] = professor[i+1];
				professor[i+1] = temp;

				swapOccurred = true;
			}
		}
	} while (swapOccurred);
}

int main (void) {

	// Variables
	char inFile[60], // stores name of file to be opened
		 outFile[60]; // stores name of file to output to

	ifstream fin; // ifstream for taking in our data file
	ofstream fout; // ofstream for outputting data to


	int validLineCount = 0, // count number of valid lines of data
		profCount = 0; // Counts number of unique profs

	int dataLine, // used for storing one line of data
		professor[MAX_DATA_LINES+1], 
		// stores non-redundant professor id's
		// Size is one larger than max data expected to hold a stopper element
		tally[MAX_DATA_LINES]; // stores tally of professor with matching array index

	// Initialize professor and tally arrays to 0
	initializeArray(tally, MAX_DATA_LINES, 0);
	initializeArray(professor, MAX_DATA_LINES, 0);
	// stopper element
	professor[MAX_DATA_LINES] = STOPPER;


	// Get and store input file name
	cout << "Enter name of input file: ";
	cin >> inFile;

	// Open file
	fin.open(inFile);
	//fin.open("full");

	// If input file fails to open, report and exit
	if (fin.fail()) {
		cout << "Unable to open file " << inFile << endl;
	} else {

		// Get and store output file name
		cout << "Enter name of output file: ";
		cin >> outFile;

		// Open output file
		fout.open(outFile);
		//fout.open("out");
		
		// If output file fails to open, report and exit
		if (fout.fail()) {
			cout << "Unable to open file " << outFile << endl;
		} else {

			// Loop for storing data from input file
			for (;;) {

				// Get a line of data
				fin >> dataLine;

				if (fin.fail()) { // Error found: report and continue
					if (fin.eof()) { // Break out of loop if EOF
						break;
					}

					fin.clear();
					fin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << "Unrecognizable prof number ignored." << endl;

				} else if (!validProfId(dataLine)) { // Invalid professor number
					fin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << "Invalid professor number (" << dataLine
						<< ") ignored." << endl;

				} else { 
					// Process dataLine and tally professor ID
					tallyProfessor(professor, tally, dataLine, profCount);
				}
			}

			// Bubble sort tally and professor at the corresponding index
			bubbleSortTally(professor, tally, profCount);

			// Print header
			fout << "   Professor       Votes\n";
			fout << "----------------------------\n";

			// Print prof id and number of votes
			for (int i = profCount - 1; i >= 0; i--) {
				fout << setw(10) << professor[i]  // Print prof id
					<< setw(12) << tally[i] << endl; // Print number of votes
			}
			fout.close();

			// Report success
			cout << "The results have been written to the output file." << endl;
		}
	}

	cout << endl;
	return EXIT_SUCCESS;
}
