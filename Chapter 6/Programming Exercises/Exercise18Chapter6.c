// Porfesor Popularny i serwis spolecznosciowy - Exercise18Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	int friends = 5;
	const float mnoznik = 2;
	int i = 0;	

	do {
		friends -= ++i;
		friends *= mnoznik;
		printf("%2d. tydzien - ", i);
		printf("%3d\n", friends);
	} while (friends < 150);
	
	printf("Liczba Dunbara zostala przekroczona po %d tygodniach", i);
	
	getchar();
	return 0;
}