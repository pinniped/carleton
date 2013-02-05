#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

#define MAXSIZE 100
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

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

int * mergeSort(int list[], int listSize)
    // if list size is 1, consider it sorted and return it
    if (listSize == 1) {
		return list;
    } else { 
		// else list size is > 1, so split the list into two sublists
		int left[(MAXSIZE + 1) / 2], right[(MAXSIZE + 1) / 2]; // var list left, right
		int mid = (listSize + 1) / 2;
		/*for each x in m up to middle
			add x to left*/
		for (int i = 0; i < mid; i++) {
			left[i] = list[i];
		}
		/*for each x in m after or equal middle
			add x to right*/
		for (int i = mid; i < listSize; i++) {
			right[i] = list[i];
		}
		// recursively call merge_sort() to further split each sublist
		// until sublist size is 1
		left = mergeSort(left, mid);
		right = mergeSort(right, listSize - mid);
		// merge the sublists returned from prior calls to merge_sort()
		// and return the resulting merged sublist
		return merge(left, right);
    }

int * merge(int left[], int right[])
    var list result
    while length(left) > 0 or length(right) > 0
        if length(left) > 0 and length(right) > 0
            if first(left) <= first(right)
                append first(left) to result
                left = rest(left)
            else
                append first(right) to result
                right = rest(right)
        else if length(left) > 0
            append first(left) to result
            left = rest(left)
        else if length(right) > 0
            append first(right) to result
            right = rest(right)
    end while
    return result

int main (void) {
	// Variables
	
	
	
	waitReturn();
	return 0;
}
