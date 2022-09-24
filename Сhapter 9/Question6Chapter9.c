//  Question6Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void zmien (int * px, int * py);


/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int x, y;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje zmien()\n");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj liczbe calkowita, ktore zostyanie przypisane do x: ");
	scanf("%d", &x);
	printf("Podaj liczbe calkowita, ktore zostyanie przypisane do y: ");
	scanf("%d", &y);	
	printf("\nPoczatkowo x = %5d, a y = %5d.\n", x, y);
	zmien(&x, &y);
	printf("A teraz    x = %5d, a y = %5d.\n", x, y);
/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}


void zmien (int * px, int * py)
{
	int a, b;
	a = *px;
	b = *py;
	*px = a + b;
	*py = a - b;
}


//Inne rozwiazania:
/*
void zmien (int * pa, int * pb)
{
	int temp;
	temp = *pa + *pb;
	*pb = *pa - *pb;
	*pa = temp;
}
*/
/*
void zmien (int * pa, int * pb)
{
	*pa += *pb;
	*pb = *pa - 2 * *pb;
}
*/