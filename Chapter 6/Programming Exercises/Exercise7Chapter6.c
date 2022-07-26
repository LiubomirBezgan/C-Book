// wspak - Exercise7Chapter6.c
// v1.0
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 0;
	char lit=1;
	char slowo[20];	
	puts("Wpisz slowo:");
	
	while ('\n' != lit)
	{
		scanf("%c", &lit);
		slowo[i] = lit;
		i++;
	}
	
	for (i = strlen(slowo); i >=0 ; i--)
		printf("%c", slowo[i]);
	
	getchar();
	return 0;
}