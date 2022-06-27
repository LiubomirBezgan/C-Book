// wyświetla rozmiary typów
// v2.0
#include <stdio.h>
#include <limits.h>	// granice liczb calkowitych
#include <float.h>	// granice liczb zmiennoprzecinkowych
int main(void)
{
	// definicja zmiennych
	char char_var;
	short short_var;
	int int_var;
	unsigned unsigned_var;
	long long_var;
	long long long_long_var;
	double double_var;

	unsigned char_var1;
	unsigned short_var1;
	unsigned int_var1;
	long long long_var1;
	  
	// w C99 zdefionowano format %zd dla rozmiarów
	printf("Typ char \tma rozmiar %zd bajt.\n", sizeof(char));
	printf("Typ short \tma rozmiar %zd bajtow.\n", sizeof(short));
	printf("Typ int \tma rozmiar %zd bajtow.\n", sizeof(int));
	printf("Typ unsigned \tma rozmiar %zd bajtow.\n", sizeof(unsigned));
	printf("Typ long \tma rozmiar %zd bajtow.\n", sizeof(long));
	printf("Typ long long \tma rozmiar %zd bajtow.\n", sizeof(long long));
	printf("Typ double \tma rozmiar %zd bajtow.\n\n", sizeof(double));

	// maksymalne wartości różnych typów
	printf("Maksymalna wartosc typu char\t\twynosi %d.\n", CHAR_MAX);
	printf("Maksymalna wartosc typu short\t\twynosi %hd.\n", SHRT_MAX);
	printf("Maksymalna wartosc typu int\t\twynosi %d.\n", INT_MAX);
	printf("Maksymalna wartosc typu unsigned\twynosi %u.\n", UINT_MAX);
	printf("Maksymalna wartosc typu long\t\twynosi %ld.\n", LONG_MAX);
	printf("Maksymalna wartosc typu long long\twynosi %lld.\n", LLONG_MAX);
	printf("Maksymalna wartosc typu double\t\twynosi %e.\n\n", DBL_MAX);
	
	// nadanie zmiennym maksymalnej wartości
	char_var = CHAR_MAX;
	short_var = SHRT_MAX;
	int_var = INT_MAX;
	unsigned_var = UINT_MAX;
	long_var = LONG_MAX;
	long_long_var = LLONG_MAX;
	double_var = DBL_MAX;
	printf("Nadanie zmiennym maksymalnej wartosci\nStan programu: \nc \t%#c (%d), \ns \t%hd, \ni \t%d, \nu \t%u, \nlng \t%ld, \nlnglng \t%lld, \ndbl \t%e\n\n",
		char_var, char_var, short_var, int_var, unsigned_var, long_var, long_long_var, double_var);

	// próba przekroczenia limitu
	char_var = char_var + 1;
	short_var = short_var + 1;
	int_var = int_var + 1;
	unsigned_var = unsigned_var + 1;
	long_var = long_var + 1;
	long_long_var = long_long_var + 1;
	double_var = double_var + 0.000001e+308;
	printf("Proba przekroczenia limitu\nStan programu: \nc \t%#c (%d), \ns \t%hd, \ni \t%d, \nu \t%u, \nlng \t%ld, \nlnglng \t%lld, \ndbl \t%e\n\n",
		char_var, char_var, short_var, int_var, unsigned_var, long_var, long_long_var, double_var);

	char_var1 = 128;
	short_var1 = 32768;
	int_var1 = 2147483648;
	long_var1 = 2147483648;

	// przepełnienie
	puts("Proba przepelnienia");
	printf("char_var1 \t= %u, \t\tlecz nie %c\nshort_var1 \t= %u, \t\tlecz nie %hd\nint_var1 \t= %u, \t\tlecz nie %d\nlong_var1 \t= %lld, \tlecz nie %ld\n",
		char_var1, char_var1, short_var1, short_var1, int_var1, int_var1, long_var1,long_var1);

	getchar();
	return 0;
}