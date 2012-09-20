#include <stdio.h>

int main(int argc, const char *argv[])
{
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int *ptr = array;

	printf("\n");
	printf("array[0]: %d\n", *ptr);
	printf("array[1]: %d\n", *(++ptr));
	
	return 0;
}
