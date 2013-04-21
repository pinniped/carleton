#include <stdio.h>
#include <math.h>

void print_array(double data[], int size);
double max(double data[], int size);
double min(double data[], int size);
double avg_magnitude(double data[], int size);
double avg_power(double data[], int size);

int main(void)
{

	// Test print_array

	double data1[] = {1.0, 5.2, -3.7, 4.9};

	printf("Calling print_array\n");
	printf("Expected output: [1.0 5.2 -3.7 4.9]\n");
	printf("Actual output:   ");
	print_array(data1, 4);
	printf("\n\n");

	double data2[] = {2.5};  // Array with 1 element

	printf("Calling print_array\n");
	printf("Expected output: [2.5]\n");
	printf("Actual output:   ");
	print_array(data2, 1);
	printf("\n\n");

	// Test max

	printf("Calling max with array: ");
	print_array(data1, 4);
	printf("\nExpected result: 5.2\n");
	printf("Actual result:   %.1f\n\n", max(data1, 4));

	printf("Calling max with array: ");
	print_array(data2, 1);
	printf("\nExpected result: 2.5\n");
	printf("Actual result:   %.1f\n\n", max(data2, 1));

	double data3[] = {5.2, 1.0, -3.7, 4.9};  // largest at front

	printf("Calling max with array: ");
	print_array(data3, 4);
	printf("\nExpected result: 5.2\n");
	printf("Actual result:   %.1f\n\n", max(data3, 4));

	double data4[] = {1.0, 4.9, -3.7, 5.2};  // largest at end

	printf("Calling max with array: ");
	print_array(data4, 4);
	printf("\nExpected result: 5.2\n");
	printf("Actual result:   %.1f\n\n", max(data4, 4));


	// Test min

	printf("Calling min with array: ");
	print_array(data1, 4);
	printf("\nExpected result: -3.7\n");
	printf("Actual result:   %.1f\n\n", min(data1, 4));

	printf("Calling min with array: ");
	print_array(data2, 1);
	printf("\nExpected result: 2.5\n");
	printf("Actual result:   %.1f\n\n", min(data2, 1));

	double data5[] = {-3.7, 1.0, 5.2, 4.9};  // smallest at front

	printf("Calling min with array: ");
	print_array(data5, 4);
	printf("\nExpected result: -3.7\n");
	printf("Actual result:   %.1f\n\n", min(data5, 4));

	double data6[] = {5.2, 1.0, 4.9, - 3.7};  // smallest at end

	printf("Calling min with array: ");
	print_array(data6, 4);
	printf("\nExpected result: -3.7\n");
	printf("Actual result:   %.1f\n\n", min(data6, 4));


	// Test avg_magnitude

	double samples[] = {5.7, 2.3, -1.9, 4.5, 6.2, -8.1, 9.7, 3.1};

	printf("Calling avg_magnitude with array: ");
	print_array(samples, 8);
	printf("\nExpected result: 5.2\n");
	printf("Actual result:   %.1f\n\n", avg_magnitude(samples, 8));

	// Test avg_power

	printf("Calling avg_power with array: ");
	print_array(samples, 8);
	printf("\nExpected result: 33.7\n");
	printf("Actual result:   %.1f\n\n", avg_power(samples, 8));

	return 0;
}

void print_array(double data[], int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%.1lf", data[i]);
	}
	printf("]");
}

double max(double data[], int size) {
	double max = data[0];
	for (int i = 1; i < size; i++) {
		if (max < data[i]) {
			max = data[i];
		}
	}
	return max;
}

double min(double data[], int size) {
	double min = data[0];
	for (int i = 1; i < size; i++) {
		if (min > data[i]) {
			min = data[i];
		}
	}
	return min;
}

double avg_magnitude(double data[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += fabs(data[i]);
	}
	return sum / size;
}

double avg_power(double data[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += pow(data[i], 2);
	}
	return sum / size;
}
