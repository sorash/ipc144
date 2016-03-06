/*
 * Soroush Ashrafi
 * IPC144 Workshop 9
 * November 2015
 */

// include needed headers
#include <stdio.h>

// max sales number
#define MAX_SALES 10

// struct for a sale
struct sale
{
	
	int quantity;
	double price;
	char tax;
};

// function prototypes
int enter(struct sale s[], int maxno);
void total(const struct sale s[], int no_sales);

void main()
{

	int no_sales;

	// sales array
	struct sale s[MAX_SALES];

	// header
	printf("Sale Records\n");
	printf("============\n");

	// get data from user and save the number of items entered
	no_sales = enter(s, MAX_SALES);

	// show totals
	total(s, no_sales);
}

// gets sales data from user
int enter(struct sale s[], int maxno)
{

	// counts the number of elements user inputs
	int counter = 0;

	// keeps the loop running
	int stop = 0;

	// ask user for data unless they enter 0
	while(!stop)
	{

		printf("Quantity:\t");
		scanf("%i", &s[counter].quantity);

		// stop loop if user entered 0
		if(s[counter].quantity == 0)
			stop = 1;
		else
		{

			printf("Unit price:\t");
			scanf("%lf", &s[counter].price);

			printf("Taxable (y/n):\t");
			scanf(" %c", &s[counter].tax);
			
			// add to counter
			counter++;
		}
	}

	return counter;
}

// totals the sales before the tax, hst, and after tax and displays them
void total(const struct sale s[], int no_sales)
{

	// variables for subtotall, tax, and total
	double sub = 0, tax = 0, total = 0;

	// count through all sales
	int i;
	for(i = 0; i < no_sales; i++)
	{

		if(s[i].tax == 'y' || s[i].tax == 'Y')
			tax += (s[i].quantity * s[i].price) * 0.13;

		sub += s[i].quantity * s[i].price;
	}

	// add total
	total += sub + tax;

	// display
	printf("Subtotal:\t%.2lf\n", sub);
	printf("Tax:\t%.2lf\n", tax);
	printf("Total:\t%.2lf\n", total);
}
