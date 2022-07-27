// wspak liniowy - Exercise15Chapter6.c
// v1.0
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = -1;
	char linia[255];

	puts("Program pobiera linie znakow i wyswietla ja w odrtotnej kolejnosci.");
	puts("Prosze podac linie znakow (nie dluzsza niz 255 symboli):");

	do {
		i++;
		scanf("%c", &linia[i]);
	} while ('\n' != linia[i]);
	
	printf("\nOto wynik:\n");
	
	for (i = strlen(linia) - 2; i >= 0; i--)
		printf("%c", linia[i]);

	getchar();
	return 0;
}
