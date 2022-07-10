// ASCII Table (MISRA compliant)
// v2.0
#include <stdio.h>
#include <limits.h>	// granice liczb calkowitych

int main(void)
{
	// definicja zmiennych
	signed char ch = CHAR_MIN;

	printf("ASCII Table\n\nKOD\tSYMBOL\n");

	while (ch != 127)
	{
		printf("%d\t%#c\n", ch, ch);
		ch=ch+1;
	}
	printf("%d\t%#c\n", ch, ch);
	getchar();
	return 0;
}