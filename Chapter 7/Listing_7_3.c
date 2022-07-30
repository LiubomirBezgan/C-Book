// "Szyfr" - zmienia dane wejsciowe, zachowujac nie-litery
// v1.0
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))		// jesli znak jest litera
			putchar(ch + 1);	// wyswietl nastepna litere
		else
			putchar(ch);		// jesli nie, wyswietl gp bez zmian
	}
	putchar(ch);				//wyswietl znak nowej linii

	getchar();
	return 0;
}