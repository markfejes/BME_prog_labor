#include <stdio.h>

int* searchInArray (int arrayIn[], int arrayInSize, int searchFor);

int main(void){
	int* helper; int found;
	int numbers[100] = {0};
	numbers[67] = 39;

	helper = searchInArray(numbers, 100, 329);

	found = helper != NULL ? *helper : -1;

	printf("%d\n", found);

	return 0;
}


int* searchInArray (int arrayIn[], int arrayInSize, int searchFor)
{
	int i;
	for (i = 0; i < arrayInSize; i++)
	{
		if (arrayIn[i] == searchFor)
		{
			return &arrayIn[i];
		}
	}

	return NULL;
}