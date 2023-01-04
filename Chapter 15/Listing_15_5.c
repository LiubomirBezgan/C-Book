// stosowanie _Alignof i _Alignas (C11)
#include <stdio.h>

int main(void)
{
	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	char _Alignas(double) cz;

	printf("Wyrownanie char: %zd\n", _Alignof(char));
	printf("Wyrownanie double: %zd\n", _Alignof(double));
	printf("&dx: %p\n", &dx);
	printf("&ca: %p\n", &ca);
	printf("&cx: %p\n", &cx);
	printf("&dz: %p\n", &dz);
	printf("&cb: %p\n", &cb);
	printf("&cz: %p\n", &cz);

	return 0;
}