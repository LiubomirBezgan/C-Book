//  my_delay() - Exercise4Chapter16.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

void my_delay(double s);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double s;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to test my_delay() function.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter a delay (in seconds):");
	while ( (1 != scanf("%lf", &s)) || (s < 0.0) )
	{
		clear_buffer();
		puts("Wrong values. Please try again.");
		puts("\nPlease enter a delay (in seconds):");
	}
	puts("Please wait.");
	my_delay(s);
	puts("OK, let's go!");
/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

void my_delay(double s)		// s is time in seconds
{
	clock_t start = clock();
	while ( s > ( ( (double) (clock() - start) ) / CLOCKS_PER_SEC) ) 
	{
		continue;
	}
}