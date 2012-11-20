#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int** a = (int**)malloc(7 * sizeof(int*));
	int* b = (int*)malloc(7*sizeof(int));

	for (int i = 0; i < 7; i++) {
		b[i] = i;
		a[i] = &b[i];
		printf("b[i]: %d, a[i]: %x, *a[i]: %d.\n", b[i], a[i], *a[i]);
	}
	
	return 0;
}

