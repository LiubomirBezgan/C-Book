// sumuje liczby calkowite wpisane przez uzytkownika - Listing_6_1.c
// v2.0
#include <stdio.h>

int main(void)
{
	long num;
	long suma = 0L;
	_Bool wej_jest_ok;	//uzycie typu _Bool

	printf("Podaj liczbe calkowita do zsumowania ");
	printf("(albo q, aby zakonczyc program):\n");
	wej_jest_ok = scanf("%ld", &num);

	while (wej_jest_ok)
	{
		suma = suma + num;
		printf("Podaj nastepna liczbe ");
		printf("(albo q, aby zakonczyc program):\n");
		wej_jest_ok = scanf("%ld", &num);
	} 

	printf("Suma podanych liczb wynosi %ld.\n", suma);

	getchar();
	getchar();
	getchar();
	return 0;
}