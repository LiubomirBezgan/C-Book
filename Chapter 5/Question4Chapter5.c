// Question4Chapter5.c
// v1.0
#include <stdio.h>

int main (void)
{
	int i = 1;
	float n;
	
	printf("Uwaga! Nadchodza ulamki!\n");
	
	while (i++ < 30)
	{
		n = 1 / (float) i;
		printf("%f\n", n);
	}

	printf("To by bylo na tyle.\n");
	getchar();
	return 0;
}
