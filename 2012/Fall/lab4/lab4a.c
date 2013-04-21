#include <stdio.h>

int main(int argc, const char *argv[])
{
	int n1, n2;
	float f;
	double d;
	char c;
	bool b;
	char s[80];

	FILE * pFile = fopen ("myfile.txt","w");
	FILE * iFile = fopen("infile.txt", "r");
	if (pFile!=NULL) {
		fprintf (pFile, "fopen example");
	}

	fprintf(pFile, "Please enter a number: ");
	fscanf(iFile, "%f", &n1);
	fprintf(pFile, "%d\n", n1);


	fprintf(pFile, "Please enter two numbers: ");
	fscanf(iFile, "%d %d", &n1, &n2);
	fprintf(pFile, "%d %d\n", n1, n2);


	fprintf(pFile, "Please enter a float and a double: ");
	fscanf(iFile, "%f %lf", &f, &d);
	fprintf(pFile, "%f %lf\n", f, d);

	fprintf(pFile, "Please enter a character: ");
	fscanf(iFile, " %c", &c);
	fprintf(pFile, "%c\n", c);


	fprintf(pFile, "Please enter a boolean: ");
	fscanf(iFile, "%d", &b);
	fprintf(pFile, "%d\n", b);

	fprintf(pFile, "Please enter a string: ");
	fscanf(iFile, "%s", s);
	fprintf(pFile, "%s\n", s);

	fclose (pFile);
	return 0;
}
