// C Primer Plus Chapter 2 Exercise 4
// Version 1.0
#include <stdio.h>
void panieJanie(void);	//prototyp funkcji wg ANSI/ISO C
void ranoWstan(void);	//prototyp funkcji wg ANSI/ISO C

int main(void) 			// wyświetlanie tekstu piosenki za pomocą własnych fynkcji oraz pętli while
{
	int i;
	i=2;

	while (i>0)
	{
		panieJanie();	//instrukcja wywołania
		i = i - 1;
	}

	ranoWstan();		//instrukcja wywołania
	return 0;
}

void panieJanie(void)	//definicja funkcji
{
	printf("Panie Janie!\n");
}

void ranoWstan(void)	//definicja funkcji
{
	printf("Rano wstan!\n");
}