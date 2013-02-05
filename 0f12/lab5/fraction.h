/** Fraction Library */

struct fraction {
	int num;  // numerator
	int den;  // denominator
};

/* Print fraction f in the form a/b. */
void print_fraction(struct fraction f);


/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
   */
int gcd(int a, int b);

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
struct fraction reduce(struct fraction f);


/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
   */
struct fraction make_fraction(int a, int b);

/* Return a fraction that is the product of f1 and f2 in reduced form. */
struct fraction multiply_fractions (struct fraction f1, struct fraction f2);

/* Return a fraction that is the sum of f1 and f2 in reduced for. */
struct fraction add_fractions (struct fraction f1, struct fraction f2);
