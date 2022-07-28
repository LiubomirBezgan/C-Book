// Jim Szczesciarz wygral milion dolarow - Exercise17Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	float konto = 1000000;
	const float percent = 0.08;
	int i=0;	

	do	{
		konto -= 100000;
		konto += konto * percent;
		printf("%2d. ROK - ", ++i);
		printf("%.2f\n", konto);
	} while (konto > 0);
	
	printf("Konto oproznilo sie po %d latach", i);
	getchar();
	return 0;
}