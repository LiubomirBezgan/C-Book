// bez goto i continue - Question10Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch;
	while ((ch = getchar()) != '#')
	{
		if (ch != '\n')
		{
			printf("Krok 1\n");
			
			if (ch != 'c' && ch != 'h' && ch != 'b')
				printf("Krok 2\n");
			if (ch != 'c' && ch != 'b')
				printf("Krok 3\n");
			if (ch == 'b')
				break;
		}

	}
	printf("Koniec\n");
	return 0;
}