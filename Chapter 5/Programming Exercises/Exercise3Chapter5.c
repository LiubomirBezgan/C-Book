// dni -> htygodnie + dni - Exercise3Chapter5.c
// v1.0
#include <stdio.h>
#define DNI 7		// 7 dni w 1 tygodniu 

int main(void)
{
	int n; 			// liczba dni

	puts("Prosze podac liczbe dni do przeliczenia na tygodnie i dni.");
	puts("W celu zakonczenia programu wpisz \"0\" lub \"-20\".");
	printf("Liczba dni: ");
	scanf("%d", &n);

	while ((n != 0) & (n != -20))
	{
		printf("%d dni to %d tygodnie, %d dni.\n\n", n, n / DNI, n % DNI);
		puts("Prosze podac liczbe dni do kolejnego przeliczenia.");
		puts("W celu zakonczenia programu wpisz \"0\" lub \"-20\".");
		printf("Liczba dni: ");
		scanf("%d", &n);
	}

	puts("\nDo zobaczenia!");

	getchar();
	getchar();
	return 0;
}