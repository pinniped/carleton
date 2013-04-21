#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Cross-platform replacement to system("pause")
void waitReturn()
    {
        char c;
        cout << "Return to continue...";
        //cin.read(&c,1);
        //if (cin.peek() == 0xA) {;}
    	cin.ignore(numeric_limits<streamsize>::max(), '\n' );
    }

bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

int* foo(int list[]) {
	for (int i = 0; list[i] != '\0'; i++) {
		list[i] += 2;
	}

	return list;
}

int main (void) {
	int a, b, c, d;
	a =0;

	int array[20];

	/*
		int array[20] = {20,1};
		for (int i = 0; i < 5; i++) {
			cout << array[i] << endl;
		}
	*/

	cout << sizeof(array) / sizeof(array[0]) << endl;

	waitReturn();
	return 0;
}
