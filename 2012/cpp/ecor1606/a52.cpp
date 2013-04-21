#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cassert>

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

// Given a number, returns true if it is an integer and
// false otherwise.
bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

// Given a year, returns true if it is a leap year
// and false otherwise
bool isLeap(int year){
	if (year % 400 == 0) {
		return true;
	} else if (year % 100 == 0) {
		return false;
	} else if (year % 4 == 0) {
		return true;
	} else {
		return false;
	}
}

// Given a month and a year, returns the number of
// days in that month
int daysInMonth (int month, int year) {
	// Determines whether the month is a bigMonth
	// that is whether it one of the months with 31 days
	bool bigMonth = false;
	if (month < 8 && month % 2 != 0) {
		bigMonth = true;
	} else if (month > 7 && month % 2 == 0) {
		bigMonth = true;
	}

	// Returns number of days if month is Feb
	// since it is a special day, otherwise
	// return 31 if it is a bigMonth and 30
	// otherwise
	if (month == 2) {
		if (isLeap(year)) {
			return 29;
		}
		return 28;
	} else if (bigMonth) {
		return 31;
	} else {
		return 30;
	}
}

// returns number of preceding days in same year:
// 0 for Jan 1, 1 for Jan 2, and so on
int daysSinceJan1 (int day, int month, int year) {
	int daysSoFar = day - 1;

	for (int i = 1; i < month; i++) {
		daysSoFar += daysInMonth(i, year);
	}

	return daysSoFar;
}


// returns the number of days before Jan 1st of the specified year 
// (using Jan 1 1900 as the starting point)
// returns 0 for 1900, 
//         365 for 1901 (note: 1900 was NOT a leap year)
//         730 for 1902, etc.
int daysInPreviousYears (int year) {
	int daysSoFar = 0;
	const int startYear = 1900;

	for (int i = 0; i < year - startYear; i++) {
		if (isLeap(startYear + i)) {
			daysSoFar += 366;
		} else {
			daysSoFar += 365;
		}		
	}

	return daysSoFar;
}

// returns the number of days since Jan 1 1900
int daysSinceStartOfTime (int day, int month, int year) {
	return daysSinceJan1(day, month, year) + daysInPreviousYears(year);
}

// returns the day of the week: 1 is Monday, 2 is Tuesday, etc.
// Hint: use daysSinceStartOfTime and Jan 1 1900 was a Monday
int dayOfWeek (int day, int month, int year) {
	return (daysSinceStartOfTime(day, month, year) + 1) % 7;
}


// creates a calendar for the given month and year and prints
// it out nicely
void createCalendar (int month, int year) {

  int startDay, days, count, i;

  startDay = dayOfWeek (1, month, year);
  days = daysInMonth (month, year);

  cout << "\n  Su  Mo  Tu  We  Th  Fr  Sa\n";

  // work out how many blank entries should precede the first number
  count = startDay % 7;
  // output the required blank entries
  for (i = 1; i <= count; i++) {
    cout << setw(4) << " ";
  }
 
  // output all of the numbers
  for (i = 1; i <= days; i++) {
    cout << setw(4) << i;
    count++;
    if (count == 7) { // if the current output line has 7 items on it
      cout << endl;  // end the current output line
      count = 0;     // and begin a new one
    }
  }

  if (count != 0) { // if we're part way through an output line
    cout << endl;  // end this output line
  }

  cout << endl;

}

int main (void) {
	// Tests
	/***********************
	// isLeap tests
	assert(isLeap(1600) != 0);
	assert(isLeap(2000) != 0);
	assert(isLeap(2400) != 0);
	assert(isLeap(2800) != 0);
	assert(isLeap(1700) == 0);
	assert(isLeap(1800) == 0);
	assert(isLeap(1900) == 0);
	assert(isLeap(2100) == 0);
	assert(isLeap(2200) == 0);
	assert(isLeap(2300) == 0);
	assert(isLeap(2500) == 0);
	assert(isLeap(2600) == 0);
	assert(isLeap(2700) == 0);
	assert(isLeap(2900) == 0);
	assert(isLeap(3000) == 0);

	// daysInMonth tests
	assert(daysInMonth(1,1600) == 31);
	assert(daysInMonth(2,1600) == 29);
	assert(daysInMonth(3,1600) == 31);
	assert(daysInMonth(4,1600) == 30);
	assert(daysInMonth(5,1600) == 31);
	assert(daysInMonth(6,1600) == 30);
	assert(daysInMonth(7,1600) == 31);
	assert(daysInMonth(8,1600) == 31);
	assert(daysInMonth(9,1600) == 30);
	assert(daysInMonth(10,1600) == 31);
	assert(daysInMonth(11,1600) == 30);
	assert(daysInMonth(12,1600) == 31);
	
	assert(daysInMonth(2,1700) == 28);
	assert(daysInMonth(2,2200) == 28);
	assert(daysInMonth(2,2400) == 29);

	// daysInPreviousYears tests
	assert(daysInPreviousYears(1900) == 0);
	assert(daysInPreviousYears(1901) == 365);
	assert(daysInPreviousYears(1902) == 730);
	assert(daysInPreviousYears(1903) == 1095);
	assert(daysInPreviousYears(1904) == 1460);
	assert(daysInPreviousYears(1905) == 1826);

	// daysSinceStartOfTime tests
	assert (daysSinceStartOfTime(1,1,1900) == 0);
	assert (daysSinceStartOfTime(2,1,1900) == 1);
	assert (daysSinceStartOfTime(1,1,1901) == 365);
	assert (daysSinceStartOfTime(2,1,1901) == 366);
	assert (daysSinceStartOfTime(28,2,1904) == 1460 + 31 + 27);
	assert (daysSinceStartOfTime(29,2,1904) == 1460 + 31 + 28);

	// dayOfWeek tests
	assert (dayOfWeek(1,1,1900) == 1);
	assert (dayOfWeek(2,1,1900) == 2);
	assert (dayOfWeek(8,1,1900) == 1);
	assert (dayOfWeek(5,3,2012) == 1);
	*/

	// Variables
	int month, year;

	// get month, year pairs from the user until 0 0 entered
	for (;;) {

		cout << "Enter month (1 - 12), and year (>= 1900)." << endl
				<< "Use two zeroes to terminate program." << endl << ": ";
		cin >> month >> year;

		if (cin.fail()) { // user entered something other than numbers
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Garbage input ignored.\n";

		} else {

			if ((month == 0) && (year == 0)) { // sentinel values
				break;
			} 

			if (month < 1 || month > 12 || year < 1900) { // invalid values
				cout << "Invalid values ignored.\n";
			} else { // valid month and year
				createCalendar (month, year);
			}
		}
	} // end for (;;)

	waitReturn();
	return 0;
}
