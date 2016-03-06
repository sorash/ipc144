/*
 * Soroush Ashrafi
 * IPC144 Assignment 2
 * November 2015
 */

// include needed headers
#include <stdio.h>

// prototypes
int getInteger(int min, int max);
void getDailyData(float* high, float* low, char* condition);

void main()
{

	// variable for number of days user will enter weather data for, ask user for the value
	int days = getInteger(1, 14);

	// arrays for high and low temperatures, and condition
	float high[days], low[days];
	char condition[days];

	// ask user for daily data
	int i;
	for(i = 0; i < days; i++)
		getDailyData(&high[i], &low[i], &condition[i]);
}

// asks the user to enter an integer between the given min and max, and makes sure the value is in the range
int getInteger(int min, int max)
{

	// variable for input
	int num;

	// ask user to input a number between the min and max
	while(num < min || num > max)
	{
		printf("Please enter the number of days you will be entering data for:\n", min, max);
		scanf("%i", &num);

		// tell user if their input is invalid
		if(num < min || num > max)
			printf("Value must be within the range of %i and %i inclusive!\n", min, max);
	}
}

// asks the user to enter data weather for a day, including high and low temperatures, and the condition
void getDailyData(float* high, float* low, char* condition)
{

	// get how many values were entered by user
//	int valuesEntered = 0;

	// make sure user entered values for all fields
//	while(valuesEntered < 3)
//	{

//		printf("Please enter the high and low temperatures, followed by the condition ('s' for sunny, 'c' for cloudy, and 'p' for precipitation) for this day, separated by commas:\n");
//		valuesEntered = scanf("%f, %f, %c", high, low, condition);
	
//		if(valuesEntered < 3)
//			printf("Please enter values for all fields!\n");
//		else
//		{

//			while((*high < *low) || (*condition != 'c' && *condition != 's' && *condition != 'p'))
//			{

				// tell user the error that happened
//				if(*high < *low)
//					printf("High temperature can not be less than low temperature!\n");
//				else if(*condition != 'c' && *condition != 's' && *condition != 'p')
//					printf("Condition can only be one of the following: 'c' for cloudy, 's' for sunny, and 'p' for precipitation!\n");
//			}
//		}
//	}
}
