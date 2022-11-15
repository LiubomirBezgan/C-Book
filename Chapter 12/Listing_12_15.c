//  gdzie jest pamiec? - Listing_12_15.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int obszar_statyczny = 30;
const char * lcz = "Literal ciagu znakow";

int main(void)
{
	int obszar_automatyczny = 40;
	char ciag_automatyczny[] = "Automatyczny przydzial tablicy znakow";
	int * wski;
	char * wskl;

	wski = (int *) malloc(sizeof(int));
	*wski = 35;
	wskl = (char *) malloc(strlen("Ciag przydzielany dynamiczne") + 1);
	strcpy(wskl, "Ciag przydzielany dynamicznie");

	printf(" obszar_statyczny: %d pod adresem %p\n", obszar_statyczny, &obszar_statyczny);
	printf(" obszar_automatyczny: %d pod adresem %p\n", obszar_automatyczny, &obszar_automatyczny);	
	printf(" *wski: %d pod adresem %p\n", *wski, wski);
	printf(" %s pod adresem %p\n", lcz, lcz);
	printf(" %s pod adresem %p\n", ciag_automatyczny, ciag_automatyczny);
	printf(" %s pod adresem %p\n", wskl, wskl);
	printf(" %s pod adresem %p\n", "Literal w kodzie", "Literal w kodzie");
	free(wski);
	free(wskl);
	return 0;
}