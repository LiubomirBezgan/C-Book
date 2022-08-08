// licznik liczb parzystych i nieparzystych - Exercise3Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	int liczba;
	int licznik_p = 0;			// licznik liczb parzystych
	int licznik_np = 0;			// licznik liczb nieparzystych
	int suma_p = 0;				// suma liczb parzystych
	int suma_np = 0;			// suma liczb nieparzystych

	puts("Program wyswietla ilosci wpisanych liczb parzystych i nieparzystych oraz ich wartosci srednie.");
	puts("Podawaj liczby calkowite, rozdzielajac je znakiem bialym (np. \' \', \'\\t\', \'\\n\' itd.); '0' konczy zliczenie.");
	while (scanf("%d", &liczba) == 1)
	{
		if (liczba == 0)
			break;
		else if (liczba % 2 == 0)
			{
				licznik_p++;
				suma_p += liczba;
			}
			else
			{
				licznik_np++;
				suma_np += liczba;
			}
	}
	
	if (licznik_p == 1)
		printf("Wpisano %d liczbe parzysta; srednia wartosc wynosi %0.2f.\n", licznik_p, (float) suma_p / licznik_p);
	else if (licznik_p > 1 && licznik_p < 5)
		printf("Wpisano %d liczby parzyste; ich srednia wartosc wynosi %0.2f.\n", licznik_p, (float) suma_p / licznik_p);
	else
		printf("Wpisano %d liczb parzystych; ich srednia wartosc wynosi %0.2f.\n", licznik_p, (float) suma_p / licznik_p);

	if (licznik_np == 1)
		printf("Wpisano %d liczbe nieparzysta; srednia wartosc wynosi %0.2f.\n", licznik_np, (float) suma_np / licznik_np);
	else if (licznik_np > 1 && licznik_np < 5)
		printf("Wpisano %d liczby nieparzyste; ich srednia wartosc wynosi %0.2f.\n", licznik_np, (float) suma_np / licznik_np);
	else
		printf("Wpisano %d liczb nieparzystych; ich srednia wartosc wynosi %0.2f.\n", licznik_np, (float) suma_np / licznik_np);

	puts("Wpisz '#', aby zamknac program:");
	while (getchar() != '#')
		continue;

	return 0;
}