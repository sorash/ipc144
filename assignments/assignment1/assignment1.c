/* 
 * Soroush Ashrafi
 * IPC144 Assignment 1
 * Ask user for weather reports and shows some graphics and averages based on it
 *
 * I declare that this assignment is wholly my own work in accordance with Seneca Academic Policy. No part of this assignment
 * has been copied manually or electronically from any other source (including websites) or distributed to other students.
 * Name: Soroush Ashrafi	Student #: 030265151
 */

// include needed headers
#include <stdio.h>
#include <ctype.h>

// define a pre-set value for character repeat times, DEF 20
#define REPEAT_CHAR 20

// define characters for the conditions that will be printed
#define SUNNY_CHAR '@'
#define CLOUDY_CHAR '~'
#define POS_PREC_CHAR ';'
#define NEG_PREC_CHAR '*'

void main()
{

	// variable for number of days the user will enter data for
	int numDays = 0;

	// ask user how many days they will be entering data for
	while(numDays == 0)
	{
		
		printf("Please enter how many days you will be entering weather data for:\n");
		scanf("%i", &numDays);

		// if value entered is less than or equal to zero, tell user
		if(numDays <= 0)
			printf("Value must be higher than zero.\n");
	}

	// variables for high, low, and average temperatures, and the condition
	double high, low, avg, totalAvg = 0;
	char condition;

	// ask the user for weather data for as many days as they entered prviously
	int i; // hate how you can't do this in the actual for loop...
	for(i = 0; i < numDays; i++)
	{

		// ask user for high and low temperature of the day
		printf("Please enter the high and low temperatures of the day respectively:\n");
		scanf("%lf", &high);
		scanf("%lf", &low);

		// ask user for the condition of the day
		printf("Please enter the condition for the day (enter 's' for sunny, 'c' for cloudy, and 'p' for precipitation):\n");
		scanf(" %c", &condition);

		// calculate the average for the day and add it to the total average
		avg = (high + low) / 2;
		totalAvg += avg;

		// show user the average
		printf("Today's average temperature is: %.2lf\n", avg);

		// show the graphics based on the weather conditions and average, print out as many characters as set by the pre-set value
		int x; //...........
		for(x = 0; x < REPEAT_CHAR; x++)
		{

			// print characters based on the day's condition
			switch(tolower(condition))
			{

				case 's':
					printf("%c", SUNNY_CHAR);
					break;
				case 'c':
					printf("%c", CLOUDY_CHAR);
					break;
				case 'p':
				{
					
					// also check the average and output based on it being positive or negative
					if(avg <= 0)
						printf("%c", NEG_PREC_CHAR);
					else
						printf("%c", POS_PREC_CHAR);
					break;
				}
			}
		}

		// insert some line breaks
		printf("\n");
		printf("\n");
	}
	
	// calcluate total average for all days entered and show the user
	totalAvg /= numDays;
	printf("The average for all %i days you entered is: %.2lf\n", numDays, totalAvg);
}
