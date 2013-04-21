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
void cleanStream() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Given a boolean, prints "True" to screen if its value is
// true, and prints "False" to screen otherwise
void printBoolean(bool P) {
	if (P) {
		cout << "T";
	} else {
		cout << "F";
	}
}

// Given a number, returns true if it is an integer and
// false otherwise.
bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

int main (void) {
	// Variables
	int test = 0;

	printBoolean(test);
	test = 1;
	printBoolean(test);


	
	waitReturn();
	return 0;
}
