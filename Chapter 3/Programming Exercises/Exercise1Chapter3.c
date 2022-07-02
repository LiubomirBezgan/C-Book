// Wyświetla rozmiary typów oraz wyniki dokonan przepełnienia i niedomiaru, wykorzystujac narzedzia do formatowania
// v4.0
#include <stdio.h>
#include <limits.h>	// granice liczb calkowitych
#include <float.h>	// granice liczb zmiennoprzecinkowych
#define C "char"
#define S "short"
#define I "int"
#define U "unsigned"
#define L "long"
#define LL "long long"

int main(void)
{
	// definicja stałych
	const char *FLT = "float";
	const char *DBL = "double";

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
	float float_var1;
	double double_var1;
	
	// w C99 zdefionowano format %zd dla rozmiarów
	printf("Typ %9s ma rozmiar %zd bajt\n", C, sizeof(char));
	printf("Typ %9s ma rozmiar %zd bajtow\n", S, sizeof(short));
	printf("Typ %9s ma rozmiar %zd bajtow\n", I, sizeof(int));
	printf("Typ %9s ma rozmiar %zd bajtow\n", U, sizeof(unsigned));
	printf("Typ %9s ma rozmiar %zd bajtow\n", L, sizeof(long));
	printf("Typ %9s ma rozmiar %zd bajtow\n", LL, sizeof(long long));
	printf("Typ %9s ma rozmiar %zd bajtow\n", FLT, sizeof(float));
	printf("Typ %9s ma rozmiar %zd bajtow\n", DBL, sizeof(double));
	puts("");

	// maksymalne wartości różnych typów
	printf("Maksymalna wartosc typu %9s wynosi %d\n", C, CHAR_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %hd\n", S, SHRT_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %d\n", I, INT_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %u\n", U,  UINT_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %ld\n", L, LONG_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %lld\n", LL, LLONG_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %e\n", FLT, FLT_MAX);
	printf("Maksymalna wartosc typu %9s wynosi %e\n", DBL, DBL_MAX);
	puts("");

	// nadanie zmiennym maksymalnej wartości
	char_var = CHAR_MAX;
	short_var = SHRT_MAX;
	int_var = INT_MAX;
	unsigned_var = UINT_MAX;
	long_var = LONG_MAX;
	long_long_var = LLONG_MAX;
	double_var = DBL_MAX;
	printf("Nadanie zmiennym maksymalnej wartosci\nStan programu: \nc \t%#4c (%4d), \ns \t%11hd, \ni \t%11d, \nu \t%11u, \nlng \t%11ld, \nlnglng \t%20lld, \ndbl \
\t%14e.\n\n", char_var, char_var, short_var, int_var, unsigned_var, long_var, long_long_var, double_var);

	// próba przekroczenia limitu
	char_var = char_var + 1;
	short_var = short_var + 1;
	int_var = int_var + 1;
	unsigned_var = unsigned_var + 1;
	long_var = long_var + 1;
	long_long_var = long_long_var + 1;
	double_var = double_var + 0.000001e+308;
	printf("Proba przekroczenia limitu\nStan programu: \nc \t%#4c (%4d), \ns \t%11hd, \ni \t%11d, \nu \t%11u, \nlng \t%11ld, \nlnglng"
			"\t%20lld, \ndbl \t%4e.\n\n",char_var, char_var, short_var, int_var, unsigned_var, long_var, long_long_var, double_var);

	char_var1 = 1322;
	short_var1 = 33768;
	int_var1 = 2247483648;
	long_var1 = 222147483648;

	// przepełnienie
	puts("Proba przepelnienia");
	printf("char_var1 \t= %12u, lecz nie %#c\nshort_var1 \t= %12u, lecz nie %hd\nint_var1 \t= %12u, lecz nie %d\nlong_var1 \t= %12lld, lecz nie %ld\n\n",
		char_var1, char_var1, short_var1, short_var1, int_var1, int_var1, long_var1,long_var1);

	//niedomiar zmiennej zmiennoprzecinkowej
	puts("BADANIE NIEDOMIARU ZMIENNYCH ZMIENNOPRZECINKOWYCH:");
	printf("FLT_MANT_DIG \t= %3d\n", FLT_MANT_DIG);
	printf("FLT_DIG \t= %3d\n", FLT_DIG);
	printf("FLT_MIN_10_EXP \t= %3d\n", FLT_MIN_10_EXP);
	printf("FLT_MAX_10_EXP \t= %3d\n", FLT_MAX_10_EXP);
	printf("FLT_MIN \t= %e\n", FLT_MIN);
	printf("FLT_MAX \t= %e\n", FLT_MAX);
	printf("FLT_EPSILON \t= %e\n\n", FLT_EPSILON);

	float_var1 =  1.175494e-038;


	int i = 0; // licznik
	while (i!=25)
	{
		printf("float_var1 = %e, a rozmiar %zd bajtow\n", float_var1, sizeof(float_var1));
		float_var1 = float_var1 / 2;
		i=i+1;
	}
	

	puts("\nA teraz DOUBLE:");
	printf("DBL_MANT_DIG \t= %4d\n", DBL_MANT_DIG);
	printf("DBL_DIG \t= %4d\n", DBL_DIG);
	printf("DBL_MIN_10_EXP \t= %4d\n", DBL_MIN_10_EXP);
	printf("DBL_MAX_10_EXP \t= %4d\n", DBL_MAX_10_EXP);
	printf("DBL_MIN \t= %e\n", DBL_MIN);
	printf("DBL_MAX \t= %e\n", DBL_MAX);
	printf("DBL_EPSILON \t= %e\n\n", DBL_EPSILON);

	double_var1 =  2.225074e-308;


	int j = 0; // licznik
	while (j!=25)
	{
		printf("double_var1 = %e, a rozmiar %zd bajtow\n", double_var1, sizeof(double_var1));
		double_var1 = double_var1 / 5;
		j=j+1;
	}

	getchar();
	return 0;
}