/*
 * Soroush Ashrafi
 * October 2015
 * Simplifies a given fraction
 */

// include needed headers
#include <stdio.h>

// prototype for simplify function
void simplify(int *num, int* denom);

void main()
{

	// variables for numerator and denominator, and pointers
	int numerator = 0, denominator = 0, *num = &numerator, *denom = &denominator;

	// ask user for a fraction
	printf("Please enter the numerator of the fraction:\n");
	scanf("%i", num);
	while(*denom == 0)	// check if user enters zero for denominator
	{
		printf("Please enter the denominator of the fraction:\n");
		scanf("%i", denom);

		if(*denom == 0)
			printf("Denominator can not be zero.\n");
	}

	printf("The fraction is: %i/%i\n", *num, *denom);

	// simplify the fraction
	simplify(num, denom);

	// show user the simplified fraction
	if(*num == *denom)
		printf("The simplified fraction is: 1\n");
	else
		printf("The simplified fraction is: %i/%i\n", *num, *denom);
}

// simplifies a given fraction
void simplify(int *num, int *denom)
{

	// vairalbes for simplified numerator and denominator, and greatest common denominator
	int simpNum, simpDenom, gcd;

	// if numbers are the same, return 1
	if(*num == *denom)
		*num = 1, *denom = 1;
	else	// else find the greatest common denominator
	{

		gcd = findGCD(*num, *denom);
		*num /= gcd;
		*denom /= gcd;
	}		
}

// finds the greatest common denominator with 2 given numbers
int findGCD(int a, int b)
{
	
	// variable for remainder of the two numbers
	int remainder;

	// if the remainder is zero, the 2nd number is the gcd
	if((remainder = b % a) == 0)
		return a;
	else	// else try to find the gcd with the remainder
		findGCD(remainder, b);
}
