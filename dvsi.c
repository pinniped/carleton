#include <stdio.h>

int main(int argc, const char *argv[])
{
	int d, i;
	printf("Enter value for %%i:");
	scanf("%i",&i);
	printf("Your %%i value is: %i\n", i);

	printf("Enter value for %%d:");
	scanf("%d",&d);
	printf("Your %%d value is: %d\n", d);
	return 0;
}
