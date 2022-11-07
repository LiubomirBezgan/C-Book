//  test funkcji usun_odstepy() - Exercise10Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#define ROZMIAR 81
void usun_odstepy(char * lancuch);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje usun_odstepy(), ktora usuwa odstepy z lancucha.");

/*  Code ----------------------------------------------------------------------*/
	puts("Wpisz pusty wiersz, aby zakonczyc.");
	puts("\nPodaj lancuch:");
	wczytaj(tablica, ROZMIAR);
	while (*tablica != '\0')
	{
		printf("Przed: %s\n", tablica);
		usun_odstepy(tablica);
		printf("   Po: %s\n", tablica);
		puts("\nPodaj lancuch:");
		wczytaj(tablica, ROZMIAR);
	}


/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void usun_odstepy(char * lancuch)
{
	char * zapisuje = lancuch;
	char * pobiera = lancuch;
	while (*pobiera != '\0')
	{
		if (*pobiera == ' ')
		{
		    while (*pobiera == ' ')
		    {
		        pobiera++;
		    }
		}
		*zapisuje++ = *pobiera++;
	}
	*zapisuje = '\0';
}