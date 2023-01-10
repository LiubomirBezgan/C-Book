// MOJTYP
#include <stdio.h>

#define MOJTYP(X) _Generic((X),\
	int: "int",\
	float: "float",\
	double: "double",\
	default: "inny"\
)

int main(void)
{
	int d = 5;

	printf("%s\n", MOJTYP(d));
	printf("%s\n", MOJTYP(2.0*d));
	printf("%s\n", MOJTYP(3L));		// 3L jest typu long
	printf("%s\n", MOJTYP(&d));		// &d jest typu int *
	return 0;
}