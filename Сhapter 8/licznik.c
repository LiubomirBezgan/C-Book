// licznik.c - program podaje liczbe znakow, slow i wierszy w pliku
// v1.0
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int c;							// biezacy znak
	char poprz; 					// poprzedni znak
	long ile_znakow = 0L;			// liczba znakow
	int ile_wierszy = 0;			// liczba linii
	int ile_slow = 0;				// liczba slow
	int ile_np_wierszy = 0;			// liczba niepelnych wierszy
	bool w_slowie = false;			// == true, jesli c znajduje sie w slowie

	puts("Program podaje liczbe znakow, slow i wierszy w pliku:");
	poprz = '\n';					// uzyty do rozpoznania konca linii

	while ((c = getchar()) != EOF)
	{
		ile_znakow++;				// liczy znaki
		if (c == '\n')
			ile_wierszy++;			// liczy wiersze
		if (!isspace(c) && !w_slowie)
		{
			w_slowie = true;		// zaczelo sie nowe slowo
			ile_slow++;				// liczy slowa
		}
		if (isspace(c) && w_slowie)
			w_slowie = false;		//znajduje koniec slowa
		poprz = c;
	}

	if (poprz != '\n')
		ile_np_wierszy = 1;
	printf("znakow = %ld, slow = %d, wierszy = %d, niepelnych wierszy = %d\n", ile_znakow, ile_slow, ile_wierszy, ile_np_wierszy);
	return 0;
}