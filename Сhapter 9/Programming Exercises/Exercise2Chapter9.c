//  opis - Exercise2Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void rzad_zn(char ch, int i, int j);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	int i, j;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje rzad_zn(ch, i, j).\n");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj znak: ");
	scanf("%c", &ch);
	printf("Podaj numer poczatkowej kolumny: ");
	scanf("%d", &i);
	printf("Podaj numer koncowej kolumny: ");
	scanf("%d", &j);
	while (j < i)
	{
		puts("Numer koncowej kolumny nie moze byc mniejszy od numeru poczatkowej kolumny.");
		printf("\nPodaj numer koncowej kolumny: ");
		scanf("%d", &j);
	}
	printf("%c %d %d\n", ch, i, j);
	rzad_zn(ch, i, j);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void rzad_zn(char ch, int i, int j)
{
	int licznik;
	for (licznik = 0; licznik < j + i - 1; licznik++)
		printf("|   ");
	putchar('\n');
	for (licznik = 0; licznik < i-1; licznik++)
		printf("|   ");
	for (licznik = i; licznik <= j; licznik++)
		printf("%c   ", ch);
	for (licznik = j; licznik < j+i - 1; licznik++)
		printf("|   ");
	putchar('\n');
	for (licznik = 0; licznik < j + i - 1; licznik++)
		printf("|   ");
}