//  The Heap (an average value) - obliczenie wartosci sredniej
//  v1.1
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
int scanArray(int * array, int length);								// pobiera length sztuk liczb calkowitych i zwraca ich sume
void printArray(const int * array, int length);						// wyswietla elementy tablicy od pierwszego do length, rozdzielajac je spacja.

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int howMany;
	int total;
	float average;
	int * pointsArray;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program oblicza wartosc srednia, uzywajac Heap memory (sterty, kopca lub stogu).\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Ile liczb calkowitych planujesz wprowadzic do obliczenia sredniej arytmetycznej?");
	scanf(" %d", &howMany);
	pointsArray = (int *) malloc(howMany * sizeof(int));			// pozyczenie pamieci dodatkowej
	
	total = scanArray(pointsArray, howMany);

	average = (float) total / (float) howMany;

	// wyswietlenie wyniku
	printf("Srednia arytmetyczna z liczb ");
	printArray(pointsArray, howMany);
	printf("wynosi %.2f\n", average);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

int scanArray(int * array, int length)
{
	int i;
	int sum = 0;

	puts("Podaj wartosci:");
	for (i = 0; i < length; i++)
	{
		scanf(" %d", &array[i]);									// notacja tablicowa
		sum += array[i];											// notacja tablicowa
	}
	return sum;
}

void printArray(const int * array, int length)
{
	int j;
	for (j = 0; j < length; j++)
	{
		printf("%d ", array[j]);									// notacja tablicowa
	}
}

