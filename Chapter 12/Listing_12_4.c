//  uzycie zmiennych globalnych - Listing_12_4.c
//  v1.0
#include <stdio.h>
int jednostki = 0;					// zmienna zewnetrzna
void krytyka(void);

int main(void)
{
	extern int jednostki;	// powtorna (opcjonalna) deklaracja
	puts("Ile funtow masla miesci sie w barylce?");
	scanf("%d", &jednostki);
	while (jednostki != 56)
	{
		krytyka();
	}
	puts("Musiales podejrzec!");
	return 0;
}

void krytyka(void)
{
	// pominieto powtorna (opcjonalna) deklaracje
	puts("Nie masz szczescia, sprobuj ponownie.");
	scanf("%d", &jednostki);
}