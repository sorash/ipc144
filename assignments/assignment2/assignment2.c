/*
 * I declare that the attached assignment is wholly my
 * own work in accordance with Seneca Academic Policy.  No part of this
 * assignment has been copied manually or electronically from any
 * other source (including web sites) or distributed to other students.
 * Name: Soroush Ashrafi	Student ID: 030265151
 */

/*
 * Soroush Ashrafi
 * IPC144 Assignment 2
 * November 2015
 */

// include needed headers
#include <stdio.h>
#include <string.h>

// define color codes
// codes learned from: http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define red "\x1B[31m"
#define green "\x1B[32m"
#define white "\x1B[37m"
#define yellow "\x1B[33m"

// prototypes
int getInteger(int min, int max);
void getDailyData(float* high, float* low, char* condition);
float average(float first, float second);
void draw(char c, int num);
char symbolToDraw(char condition, float averageTemperature);
void displayResult(int days, float allDaysAverage);

void main()
{

	// variables
	int numDays;
	int i;
	float sum = 0;
	float dailyHigh;
	float dailyLow;
	char conditions;
	float dailyAvg = 0;

	// title
	printf("%sWeather Analyzer 2.0\n", green);
	printf("====================%s\n", white);

	// ask user for number of days
	printf("%sHow many days of data?%s\n", yellow, white);

	// get an integer between 1 and 14
	numDays = getInteger(1, 14);

	// ask user for data for all days
	for(i = 0; i < numDays; i++)
	{

		// get input from user
		getDailyData(&dailyHigh, &dailyLow, &conditions);
		dailyAvg = average(dailyHigh, dailyLow);
		printf("%sToday's average temperature is: %.2f%s\n", green, dailyAvg, white);
		sum += dailyAvg;
		draw(symbolToDraw(conditions, dailyAvg), 20);
	}

	displayResult(numDays, (sum/numDays));
}

// asks the user for an integer between the minimum and maximum values inclusive
int getInteger(int min, int max)
{

	// varaible for input
	int num;

	// ask user for the number in range
	while(num < min || num > max)
	{

		printf("%sEnter a number between %i and %i inclusive:%s\n", yellow, min, max, white);
		scanf("%i", &num);

		// tell user if input is invalid
		if(num < min || num > max)
			printf("%sValue must be within the range of %i and %i inclusive!%s\n", red, min, max, white);
	}
	return num;
}

// asks user for daily data, including high and low temperatures and condition for the day
// and makes sure the high value is a larager value than low value
// also makes sure the condition given is one of the valid inputs
void getDailyData(float* high, float* low, char* condition)
{

	// variable that checks how many values were enetered by user
	int values = 0;

	// make sure user entered values for all fields
	while(values < 3)
	{

		printf("%sPlease enter the high and low temperatures, followed by condition ('s' for sunny, 'c' for cloudy, and 'p' for precipitation) for the day, all separated by commas.%s\n", yellow, white);
		values = scanf("%f, %f, %c", high, low, condition);

		// clear buffer
		while(getchar() != '\n');

		if(values < 3)
			printf("%sPlease enter values for all fields!%s\n", red, white);
		else
		{
			
			while((*high < *low) || (*condition != 'c' && *condition != 's' && *condition != 'p'))
			{

				// tell user the error that occured
				if(*high < *low)
					printf("%sHigh temperature can not be less than low temperature!%s\n", red, white);
				if(*condition != 'c' && *condition != 's' && *condition != 'p')
					printf("%sCondition can only be one of the following: 'c' for cloudy, 's' for sunny, and 'p' for precipitation!%s\n", red, white);
				
				getDailyData(high, low, condition);
			}
		}
	}
}

// returns an average of the first and second floats given
float average(float first, float second)
{

	return (first + second) / 2;
}

// draws a row of characters based on given character and number of times to be repeated
void draw(char c, int num)
{

	int i;
	for(i = 0; i < num; i++)
		printf("%s%c", green, c);
	printf("%s\n", white);
}

// returns a character based on given weather condition and average temperature
char symbolToDraw(char condition, float averageTemperature)
{

	switch(condition)
	{

		case 'c':
			return '~';
			break;
		case 's':
			return '@';
			break;
		// for precipitation, the average temperature modifies the character
		case 'p':
			if(averageTemperature > 0)
				return ';';
			else
				return '*';
			break;
	}
}

// dispalys the average temperature for a period of days
void displayResult(int days, float allDaysAverage)
{

	char daysStr[5];
	
	switch(days)
	{
	
		case 1:
			strcpy(daysStr, "one");
			break;
		case 2:
			strcpy(daysStr, "two");
			break;
		case 3:
			strcpy(daysStr, "three");
			break;
		case 4:
			strcpy(daysStr, "four");
			break;
		case 5:
			strcpy(daysStr, "five");
			break;
		case 6:
			strcpy(daysStr, "six");
			break;
		case 7:
			strcpy(daysStr, "seven");
			break;
		case 8:
			strcpy(daysStr, "eight");
			break;
		case 9:
			strcpy(daysStr, "nine");
			break;
	}

	// display results
	if(days <= 9)
	{
		
		printf("%sYour ", green);

		int i;
		for(i = 0; daysStr[i] != '\0'; i++)
			printf("%c", daysStr[i]);

		printf(" day average is: %.2f%s\n", allDaysAverage, white);
	}
	else
		printf("%sYour %i day average is: %.2f%s\n", green, days, allDaysAverage, white);
}
