//  test funkcji myatoi() - Exercise15Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <ctype.h>
#define ROZMIAR 81

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char array[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje myatoi().\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Podaj liczbe calkowita:");
	scanf("%s", array);
	while (getchar() != '\n')
	{
		continue;
	}
	printf("Wynik funkcji myatoi(): %d\n", myatoi(array));
	printf("%d + 4 = %d\n", myatoi(array), myatoi(array) + 4);

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}