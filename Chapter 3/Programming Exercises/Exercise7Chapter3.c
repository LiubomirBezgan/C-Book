// konwersja in <-> cm - Exercise7Chapter3.c
// v1.0
#include <stdio.h>

int main(void)
{
	float inch_to_cm = 2.54;
	float inch, cm, inch1, cm1;

	printf("Prosze podac swoj wzrost w cm: ______\b\b\b\b\b\b");
	scanf("%f", &cm);
	inch = cm / inch_to_cm;
	printf("W calach twoj wzrost wynosi %.2f\n", inch);
	
	printf("\nA teraz podaj swoj wzrost w calach: ______\b\b\b\b\b\b");
	scanf("%f", &inch1);
	cm1 = inch1 * inch_to_cm;
	printf("W centymetrach twoj wzrost wynosi %.2f\n", cm1);

	getchar();
	getchar();
	return 0;
}