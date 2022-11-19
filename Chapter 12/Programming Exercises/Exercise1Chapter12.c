//  NIEuzycie zmiennych globalnych - Exercise1Chapter12.c
//  v1.0
#include <stdio.h>
void krytyka(int * odpowiedz);

int main(void)
{
	int jednostki;	// powtorna (opcjonalna) deklaracja
	puts("Ile funtow masla miesci sie w barylce?");
	scanf("%d", &jednostki);
	while (jednostki != 56)
	{
		krytyka(&jednostki);
	}
	puts("Musiales podejrzec!");
	return 0;
}

void krytyka(int * odpowiedz)
{
	puts("Nie masz szczescia, sprobuj ponownie.");
	scanf("%d", odpowiedz);
}