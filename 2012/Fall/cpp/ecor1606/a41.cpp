#include <iostream>
#include <string>
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

/* Given the minute conversion of a valid time of
 * the day. 
 * If called with type = 0, outputs "midnight"
 * if minutes is 0 and "noon" if minutes
 * is 12*60; otherwise outputs the time of the day
 * as h:mm with h hour and m mins and "am" displayed 
 * if h is between [0,11] and "pm" displayed otherwise.
 *
 * If called with type = 1, returns the h:mm conversion
 * of minutes where hh is the hours and mm is the minutes
 * 
 * If called with type =2, same output as type = 1 
 * but also outputs ss as the seconds roundede. */
void outputTime(double minutes, int type) {
	int time = (int) floor(minutes);
	double decimal = minutes - floor(minutes);
	int h = (int)time / 60;
	int m = (int)time % 60;
	int s = (int) round(decimal * 60);
	string ampm = "am";

	// Type 0 time of day call
	if (type == 0) {
		// If time is 0 or 12*60, outputs "midnight"
		// or "noon" respectively and exits function
		if (time == 0) {
			cout << "midnight";
			return;
		} else if (time == (12 * 60)) {
			cout << "noon";
			return;
		}

		// Make modifications to h and ampm
		if (h == 0) {
			h = 12;
		} else if (h > 11) {
			ampm = "pm";
			if (h > 12) {
				h -= 12;
			}
		}
	}

	cout << h << ":"; // Output hour
	
	// If m is only 1 digit, ouput a 0 in front
	if (m < 10) {
		cout << "0";
	}
	cout << m; // Output minute

	// If call type 0, output am or pm
	if (type == 0) {
		cout << ampm;
	} else if (type == 2) { // If call type 2, outputs seconds
		cout << ":";
		if (s < 10) {
			cout << "0";
		}
		cout << s;
	}
}




int main (void) {
	// Constants
	const string indent = "\t\t\t\t\t\t"; // Tab width to use when outputting time

	// Variables
	int validEntries = 0,
		validTimes = 0,
		invalidTimes = 0,
		validGaps = 0; 

	double currHour,
		   currMin,
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
	for (;;) {

		if (((currHour == 99) && (currMin == 99))) {
			break;
		}

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

				// Output current time as hh:mm
				cout << indent << "Valid Time: ";
				outputTime(currTime, 0);
				cout << endl;	

				prevTime = currTime; // Initiate prevTime
			} else if ((currTime - prevTime) >= 0 || specialCase) {
				validTimes ++; // Count number of valid times
				validGaps ++; // Count number of valid timeGaps

				// Output current time as hh:mm
				cout << indent << "Valid Time: ";
				outputTime(currTime, 0);
				cout << endl;	

				// Calculate time gap
				// For special case, add 24 hours to accomodate for smaller current time
				if (specialCase) {
					timeGap = currTime - prevTime + (24 * 60);
					cout << indent << "Gap From Previous Time: ";
					outputTime(timeGap, 1); cout << endl;
				} else {
					timeGap = currTime - prevTime;
					cout << indent << "Gap From Previous Time: ";
					outputTime(timeGap, 1); cout << endl;
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
		cout << "The shortest gap was "; outputTime(minGap, 1); cout << endl;
		cout << "The longest gap was "; outputTime(maxGap, 1); cout << endl;
		cout << "The average gap length to the nearest second was "; outputTime(gapSum / validGaps, 2);
		cout << "." << endl << endl;
	}

	waitReturn();
	return 0;
}
