// min -> h+min - Exercise1Chapter5.c
// v1.0
#include <stdio.h>
#define MIN 60		// 60 minut w 1 godzinie 

int main(void)
{
	int czas;

	puts("Prosze podac czas w minutach do przeliczenia na godziny i minuty.");
	puts("W celu zakonczenia programu wpisz \"0\" lub wartosc ujemna.");
	printf("Liczba minut: ");
	scanf("%d", &czas);

	while (czas > 0)
	{
		printf("%d min to %d godzin %d minut.\n\n", czas, czas / MIN, czas % MIN);
		puts("Prosze podac liczbe minut do kolejnego przeliczenia:");
		puts("W celu zakonczenia programu wpisz \"0\" lub wartosc ujemna.");
		scanf("%d", &czas);
	}

	puts("\nDo zobaczenia!");

	getchar();
	getchar();
	return 0;
}