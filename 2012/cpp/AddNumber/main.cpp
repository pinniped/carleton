#include <iostream>
#include "io.h"

using namespace std;

#define TOO_MANY 10

void yourMother(int children) {
	cout << "The number of children you have produced thus far is:"
		<< children << endl;
	if (children > TOO_MANY) {
		cout << "You have too many children =(";
		cout << endl;
	} else {
		cout << "You still have a shit ton of children D:";
		cout << endl;
	}
}

int main()
{
	// Get a number from user
	int x = readNumber();
	int y = readNumber();
	// Write the number to console
	//writeAnswer(x * y);
	yourMother(x + y);
	
	return 0;
}
