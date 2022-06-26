// wyświetla rozmiary typów
// v1.1
#include <stdio.h>
int main(void)
{
	// w C99 zdefionowano format %zd dla rozmiarów
	printf("Typ char \tma rozmiar %zd bajt.\n", sizeof(char));
	printf("Typ short \tma rozmiar %zd bajty.\n", sizeof(short));
	printf("Typ int \tma rozmiar %zd bajty.\n", sizeof(int));
	printf("Typ unsigned \tma rozmiar %zd bajty.\n", sizeof(unsigned));
	printf("Typ long \tma rozmiar %zd bajty.\n", sizeof(long));
	printf("Typ long long \tma rozmiar %zd bajtow.\n", sizeof(long long));
	printf("Typ double \tma rozmiar %zd bajtow.\n \n", sizeof(double));
	getchar();
	return 0;
}