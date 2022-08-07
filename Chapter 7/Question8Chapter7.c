// UWAGA! Program zawiera blad! - Question8Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	int wiek = 20;
	while (wiek++ <= 65)
	{
		if ((wiek % 20) == 0)
			printf("Masz %d lat. Dostajesz podwyzke.\n", wiek);
		if (wiek = 65)				// powinno byc: if (wiek == 65)
			printf("Masz %d lat. Dostajesz zloty zegarek.\n", wiek);
	}
	return 0;
}