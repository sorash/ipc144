/*
 * Soroush Ashrafi
 * Workshop4_2
 * Table of primes
 * October 2015
 */

// include needed headers
#include <stdio.h>

// prototype for finding prime numbers method
int findNextPrime(int, int);

void main()
{

	// variables for upper limit and number of columns
	int limit, columns;

	// ask user for the limit and number of columns
	printf("Please enter upper limit and number of columns respectively: \n");
	scanf("%i", &limit);
	scanf("%i", &columns);

	findNextPrime(2, limit);
}

// find the next prime number starting from given number and the upper limit
int findNextPrime(int current, int limit)
{

	int i;
	for(i = current; i < limit; i++)
	{

		int x;
		for(x = 2; x < current; x++)
		{

			if(current % x == 0)
				printf("Not prime: %i\n", current);
			else if((current % current == 0) && (current % 1 == 0))
				printf("Prime: %i\n", current);
		}

		current++;
	}
}
