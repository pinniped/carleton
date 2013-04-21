#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

# define HEADER_COL1_WIDTH 11
# define HEADER_COL2_WIDTH 10
# define HEADER_COL3_WIDTH 14
# define HEADER_COL4_WIDTH 8

# define ROW_COL1_WIDTH 10
# define ROW_COL2_WIDTH 11
# define ROW_COL3_WIDTH 13
# define ROW_COL4_WIDTH 7

// Cross-platform replacement to system("pause")
void waitReturn() {
	cout << "Press ENTER to continue...";
	cin.get();
}

// Sanitize input stream
void iClear() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Returns the square of an integer value. 
int sqrInt(int value) {
	return value * value;
}

// Given a number, returns true if it is an integer and
// false otherwise.
bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

// Returns an integer value from the user between minimum and  
// maximum, inclusive. 
// We assume that the calling function has output the initial  
// request for input. 
// This function will check the value entered and output an error  
// message until a value in the correct range is entered. 
int getInt(int minimum, int maximum) {
	int input;

	for (;;) {
		cin >> input;
		iClear();

		if (input <= maximum && input >= minimum) {
			break;
		} else {
			cout << "Input must be an integer between "
				<< minimum << " and " << maximum
				<< " inclusive, try again: ";
		}
	}

	return input;
}


// Returns true if value is prime, false otherwise. 
// (Also returns false if value is less than 2.)  
bool isPrime (int value) {
	bool prime = true;
	// Check all intergers less than the square root
	// of number for factors. Changes prime to false
	// if one is found.
	for (int i = 2; i < sqrt(value); i++) {
		if (value % i == 0) {
			prime = false;
			break;
		}
	}
	
	return prime;
}

// Given a number, prints 'yes' if it is a prime,
// 'no' otherwise. Print 'N/A' if number is less than 2
void printPrime(int number) {
	if (number < 2) {
		cout << "N/A";
		return;
	}

	if (isPrime(number)) {
		cout << "yes";
	} else {
		cout << "no";
	}

}

// Given a number and a precision, prints the square
// root of number to precision decimal places
// If number is less than 0, prints N/A
void printSqrt(int number, int precision) {
	if (number >= 0) {
		cout << fixed << setprecision(precision);
		cout << sqrt(number);
	} else {
		cout << "N/A";
	}
}

// Prints the header preceding rows of data
void printHeader() {
	cout << setw (HEADER_COL1_WIDTH);
	cout << "Value";
	cout << setw (HEADER_COL2_WIDTH);
	cout << "Square";
	cout << setw (HEADER_COL3_WIDTH);
	cout << "Square Root";
	cout << setw (HEADER_COL4_WIDTH);
	cout << "Prime?";
	cout << endl;
}

// Given a number and precision, prints a row of data
// as specified by the assignment
void printRow(int number, int precision) {
	cout << setw (ROW_COL1_WIDTH);
	cout << number;
	cout << setw (ROW_COL2_WIDTH);
	cout << sqrInt(number);
	cout << setw (ROW_COL3_WIDTH);
	printSqrt(number, precision);
	cout << setw (ROW_COL4_WIDTH);
	printPrime(number);
	cout << endl;
}

int main (void) {
	// Variables
	int startValue,
		prevStartValue,
		rows,
		maxRows = 200,
		decimals;

	bool firstTime = true;
	

	// Loop until value is same as previous input
	for (;;) {
		// Loop for getting valid startingValue
		cout << "Enter start value (repeat previous number to exit): ";
		startValue = getInt(-9999,9999);

		// If first iteration, initiate prevStartValue
		// If sentinel value is met, break loop
		if (firstTime) {
			firstTime = false;
			prevStartValue = startValue;
		} else if (startValue == prevStartValue) {
			break;
		}

		// Calculate the maximum number of rows such that
		// rows + startValue <= 9999
		if (maxRows + startValue >= 9999) {
			maxRows = 9999 - startValue + 1;
		}

		// Loop for getting valid input for rows
		cout << "Enter number of rows (1 to " << maxRows << "): ";
		rows = getInt(1,maxRows);

		// Loop for getting valid input for rows and decimals
		cout << "Enter number of decimal places (1 to 7): ";
		decimals = getInt(1,7);

		// Store current startValue for use in next iteration
		prevStartValue = startValue;

		// Print header
		printHeader();

		// Print "rows" rows of data, as specified by the assignment
		for (int i = 0; i < rows; i++) {
			printRow(startValue, decimals);
			startValue ++;
		}
		cout << endl;
	}
	
	waitReturn();
	return 0;
}
