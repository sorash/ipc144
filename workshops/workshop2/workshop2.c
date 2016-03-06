/* workshop2 */

// import needed headers
#include <stdio.h>

int main(void){
	
	// variables for item count
	int count;

	// variables fo price, subtotal and total, tax amount, cash tendered, and returning amount
	double price, subtotal, total, tax, cash, returnAmount;

	// variables for change, loonies, and cents for return
	int change, loonies, cents;

	// ask user for number of items purchased
	printf("Please enter how many items were purchased: \n");
	scanf("%i", &count);
	
	// ask user for price of items
	printf("Please enter the base price: \n");
	scanf("%lf", &price);
	
	// calculate the total with tax
	subtotal = price * count;
	tax = subtotal * 0.13;
	total = subtotal + tax;
	
	// show user the tax, with the price before and after
	printf("Subtotal:\t%.2f \n", subtotal);
	printf("HST(13%):\t%.2f \n", tax);
	printf("Total after tax:\t%.2f \n", total);

	// ask user for the tendered cash
	printf("Please enter how much cash is tendered: \n");
	scanf("%lf", &cash);

	// calculate how much cash is to be returned
	returnAmount = cash - total;
	printf("Change owed: \t %.2lf \n", returnAmount);

	// calculate the loonies and change needed for return
	change = cash - total;
	loonies = change % 10;
	change = (cash - total) * 100;
	cents = change % 100;
	printf("Change loonies: \t %i \n", loonies);
	printf("Change cents: \t %i \n", cents);
}
