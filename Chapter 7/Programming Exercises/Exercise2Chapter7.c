// wyswietla kody ASCII wpisanych znakow - Exercise2Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	signed char ch;
	int licznik = 0;				// licznik znakow

	puts("Wpisz jakis tekst; '#' konczy program.");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			{
				printf("\'\\n\' - %3d\n\n", ch);
				licznik = 0;
			}
		else
			{
				printf("\'%c\' - %3d, ", ch, ch);
				if (++licznik % 8 == 0)
				printf("\n");
			}
	}
	return 0;
}