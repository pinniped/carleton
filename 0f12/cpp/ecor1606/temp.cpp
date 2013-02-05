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

// Given a number, returns true if it is an integer and
// false otherwise.
bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

int main (void) {
	// Variables
	
	waitReturn();
	return 0;
}
