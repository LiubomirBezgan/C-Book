// wiek w sekundach - Exercise5Chapter3.c
// v1.1
#include <stdio.h>

int main(void)
{
	float s = 0.0f;
	printf("Prosze podac swoj wiek w latach: _____\b\b\b\b\b");
	scanf("%f", &s);
	printf("\nWow! Czyli zyjesz juz %e sekund!", s*3.156e+7);
	getchar();
	getchar();
	return 0;
}