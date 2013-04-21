#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Cross-platform replacement to system("pause")
void waitReturn() {
	cout << "Press ENTER to continue...";
	cin.get();
}

// Sanitize input stream
void iClear() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/* Given the hour and minutes as two numbers returns
 * a boolean that indicates whether numbers are valid 
 * hours and minutes respectively (hour between 0 and 
 * 23 and minute between 0 and 59 -- both inclusive). */
bool isValidTime(double hour, double min) {
	return ((hour >= 0 && hour <= 23) &&
			(min >= 0 && min <= 59));
}

/* Given two valid times currTime and prevTime,
 * returns true if currTime is less than 60 and
 * prevTime is greater than 23 * 60, and false
 * otherwise */
bool overMidnight(double currTime, double prevTime) {
	return ((prevTime > (23 * 60)) && (currTime < 60));
}

int main (void) {
	// Variables
	double currHour,
		   currMin,
		   validEntries = 0,
		   validTimes = 0,
		   invalidTimes = 0,
		   validGaps = 0, 
		   currTime,
		   prevTime,
		   timeGap,
		   maxGap,
		   minGap,
		   gapSum = 0;

	bool specialCase;
	
	// Prompt for input
	cout << "Enter time in hours and minutes (99 99 to stop): ";
	cin >> currHour >> currMin;
	iClear();

	// Sentinel loop for bus time input
	while (!((currHour == 99) && (currMin == 99))) {

		//Check for valid time
		if (isValidTime(currHour, currMin)) {

			validEntries ++; // Count valid entries
			currTime = currHour * 60 + currMin; // Update current time

			// Check for special scenario if this isn't the first iteration
			if (validEntries != 1) {
				specialCase = overMidnight(currTime,prevTime); // Check if time fits special scenario
			}

			// Setting prevTime for first iteration
			if (validEntries == 1) {
				validTimes ++; // Count number of valid times
				prevTime = currTime; // Initiate prevTime
			} else if ((currTime - prevTime) >= 0 || specialCase) {
				validTimes ++; // Count number of valid times
				validGaps ++; // Count number of valid timeGaps

				// Calculate time gap
				// For special case, add 24 hours to accomodate for smaller current time
				if (specialCase) {
					timeGap = currTime - prevTime + (24 * 60);
				} else {
					timeGap = currTime - prevTime;
				}

				// Add current timeGap to running total
				gapSum += timeGap;

					// Calculate the max time gap
					// If only one gap exists, initiate maxGap and minGap to that value
					if (validGaps == 1) {
						maxGap = timeGap;
						minGap = timeGap;
					} else {
						maxGap = max(timeGap,maxGap);
						minGap = min(timeGap,minGap);
					}

				prevTime = currTime;	
			} else {
				invalidTimes ++; // Count number of invalid times
				cout << "** Time ignored - not >= previous time. **" << endl;
			}

		} else {
			invalidTimes ++; // Count number of invalid times
			cout << "** Time ignored - hours and/or minutes invalid. **" << endl;
		}


		// Get new input
		cout << "Enter time in hours and minutes (99 99 to stop): ";
		cin >> currHour >> currMin;
		iClear();
	}

	// Output statistics
	
	// Number of valid and invalid times entered
	cout << endl;
	cout << validTimes << " valid times and "
		<< invalidTimes << " invalid times "
		<< "were entered." << endl;

	// Gap statistics
	if (validGaps == 0) {
		// No gaps to analyze
		cout << "Fewer than 2 times were entered - no gaps to analyze." << endl;
	} else {
		// Min, max, average
		cout << "The shortest gap was " << minGap << " minutes long." << endl;
		cout << "The longest gap was " << maxGap << " minutes long." << endl;
		cout << "The average gap length was " << gapSum / validGaps << " minutes." << endl;
	}

	waitReturn();
	return 0;
}
