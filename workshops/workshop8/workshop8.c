/*
 * Soroush Ashrafi
 * Workshop 8
 * November 2015
 */

// include needed headers
#include <stdio.h>
#include <string.h>

void main()
{

	// variables
	char input[100];
	int count = 0;
	int i;

	// ask user for a text to analyze
	printf("Text to be analyzed:\t");
	scanf("%100[^\n\t\v\r\f]", input);

	// count words
	for(i = 0; input[i] != '\0'; i++)
	{

		if(input[i] == ' ')
			count++;
	}

	// show count
	printf("Word count: \t%i\n", count + 1);
}
