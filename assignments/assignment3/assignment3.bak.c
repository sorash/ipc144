/*
 * Soroush Ashrafi
 * Assignment 3
 * November-December 2015
 */

// include needed headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*an instance of this struct holds the weather data for a single day*/
struct DailyData
{
	int day;
	int month;
	int year;
	float high;
	float low;
	float precipitation;
	char condition;
};

/*an instance of this struct holds summary information for the weather
 * for a given month*/
struct MonthlyStatistic
{
	float minTemperature;
	float maxTemperature;
	float averageTemperature;
	float totalPrecipitation;
};

// prototypes
int readDailyData(FILE* fp, struct DailyData allData[]);
int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz, struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[], int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );

int main(void){
	
	// open file for reading
	FILE* fp = fopen("historicaldata.csv", "r");
	
	// make sure file exists
	if(!fp)
	{
		printf("you need to put historicaldata.csv into this directory\n");
		exit(0);
	}
	
	// data
	struct DailyData allData[3000];
	struct DailyData yearData[366];
	int numTotalRecords;

	// get number of records
	numTotalRecords = readDailyData(fp, allData);

	int year;
	int reportType;
	int i;
	struct MonthlyStatistic monthly[12];
	
	// ask for year and type of report
	printf("Please enter the year for the report: ");
	scanf("%d",&year);
	printf("Please enter the type of report you wish to generate:\n");
	printf("1) summary\n");
	printf("2) detailed\n");
	scanf("%d",&reportType);
	
	int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
	sortYearData(yearData,numDays);

	for(i=0;i<12;i++)
		getStats(i+1,yearData,numDays,&monthly[i]);

	/////////////////////////////////
	for(i = 0; i < numDays; i++)
	printf("%i -- %i, %i\n", i, yearData[i].month, yearData[i].day);
	/////////////////////////////////

	printf("Weather summary for %d\n",year);
	printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
	printf("|-----------|-------|-------|-------|---------|\n");
	
	for(i=0;i<12;i++)
		printMonthlyStatistic(i+1,&monthly[i]);
	
	printf("\n\n");
	printf("Precipitation Graph\n\n");
	
	for (i=0;i<12;i++)
		graphLine(i+1,&monthly[i]);
		
	if(reportType == 2)
	{
		printf("\n\n");
		printf("Detailed report:\n");
		printVerbose(yearData,numDays);
	}
	
	return 0;
}

int readDailyData(FILE* fp, struct DailyData allData[])
{

	int i = 0;
	while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n", &allData[i].year,&allData[i].month,&allData[i].day, &allData[i].high,&allData[i].low,&allData[i].precipitation, &allData[i].condition) == 7)
		i++;
	
	return i;
}

// copies all data from allData to yearData that matches the yearWanted
int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]){

	// counter for how many records were copied
	int counter = 0;

	// loop through all data
	int i;
	for(i = 0; i < sz; i++)
	{

		// check if year is wanted and copy data
		if(allData[i].year == yearWanted)
		{
			yearData[counter] = allData[i];
			counter++;
		}
	}

	return counter;
}

// sorts the records in yearData, so that earliest record is the first
void sortYearData(struct DailyData yearData[], int sz){

	// variables for for loops and a temporary struct to hold values to be replaced
	int i, u, y;
	struct DailyData tmp;

	// sort months first
	for(i = 0; i < sz; i++)
	{
		for(u = i + 1; u < sz; u++)
		{

			// copy data
			if(yearData[i].month > yearData[u].month)
			{

				tmp = yearData[i];
				yearData[i] = yearData[u];
				yearData[u] = tmp;
			}
		}
	}

	// sort days
	for(i = 1; i <= 12; i++)
	{

		for(u = 0; u < sz; u++)
		{

			for(y = u + 1; y < sz; y++)
			{

				if(yearData[u].month == i && yearData[y].month == i)
				{
					if(yearData[u].day > yearData[y].day)
					{

						tmp = yearData[u];
						yearData[u] = yearData[y];
						yearData[y] = tmp;
					}
				}
			}
		}
	}

	// make a file for debugging
	FILE *fp;
	fp = fopen("data", "w");
	for(i = 0; i < sz; i++)
		fprintf(fp, "%i, %i, %i, %f, %f, %f, %c\n", yearData[i].year, yearData[i].month, yearData[i].day, yearData[i].low, yearData[i].high, yearData[i].precipitation, yearData[i].condition);
}

// finds minimum and maximum and average temperature and total precipitation for the month
void getStats(int month, const struct DailyData yearData[], int sz,struct MonthlyStatistic* monthly){

	float lowest = 0, highest = 0, avg = 0, prec = 0;
	int i, valueSet = 0;

	// loop through all data
	for(i = 0; i < sz; i++)
	{

		if(yearData[i].month == month)
		{	

			/*
			// set the lowest and highest to first index, and make sure it doesnt get reset everytime the loop runs
			if(!valueSet)
			{

				lowest = yearData[i].low;
				highest = yearData[i].high;
				valueSet = 1;
			}

			// find lowerst
			if(yearData[i].low < lowest)
				lowest = yearData[i].low;

			// find highest
			if(yearData[i].high > highest)
				highest = yearData[i].high;

			// add all precipitation
			prec += yearData[i].precipitation;

			// get average
			avg = average(avg, average(yearData[i].low, yearData[i].high));
			*/
		}
	}
	
	// save to month stats
	monthly[month].minTemperature = lowest;
	monthly[month].maxTemperature = highest;
	monthly[month].averageTemperature = avg;
	monthly[month].totalPrecipitation = prec;

	// used for debugging
	//printf("month: %i -- max: %.2f, min: %.2f, prec: %.2f, avg: %.2f\n", month, monthly[month].maxTemperature, monthly[month].minTemperature, monthly[month].totalPrecipitation, monthly[month].averageTemperature);
}

// prints out a single row of summary table 
void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){


}

void graphLine(int month,const struct MonthlyStatistic* monthly){

}
	
// prints details of weather data for each record in yearData
void printVerbose(const struct DailyData yearData[],int sz){

	// array of month names
	char months[12][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	// loop through all data
	int i;
	
	for(i = 0; i < sz; i++)
	{
		
		printf("%i, ", i);
		printf("%i ", yearData[i].month);
		printf("%i ", yearData[i].day);
		printf("\n");
	}
}
	                    
// returns the symbol to draw based on the average temperature and condition
char symbolToDraw(char condition, float avgTemp){

	switch(condition)
	{

		case 's':
			return '@';
			break;
		case 'c':
			return '~';
			break;
		case 'p':
			if(avgTemp < 0)
				return '*';
			else if(avgTemp >= 0)
				return ';';
			break;
	}
}

// returns the average of the given two numbers
float average(float first, float second){

	return (first + second) / 2;
}

// prints the symbol given as many times as it is passed in
void draw( char c, int num ){

	int i;
	for(i = 0; i < num; i++)
		printf("%c", c);
	printf("\n");
}
