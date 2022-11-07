//  test funkcji odwroc() - Exercise9Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#define ROZMIAR 81
void odwroc(char * lancuch);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje odwroc(), ktora odwraca zawartosc lancucha.");

/*  Code ----------------------------------------------------------------------*/
	puts("Wpisz pusty wiersz, aby zakonczyc.");
	puts("\nPodaj lancuch:");
	wczytaj(tablica, ROZMIAR);
	while (*tablica != '\0')
	{
		printf("Przed: %s\n", tablica);
		odwroc(tablica);
		printf("   Po: %s\n", tablica);
		puts("\nPodaj lancuch:");
		wczytaj(tablica, ROZMIAR);
	}


/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void odwroc(char * lancuch)
{
	char temp;
	int i;
	int licznik = 0;
	while (*lancuch++ != '\0')
	{
		licznik++;
	}
	lancuch -= licznik + 1;

	for (i = 0; i < licznik / 2; i++)
	{
		temp = *(lancuch + i);
		*(lancuch + i)  = *(lancuch + (licznik - i - 1));
		*(lancuch + (licznik - i - 1)) = temp;

	}
}