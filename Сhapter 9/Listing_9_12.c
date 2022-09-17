//  sprawdza, gdzie przechowywane sa zmienne - Listing_9_12.c
#include <stdio.h>
void mikado(int);				// deklaracja funkcji
int main(void)
{
	int ach = 2, och = 5;		// lokalne wzgledem main()
	printf("W funkcji main() ach = %d, a &ach = %p\n", ach, &ach);
	printf("W funkcji main() och = %d, a &och = %p\n", och, &och);
	mikado(ach);
	return 0;
}
void mikado(int och)			// defnicja funkcji
{
	int ach = 10;				// lokalna wzgledem mikado
	printf("W funkcji mikado() ach = %d, a &ach = %p\n", ach, &ach);
	printf("W funkcji mikado() och = %d, a &och = %p\n", och, &och);	
}