//  The Heap - nowe funkcje
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int * pointer;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program pozycza i zwraca pamiec dodatkowa.\n");
	
/*  Code ----------------------------------------------------------------------*/
	pointer = (int *) malloc(5 * sizeof(int));			// borrow extra memory
	
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;

	free(pointer);										// give it back

	return 0;
}