// licznik wielkich i malych liter oraz innych znaków - Question7Chapter7.c
// v1.0
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int ml = 0;
	int wl = 0;
	int iz = 0;
	puts("Wpisz jakis tekst; '#' konczy program.");
	while ((ch = getchar()) != '#')
	{
		if (islower(ch))
			ml++;
		else if (isupper(ch))
			wl++;
		else
			iz++;
	}
	printf("%d malych liter, %d wielkich liter, %d innych znakow.\n", ml, wl, iz);
	return 0;
}