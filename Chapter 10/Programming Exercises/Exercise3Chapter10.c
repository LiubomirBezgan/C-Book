#include <stdio.h>
#include <float.h>
float najwieksza(int rozmiar, float tab[rozmiar]);
void scanArray_flt(int length, float array[length]);

int main(void)
{
	int rozmiar;
	puts("Program pobiera wartosci i wyswietla najwieksza.\n");
	puts("Ile liczb planujesz wprowadzic?");
	scanf("%d", &rozmiar);
	float tab[rozmiar];
	scanArray_flt(rozmiar, tab);
	printf("Nawieksza wartosc to %f", najwieksza(rozmiar, tab));
}

float najwieksza(int rozmiar, float tab[rozmiar])
{
	int i;
	float max = (-1 * FLT_MAX);				// najmniejsza ujemna liczba zmiennoprzecinkowa
	for (i = 0; i < rozmiar; i++)
	{
		if (tab[i] > max)
		{
			max = tab[i];
		}
	}
	return max;
}

void scanArray_flt(int length, float array[length])
{
	int i;
	puts("Podaj wartosci:");
	for (i = 0; i < length; i++)
	{
		scanf(" %f", &array[i]);									// notacja tablicowa
	}
}