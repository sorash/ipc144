/*
 * Soroush Ashrafi
 * IPC144 Workshop7
 * November 2015
 */

// include needed headers
#include <stdio.h>

// define a value for the number of arrays, def 100
#define ITEM_COUNT 100

// prototypes
long getUPC();
double getPrice();
int getQuantity();
void showStock(int count, long barcode[], double price[], int quantity[]);

void main()
{

	// arrays for barcode, price, and quantity
	long barcode[ITEM_COUNT];
	double price[ITEM_COUNT];
        int quantity[ITEM_COUNT];

	// a counter for the number of items user enters data for
	int count = 0;

	// variable for stopping the loop
	int stop = 0;

	// ask user for the information and exit when the stopper is 1
	while(stop == 0)
	{

		// variable for user input
		long input;

		// ask for barcode, if it returns 0, stop the loop
		if((input = getUPC()) == 0)
			stop = 1;
		// else get other info from user
		else
		{
			// save the barcode
			barcode[count] = input;
	
			// ask for price
			price[count] = getPrice();

			// ask for quantity
			quantity[count] = getQuantity();

			// add to counter
			count++;
		}
	}

	// show the stock information
	showStock(count, barcode, price, quantity);	
}

// gets a barcode from the user and returns it
long getUPC()
{

	// variable for input
	long input;

	// ask user for barcode
	printf("Barcode:\t");
	scanf("%ld", &input);

	// return input
	return input;
}

// gets a price from the user and returns it
double getPrice()
{

	// variable for input
	double input;

	// ask user for barcode
	printf("Price:\t");
	scanf("%lf", &input);

	// return input
	return input;
}

// gets a quantity from the user and returns it
int getQuantity()
{

	// variable for input
	int input;

	// ask user for barcode
	printf("Quantity:\t");
	scanf("%i", &input);

	// return input
	return input;
}

// shows the stock information, including barcode, price, and quantity
// PARAMS number of items to show, barcodes, prices, and quantities to show
void showStock(int count, long barcode[], double price[], int quantity[])
{

	// show titles
	printf("\nBarcode\t\tPrice\t\tQuantity\tValue\n");
	printf("-------------------------------------------------------------\n");

	// variable for total value of goods
	double total = 0;

	// show information based on the given count
	int i;
	for(i = 0; i < count; i++)
	{

		printf("%ld\t$%.2lf\t\t%i\t\t$%.2lf\n", barcode[i], price[i], quantity[i], price[i] * quantity[i]);

		// add to total value
		total += price[i] * quantity[i];
	}

	// show total value
	printf("\nTotal value of goods in stock:\t%.2lf\n", total);
}
