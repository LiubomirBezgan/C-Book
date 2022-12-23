// Question5Chapter14.c
// v1.0
#include "Question5Chapter14.h"

int main(void)
{
	unsigned int suma = 0;
	int numer_podany;
	int i;					// licznik
	puts("Podaj numer miesiaca:");
	while (1 != scanf("%d", &numer_podany) || numer_podany > MIESIACE || numer_podany <= 0) 
	{
		while ('\n' != getchar())
		{
			continue;
		}
		puts("Podaj liczbe od 1 do 12:");
	}
	for (i = 0; i < numer_podany; i++)
	{
		suma += rok[i].dni;
	}
	printf("Od poczatku roku do konca %s uplynelo %d dni\n", rok[numer_podany - 1].nazwa, suma);
	return 0;
}