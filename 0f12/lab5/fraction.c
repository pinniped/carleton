#include <stdlib.h>  // Tip: abs(x)
#include <stdio.h>

struct fraction {
	int num;  // numerator
	int den;  // denominator
};

/* Print fraction f in the form a/b. */
void print_fraction(struct fraction f) {
	printf("%d/%d", f.num, f.den);
}


/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
*/
int gcd(int a, int b) {
	if (b == 0) {
		return abs(a);
	} else {
		return gcd(b, a % b);
	}
}

/* Return the reduced form of fraction f.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
struct fraction reduce(struct fraction f) {
	int factor = gcd(f.num, f.den);
	f.num /= factor;
	f.den /= factor;

	if (f.num == 0) {
		f.den = 1;
	} else if (f.den < 0) {
		f.num *= -1;
		f.den *= -1;
	}
	return f;
}


/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
*/
struct fraction make_fraction(int a, int b) {
	if (b == 0) {
		fprintf(stderr, "make_fraction: denominator cannot be 0.");
		exit(1);
	}
	struct fraction f;
	f.num = a;
	f.den = b;
	return reduce(f);
}

/* Return a fraction that is the product of f1 and f2 in reduced form. */
struct fraction multiply_fractions (struct fraction f1, struct fraction f2) {
	return reduce(make_fraction((f1.num * f2.num), (f1.den * f2.den)));
}

/* Return a fraction that is the sum of f1 and f2 in reduced for. */
struct fraction add_fractions (struct fraction f1, struct fraction f2) {
	struct fraction f;
	f.num = f1.num * f2.den + f2.num * f1.den;
	f.den = f1.den * f2.den;
	return reduce(f);
}
