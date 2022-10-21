#include <stdio.h>
#include <float.h>
//float * adres_najwiekszej(int rozmiar, float tab[rozmiar]);			// zwraca adres na
void scanArray_flt(int length, float array[length]);
int indeks_najwiekszej(int rozmiar, float tab[rozmiar]);

int main(void)
{
	int rozmiar;
	puts("Program pobiera wartosci i wyswietla indeks najwiekszej wartosci.\n");
	puts("Ile liczb planujesz wprowadzic?");
	scanf("%d", &rozmiar);
	float tab[rozmiar];
	scanArray_flt(rozmiar, tab);
	printf("Indeks nawiekszej wartosci to %d\n", indeks_najwiekszej(rozmiar, tab));
	/*printf("Rozmiar float na tym systemie wynosi %zu\n", sizeof (float));
	printf("Adres pierwszego elemetu tablicy to %p\n", tab);
	printf("Nawieksza liczba jest przechowywana pod adresem %p\n", adres_najwiekszej(rozmiar, tab));*/
}

/*float * adres_najwiekszej(int rozmiar, float tab[rozmiar])
{
	int i;
	float max = FLT_MIN;
	float *wsk;
	for (i = 0; i < rozmiar; i++)
	{
		if (tab[i] > max)
		{
			max = tab[i];
		  wsk = &tab[i];
		}
	}
	return wsk;
}*/

void scanArray_flt(int length, float array[length])
{
	int i;
	puts("Podaj wartosci:");
	for (i = 0; i < length; i++)
	{
		scanf(" %f", &array[i]);									// notacja tablicowa
	}
}

int indeks_najwiekszej(int rozmiar, float tab[rozmiar])
{
	int i;
	int wynik;
	float max = (-1 * FLT_MIN);
	for (i = 0; i < rozmiar; i++)
	{
		if (tab[i] > max)
		{
		max = tab[i];
		wynik = i;
		}
	}
	return wynik;
}