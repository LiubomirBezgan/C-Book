// C Primer Plus Chapter 2 Exercise 7
// Version 1.0
#include <stdio.h>
void smile(void);	//prototyp funkcji wg ANSI/ISO C

int main(void) 			// wyświetlanie tekstu za pomocą własnych fynkcji
{
	int i; // odpowiada za wiersze
	int j; // odpowiada za powtórzenia
	i=3;
	j=3;

	while (i>0)
	{
		j=i;
		while (j>0)
		{
			smile();	//instrukcja wywołania
			j=j-1;
		}
		printf("\n");
		i = i - 1;
	}
	return 0;
}

void smile(void)	//definicja funkcji
{
	printf("Usmiech!");
}
