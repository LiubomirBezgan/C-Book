//  Atrapa - Question9Chapter9.c
//  v1.0
#include <stdio.h>
#define GRANICA_DOL 1
#define GRANICA_GORA 4
void menu(void);
int wybor(int granica_dolna, int granica_gorna);

int main()
{
	int opcja;

	puts("Sluzy do testowania funkcji menu() i wybor().");
	menu();
	opcja = wybor(GRANICA_DOL, GRANICA_GORA);
	printf("%d\n", opcja);
	switch (opcja)
	{
		case 1 :
		{
			puts("Ktory plik chcesz skopiowac?");
			break;
		}
		case 2 :
		{
			puts("Ktory plik chcesz przeniesc?");
			break;
		}
		case 3 :
		{
			puts("Ktory plik chcesz usunac?");
			break;
		}
		default :
		{
			puts("Milego dnia!");
		}
	}
	return 0;
}

void menu(void)
{
	puts("Wybierz jedna z ponizszych mozliwosci:");
	puts("1) kopiowanie plikow     2) przenoszenie plikow");
	puts("3) usuwanie plikow       4) koniec");
	printf("Podaj numer wybranej opcji: ");
}

int wybor(int granica_dolna, int granica_gorna)
{
	int input;
	int flaga;							// 1 - liczba calkowita; 0 - wartosc nieliczbowa
	flaga = scanf("%d", &input);
	while ('\n' != getchar())			// czyszczenie bufora
		continue;
	while ((1 == flaga) && (input < granica_dolna || input > granica_gorna))
	{
		puts("Zly numer. Prosze podac liczbe calkowita od 1 do 4.");
		menu();
		flaga = scanf("%d", &input);
		while ('\n' != getchar())		// czyszczenie bufora
			continue;
	}
	if (0 == flaga)
	{
		return granica_gorna;
	}
	return input;
}