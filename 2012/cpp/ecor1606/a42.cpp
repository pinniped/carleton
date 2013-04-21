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

// Given a number, returns true if it is an integer and
// false otherwise.
bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

// Given a number, returns its square
int square(int number) {
	return number * number;
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

// Given a number and a precision, prints the square
// root of number to precision decimal places
// If number is less than 0, prints N/A
void printSqrt(int number, int precision) {
	cout << fixed << setprecision(precision);
	if (number >= 0) {
		cout << sqrt(number);
	} else {
		cout << "N/A";
	}
}

// Given a number, prints 'yes' if it is a prime,
// 'no' otherwise. Print 'N/A' if number is less than 2
void printPrime(int number) {
	if (number < 2) {
		cout << "N/A";
		return;
	}

	// Check for factors of number less than sqrt(number)
	// changes prime to false if it finds one
	bool prime = true;
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			prime = false;
			break;
		}
	}

	if (prime) {
		cout << "yes";
	} else {
		cout << "no";
	}

}

// Given a number and precision, prints a row of data
// as specified by the assignment
void printRow(int number, int precision) {
	// Print number
	cout << setw (ROW_COL1_WIDTH);
	cout << number;
	// Print sqare of number
	cout << setw (ROW_COL2_WIDTH);
	cout << square(number);
	// Print sqrt of number
	cout << setw (ROW_COL3_WIDTH);
	printSqrt(number, precision);
	// Print whether number is a prime
	cout << setw (ROW_COL4_WIDTH);
	printPrime(number);
	cout << endl;
}

int main (void) {
	// Variables
	int startValue, // Stores user input
		prevStartValue, // Stores user input from previous iteration of sentinel loop
		rows, // Stores user input
		maxRows = 200, // Limit on number of rows
		decimals; // Stores user input

	bool firstTime = true; // First iteration of sentinel loop?
	
	// Loop until value is same as previous input
	for (;;) {
		// Loop for getting valid startingValue
		for (;;) {
			cout << "Enter start value (repeat previous number to exit): ";
			cin >> startValue;
			iClear();

			bool validStartValue = startValue <= 9999 && startValue >= -9999;

			if (validStartValue) {
				break;
			} else {
				cout << "Value must be between -9999 and 9999, try again!";
				cout << endl;
			}

		}

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
		for (;;) {
			cout << "Enter number of rows (1 to " << maxRows << "): ";
			cin >> rows;
			iClear();

			bool validRows = rows >= 1 && rows <= maxRows;

			if (validRows) {
				break;
			} else {
				cout << "Rows must be between 1 and " << maxRows << ", try again!" << endl;
			}
		}


		// Loop for getting valid input for rows and decimals
		for (;;) {
			cout << "Enter number of decimal places (1 to 7): ";
			cin >> decimals;
			iClear();

			bool validDecimals = decimals >= 1 && decimals <= 7;

			if (validDecimals) {
				break;
			} else {
				cout << "Decimals must be between 1 and 7, try again!" << endl;
			}
		}

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
