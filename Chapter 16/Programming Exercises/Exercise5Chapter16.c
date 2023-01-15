//  The lottery - Exercise5Chapter16.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

#define LIMIT 1000

void lottery(int * array, int array_size, int number_of_picks);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int i;
	int size;
	int picks;
	int * pt_main_array;
	
/*  Description ---------------------------------------------------------------*/
	puts("THE LOTTERY\n");
	
/*  Code ----------------------------------------------------------------------*/
	// the size of array
	puts("Please enter the size of array:");
	while ( (1 != scanf("%d", &size)) || (size < 0) )
	{
		clear_buffer();
		puts("Wrong values. Please try again.\n");
		puts("Please enter the size of array:");
	}

	// array creation
	pt_main_array = (int *) malloc(size * sizeof(int));

	// filling the array
	srand((unsigned int) time(0));
	for (i = 0; i < size; i++)
	{
		pt_main_array[i] = rand() % (LIMIT+1);		// a random number from the range of 0 to LIMIT
	}

	// show the array
	for (i = 0; i < size; i++)
	{
		printf("%4d ", pt_main_array[i]);
		if (0 == (i + 1) % 10)
		{
			putchar('\n');
		}
	}
	putchar('\n');


	// picks
	puts("Please enter the number of picks:");
	while ( (1 != scanf("%d", &picks)) || (picks < 0) )
	{
		clear_buffer();
		puts("Wrong values. Please try again.\n");
		puts("Please enter the number of picks:");
	}




	lottery(pt_main_array, size, picks);


/*  Ending --------------------------------------------------------------------*/
	free(pt_main_array);
	end('#');
	return 0;
}

void lottery(int * array, int array_size, int number_of_picks)
{
	int i;
	int ** pt_picks;
	pt_picks = (int **) malloc(number_of_picks * sizeof(int *));

	for (i = 0; i < number_of_picks; i++)
	{
		pt_picks[i] = NULL;
	}
	for (i = 0; i < number_of_picks; i++)
	{
		printf("%p\n", pt_picks[i]);
	}

	puts("Here are your picks:");
	for (i = 0; i < number_of_picks; i++)
	{
		printf("%4d ", *(pt_picks[i]));
		if (0 == (i + 1) % 10)
		{
			putchar('\n');
		}
	}

	free(pt_picks);
}