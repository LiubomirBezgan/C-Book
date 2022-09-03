//  opis - Exercise4Chapter8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	bool w_slowie = false;
	char ch;
	float wynik;
	unsigned int liczba_slow=0, liczba_liter=0; 
	
/*  Description ---------------------------------------------------------------*/
	puts("Program odczytuje dane z pliku i wyswietla srednia liczbe liter w slowie.\n");
	
/*  Code ----------------------------------------------------------------------*/
	while ((ch=getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			liczba_liter++;
			w_slowie = true;
		}
		else if(w_slowie)
		{
			liczba_slow++;
			w_slowie = false;
		}
		else
			w_slowie = false;

	}
	wynik = liczba_liter / liczba_slow;
	printf("liczba_slow = %u; liczba_liter = %u.\n", liczba_slow, liczba_liter);
	printf("Srednia liczba liter w slowie wynosi %.0f.\n", wynik);
	return 0;
}