/*
 * Soroush Ashrafi
 * Workshop 4
 * Calculates future value of a specified amount of money
 * October 2015
 */

// include needed headers
#include <stdio.h>

// protoype for calculate function
double calcFutureValue(double, double, int);

void main()
{

	// variables for principal amount, annual rate, and number of years
	double principal, rate;
	int years;

	// ask user for the principal amount, annual rate, and number of years
	printf("Please enter the principal amount, annual rate, and number of years for the investment respectively:\n");
	scanf("%lf", &principal);
	scanf("%lf", &rate);
	scanf("%i", &years);

	// show user the future value based on the given values
	printf("The future value for the investment will be: \t$%.2lf\n", calcFutureValue(principal, rate, years));
}

// calculates the future value based on principal amount, annual rate, and number of years for the investment
double calcFutureValue(double principal, double rate, int years)
{

	// variable for future value
	double future = 1;
       	
	// int used for loop because it cant be initiated in the loop.........
	int i;

	// only other way i can think of to do exponents without using other headers
	for(i = 0; i < years; i++)
		future *= 1 + rate;
	
	future *= principal;
	return future;
}
