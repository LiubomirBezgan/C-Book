//  literaly zlozone - Listing_14_11.c
//  v1.0
#include <stdio.h>
#define MAXTYT 41
#define MAXAUT 31

struct ksiazka {					// szablon struktury o nazwie "ksiazka"
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;					// koniec szablonu struktury
};

int main(void)
{
	struct ksiazka polecana;
	int wynik;

	printf("Wprowadz wynik testu: ");
	scanf("%d", &wynik);

	if (wynik >= 84)
	{
		polecana = (struct ksiazka) {"Zbrodnia i kara", "Fiodor Dostojewski", 9.99};
	}
	else
	{
		polecana = (struct ksiazka) {"Kubus Puchatek", "A.A.Milne", 5.99};
	}
	printf("Wlasciwa dla Ciebie lektura to:\n");
	printf("%s autorstwa %s: $%.2f\n", polecana.tytul, polecana.autor, polecana.wartosc);

	return 0;
}
