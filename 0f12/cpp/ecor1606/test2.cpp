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

int main (void) {
	// Variables
	int count = 3;
	
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			for (int k = 0; k < count; k++) {
				for (int l = 0; l < count; l++) {
					if (i == 0) {
						cout << "S";
					} else if (i == 1) {
						cout << "A";
					} else {
						cout << "I";
					}

					if (j == 0) {
						cout << "n";
					} else if (j == 1) {
						cout << "t";
					} else {
						cout << "p";
					}

					if (k == 0) {
						cout << "a";
					} else if (k == 1) {
						cout << "u";
					} else {
						cout << "l";
					}

//					if (l == 0) {
//						cout << "s";
//					} else if (l == 1) {
//						cout << "b";
//					} else {
//						cout << "c";
//					}

					cout << endl;

				}
			}
		}
	}

	waitReturn();
	return 0;
}
