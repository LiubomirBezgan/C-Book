// wyswietlenie podanej liczby zmiennoprzecinkowej w rozny sposob - Exercise4Chapter3.c
// v1.0
#include <stdio.h>

int main(void)
{
	float FL;
	printf("Prosze podac liczbe w notacji dziesietnej: ____________\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%f", &FL);
	printf("\nPodana liczba to %f lub %e lub %a", FL, FL, FL);
	getchar();
	getchar();
	return 0;
}