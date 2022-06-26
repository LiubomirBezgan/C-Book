// wyświetla rozmiary typów
// v1.0
#include <stdio.h>
#include <limits.h>	// granice liczb calkowitych
#include <float.h>	// granice liczb zmiennoprzecinkowych
int main(void)
{
	// w C99 zdefionowano format %zd dla rozmiarów
	printf("Typ char \tma rozmiar %zd bajt.\n", sizeof(char));
	printf("Typ short \tma rozmiar %zd bajtow.\n", sizeof(short));
	printf("Typ int \tma rozmiar %zd bajtow.\n", sizeof(int));
	printf("Typ unsigned \tma rozmiar %zd bajtow.\n", sizeof(unsigned));
	printf("Typ long \tma rozmiar %zd bajtow.\n", sizeof(long));
	printf("Typ long long \tma rozmiar %zd bajtow.\n", sizeof(long long));
	printf("Typ double \tma rozmiar %zd bajtow.\n \n", sizeof(double));

	// maksymalne wartości różnych typów
	printf("Maksymalna wartosc typu char\t\twynosi %d.\n", CHAR_MAX);
	printf("Maksymalna wartosc typu short\t\twynosi %d.\n", SHRT_MAX);
	printf("Maksymalna wartosc typu int\t\twynosi %d.\n", INT_MAX);
	printf("Maksymalna wartosc typu unsigned\twynosi %u.\n", UINT_MAX);
	printf("Maksymalna wartosc typu long\t\twynosi %ld.\n", LONG_MAX);
	printf("Maksymalna wartosc typu long long\twynosi %lld.\n", LLONG_MAX);
	printf("Maksymalna wartosc typu double\t\twynosi %e.\n", DBL_MAX);
	getchar();
	return 0;
}