/* 
 * Soroush A.
 * Workshop 3
 * Checks if given SIN number is valid
 * October 2015
 */

// include needed headers
#include <stdio.h>

int main(void)
{

	// variable for the input SIN number, and a variable that controls the loop
	long SIN;
	int keepRunning = 1;

	// infinite loop that keeps asking user for a sin number until they choose to quit
	while(keepRunning)
	{

		// ask user for a SIN number
		printf("Please enter a SIN number to validify (Enter 0 to quit): ");
		scanf("%ld", &SIN);
		
		// if user entered 0, end the loop and exit
		if(SIN == 0)
		{

			// set setopper to true and break
			printf("Have a nice day! \n");
			keepRunning = 0;
		}
		// else check the number
		else
		{

			// tell user if the given number is valid or not after checking it
			if(isValidSIN(SIN) == 1)
				printf("This is a valid SIN number.\n");
			else
				printf("This is not a valid SIN number. \n");
		}
	}
}

// checks if the given sin number is valid or not
int isValidSIN(long SIN)
{
	
	// variable for the digits and totals
	int checkDigit, digit1, digit2, altDigit, sum1 = 0, sum2 = 0, altSum = 0, total = 0;

	// get check digit
	checkDigit = SIN % 10;
	SIN /= 10;

	// get alternates
	while(SIN > 0)
	{

		// get first alternates, multiply it by 2, and add them
		digit1 = SIN % 10;
		sum1 = digit1 * 2;

		// get every digit and add it
		while(sum1 > 0)
		{
			
			altSum += sum1 % 10;
			sum1 /= 10;
		}

		// divide by ten to get the next digit
		SIN /= 10;

		// get second alternates and add them
		digit2 = SIN % 10;
		sum2 += digit2; 

		// divide by ten again to get the next digit again
		SIN /= 10;
	}

	// find total and check if sin number is valid from check digit
	total = altSum + sum2;
	
	// use for debugging
	// printf("sum1: %i\nsum2: %i\naltSum: %i\ncheckDigit: %i\ntotal: %i\n", sum1, sum2, altSum, checkDigit, total);

	if((total + checkDigit) % 10 == 0)
	       return 1;
	else
		return 0;	

	//printf("sum1: %i\n sum2: %i\n altSum: %i\n checkDigit: %i\n", sum1, sum2, altSum, checkDigit);
}
