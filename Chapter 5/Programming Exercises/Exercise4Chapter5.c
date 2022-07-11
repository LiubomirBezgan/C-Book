// cm -> stop oraz cale  - Exercise4Chapter5.c
// v1.0
#include <stdio.h>
#define CM_INCH 0.3937		// 7 dni w 1 tygodniu
#define CM_FOOT 0.0328


int main(void)
{
	float cm; 			// liczba dni

	puts("Prosze podac wzrost w centymatrach.");
	puts("W celu zakonczenia programu wpisz \"0\" lub wartosc ujemna.");
	printf("Wzrost [cm]: ");
	scanf("%f", &cm);

	while (cm > 0)
	{
		printf("%.1f cm = %d stop, %.2f cali.\n\n", cm, (int) (cm * CM_FOOT), cm * CM_INCH);
		puts("Prosze podac wzrost w centymatrach do kolejnego przeliczenia:");
		puts("W celu zakonczenia programu wpisz \"0\" lub wartosc ujemna.");
		printf("Wzrost [cm]: ");
		scanf("%f", &cm);
	}

	puts("\nDo zobaczenia!");

	getchar();
	getchar();
	return 0;
}