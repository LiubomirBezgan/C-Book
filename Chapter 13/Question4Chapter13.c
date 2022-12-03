// Question4Chapter13.c
// v1.0
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	FILE * wp;
	unsigned int licznik = 0;
	double liczba;
	double suma = 0.0;

	if (argc > 2)
	{
		fprintf(stderr, "Sposob uzycia: %s nazwa_pliku\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		if (NULL == (wp = fopen(argv[1], "r")))
		{
			fprintf(stderr, "Blad otwarcia pliku %s do odczytu\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		puts("Podawaj liczby zmiennoprzecinkowe (aby zakonczyc, wpisz q):");
		wp = stdin;
	}
	while (1 == fscanf(wp, "%lf", &liczba))
	{
		suma += liczba;
		licznik++;
	}	
	fprintf(stdout, "Srednia arytmetyczna wynosi %lf.\n", suma / licznik);
	fclose(wp);
	return 0;
}
