/*
 * Soroush Ashrafi
 * Workshop 6 - Throws a pair of dice until the sum of the values on their top faces equals a specified number
 * October 2015
 */

// include needed headers
#include <stdio.h>
#include <stdlib.h>

void main()
{

	// variable for total sought and total of the roll
	int total = 13, rollTotal = 0;

	// variable for a counter to see how many rolls before user got the input total sought
	int counter = 0;

	// ask user to input total sought and make sure it's more than 1 and less than 13
	while(total <= 1 || total >= 13)
	{

		printf("Please enter total sought: \n");
		scanf("%i", &total);

		// tell user to enter a value less than 13 they enter higher
		if(total <= 1 || total >= 13)
			printf("Value must be between 1 and 13!\n");
	}

	while(total != rollTotal)
	{

		// vatiables for the 2 random dice rolls
		int rand1, rand2;

		// roll the dice twice
		printf("Result of this roll: %i + %i\n", rand1 = rand() % 6 + 1, rand2 = rand() % 6 + 1);

		// set roll total
		rollTotal = rand1 + rand2;

		// add to counter
		counter++;
	}

	// tell the user how many rolls it took until they got the input sought
	printf("You got the value for input total sought in %i rolls.\n", counter);
}
