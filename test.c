#include <stdio.h>
int f(int, int);

int main(void)
{
	int num[3];
	num[3] = 2;
	printf("%d\n", num[3]);
	//int x = f(4,9);
	int x = f(4.33,9.25);
	printf("%d\n", x);

	
	return 0;
}

int f(int a, int b)
{
	if (a>b) {
		return a;
	} else {
		return b;
	}
}
