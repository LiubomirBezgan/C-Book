// name - Exercise2Chapter4.c
// v1.0
#include <stdio.h>
#include <string.h>

int main(void)
{
	char imie[20];

	puts("Prosze podac swoje imie:");
	scanf("%s", imie);

	printf("\"%s\"\n",  imie); 					// a)
	printf("\"%20s\"\n",  imie); 				// b)
	printf("\"%-20s\"\n",  imie); 				// c)
	printf("\"%*s\"\n", 3+strlen(imie), imie);	// d)

	getchar();
	getchar();
	return 0;
}