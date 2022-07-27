// oprocentowanie - Exercise16Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	const float start_e = 100.0;				// 100 zł na poczatku u Ewy
	const float start_k = 100.0;				// 100 zł na poczatku u Kasi
	const float percent_e = 0.1;				// 10% - oprocentowanie Ewy,
	const float percent_k = 0.05;				// 5% - oprocentowanie Kasi
	float inwest_e, inwest_k;					// wartosc inwestycji
	int lata = 0;

	inwest_e = start_e;
	inwest_k = start_k;
	
	do {
		inwest_e += start_e * percent_e;		// 10% procent prosty
		inwest_k += inwest_k * percent_k;		//  5% procent składany
		lata++;
	} while (inwest_e > inwest_k);

	printf("Wartosc inwestycji Kasi przekroczyla wartosc inwestycji Ewy po %d latach\n", lata);
	printf("Wartosc inwestycji Ewy  wynosi %.2f\n", inwest_e);
	printf("Wartosc inwestycji Kasi wynosi %.2f\n", inwest_k);

	getchar();
	return 0;
}