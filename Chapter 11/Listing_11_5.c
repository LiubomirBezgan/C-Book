//  wskazniki i lancuchy  - Listing_11_5.c
//  v1.0
#include <stdio.h>

int main(void)
{
	char * tekst = "Nie badz glupi!";
	char * kopia;

	kopia = tekst;
	printf("%s\n", kopia);
	printf("tekst = %s; &tekst = %p, wartosc = %p\n", tekst, &tekst, tekst);
	printf("kopia = %s; &kopia = %p, kopia = %p\n", kopia, &kopia, kopia);
	return 0;
}