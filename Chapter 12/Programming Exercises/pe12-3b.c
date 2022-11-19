// pe12-3b.c
// kompilowac z pe12-3a.c
#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
	int tryb_aktualny;
	int tryb_poprzedni = 0;
	float dystans;
	float zuzyte_paliwo; 
	printf("Wybierz: 0 - system metryczny, 1 - system US: ");
	scanf("%d", &tryb_aktualny);
	while ( tryb_aktualny >= 0 )
	{
		tryb_aktualny = wybierz_tryb(tryb_aktualny, tryb_poprzedni);
		pobierz_dane(tryb_aktualny, &dystans, &zuzyte_paliwo);
		wyswietl_dane(tryb_aktualny, &dystans, &zuzyte_paliwo);
		tryb_poprzedni = tryb_aktualny;
		printf("Wybierz: 0 - system metryczny, 1 - system US");
		printf(" (-1 aby zakonczyc): ");
		scanf("%d", &tryb_aktualny);			
	}
	printf("Koniec.\n");
	return 0;
}