//  sprawdzanie poprawnosci danych wejsciowych - Listing_8_7.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>

/*  Functions -----------------------------------------------------------------*/
long pobierz_long(void);													// sprawdz, czy wejscie jest liczba calkowita
bool zle_granice(long poczatek, long koniec, long dolna, long gorna);		// sprawdz prawidlowosc podanych granic zakresu
double suma_kwadr(long a, long b);											// oblicz sume kwadratow liczb calkowitych z zakresu od a do b

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	const long MIN = -10000000;		// dolna granica zakresu
	const long MAX = +10000000;		// gorna granica zakresu
	long start, stop;				// poczatek i koniec przedzialu
	double wynik;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program oblicza sume kwadratow liczb calkowitych.");
	puts("Dolna granica przedzialu nie powinna byc mniejsza od -10000000.");
	puts("Dolna granica nie powinna przekraczac +10000000.");
	
/*  Code ----------------------------------------------------------------------*/
	// pobieranie wartosci
	puts("Podaj granice przedzialu (podanie 0 dla obu oznacza koniec).");
	printf("Dolna granica: ");
	start = pobierz_long();
	printf("Gorna granica: ");
	stop = pobierz_long();

	// przetwarzanie wartosci
	while (start != 0 || stop != 0)
	{
		if (zle_granice(start, stop, MIN, MAX))			// sprawdzenie poprawnosci wartosci wejsciowych
			puts("Sprobuj ponownie.");
		else
		{
			wynik = suma_kwadr(start, stop);			// dokonanie obliczen
			printf("Suma kwadratow liczb calkowitych w przedziale od %ld do %ld wynosi %g\n", start, stop, wynik);
		}
		
		puts("\nPodaj granice przedzialu (podanie 0 dla obu oznacza koniec).");
		printf("Dolna granica: ");
		start = pobierz_long();
		printf("Gorna granica: ");
		stop = pobierz_long();
	}

/*  Ending --------------------------------------------------------------------*/
	puts("Koniec");
	return 0;
}

long pobierz_long(void)
{
	long we;
	char ch;

	while(scanf("%ld", &we) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);				// pomija bledne dane wejsciowe
		printf(" nie jest liczba calkowita. \nProsze podac wartosc calkowita, np. 25, -178 czy 3: ");
	}
	return we;
}

double suma_kwadr (long a, long b)
{
	double suma = 0;
	int i;

	for (i = a; i <= b; i++)
		suma += i * i;
	return suma;
}

bool zle_granice(long poczatek, long koniec, long dolna, long gorna)
{
	bool zle = false;
	if (poczatek > koniec)
	{
		printf("%ld nie jest mniejsze od %ld.\n", poczatek, koniec);
		zle = true;
	}
	if (poczatek < dolna || koniec < dolna)
	{
		printf("Wartosci musza miec wartosc co najmniej: %ld.\n", dolna);
		zle = true;
	}
	if (poczatek > gorna || koniec > gorna)
	{
		printf("Wartosci musza miec wartosc co najmniej: %ld.\n", gorna);
		zle = true;
	}
	return zle;
}