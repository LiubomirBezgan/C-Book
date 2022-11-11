//  statystyki tekstowe - Exercise12Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <ctype.h>
#include <stdbool.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int liczba_slow = 0;
	unsigned int liczba_m_liter = 0;
	unsigned int liczba_w_liter = 0;
	unsigned int liczba_znakow_przestankowych = 0;
	bool w_slowie = false;
	char ch;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program pobiera dane wejsciowe do momentu wystapienia konca pliku, a nastepnie wyswietla statystyki.\n");
	
/*  Code ----------------------------------------------------------------------*/
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
		{
			liczba_w_liter++;
		}
		if (islower(ch))
		{
			liczba_m_liter++;
		}
		if (ispunct(ch))
		{
			liczba_znakow_przestankowych++;
		}

		if (w_slowie)				// jesli jestesmy w slowie
		{
			if (!isalpha(ch))
			{
				w_slowie = false;
			}
		}
		else						// jesli nie jestesmy w slowie
		{
			if (isalpha(ch))
			{
				liczba_slow++;
				w_slowie = true;
			}	
		}

	}
	printf("Liczba slow: %u\n", liczba_slow);
	printf("Liczba wielkich liter: %u\n", liczba_w_liter);
	printf("Liczba  malych  liter: %u\n", liczba_m_liter);
	printf("Liczba znakow przestankowych: %u\n", liczba_znakow_przestankowych);

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}