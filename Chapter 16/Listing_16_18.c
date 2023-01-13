// wykorzystuje assert()
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
	double x, y, z;
	puts("Podaj pare liczb (0 0 konczy program): ");
	while( (2 == scanf("%lf%lf", &x, &y)) && (x != 0 || y != 0) )
	{
		z = x * x - y * y;
		assert(z >= 0);
		printf("wynik wynosi %f\n", sqrt(z));
		puts("Kolejna para liczb: ");		
	}
	puts("Gotowe.");
	return 0;
}