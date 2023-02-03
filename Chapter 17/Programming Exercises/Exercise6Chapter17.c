//  description - Exercise6Chapter17.c
//  v1.0
#include <stdio.h>
#include <stdbool.h>
#define SIZE 26
bool binary_search(const int * array, int count, int searched);

int main(void)
{
	int myarray[SIZE];
	int i;
    int number = 8388609;

	for (i = 0, myarray[0] = 1; i < SIZE; i++)
	{
		if (0 != i)
		{
			myarray[i] = 2 * myarray[i - 1];
		}
	}
	for (i = 0; i < SIZE; i++)
	{
		printf("%2d:%9d ", i, myarray[i]);
		if (0 == (i + 1) % 5)
		{
			putchar('\n');
		}
	}
	printf("\nWe are looking for %d\n", number);
	if (binary_search(myarray, SIZE, number))
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}
	return 0;
}

bool binary_search(const int * array, int count, int searched)
{
	int temp_max = count - 1;
	int temp_min = 0;
	while (1 < temp_max - temp_min)
	{
		if (searched == array[(temp_max + temp_min) / 2])
		{
			return true;
		}
		else if (searched < array[(temp_max + temp_min) / 2])
		{
			temp_max = (temp_max + temp_min) / 2;
		}
		else
		{
			temp_min = (temp_max + temp_min) / 2;
		}
	}
	if (searched == array[temp_min] || searched == array[temp_max])
	{
		return true;
	}
	return false;
}