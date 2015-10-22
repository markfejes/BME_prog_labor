#include <stdio.h>
#include <string.h>

void trimString(char input[], char output[]);

int main(void){

	char input[100] = {0};
	char trimmedString[100] = {0};

	gets_s(input, 100);

	trimString(input, trimmedString);

	printf ("%s\n", trimmedString);

}

void trimString(char input[], char output[]){

	int i;
	int spaceBefore = 0; int spaceAfter = 0;
	int sizeOfInput = strlen (input);
	int j = sizeOfInput;

	while ( *input++ == ' ')
	{
		spaceBefore++;
	}

	while ( input[sizeOfInput-2] == ' ')
	{
		spaceAfter++;
		j--;
	}

	for (i = 0; i < sizeOfInput-spaceAfter-spaceBefore; i++)
	{
		output[i] = input[spaceBefore + i];
	}

}