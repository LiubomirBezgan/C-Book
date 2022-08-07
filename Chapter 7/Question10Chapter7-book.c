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
			if (ch == 'b')
				break;
			else if (ch != 'c')
			{
				if (ch == 'q')
					printf("Krok 2\n");
				printf("Krok 3\n");
			}
		}

	}
	printf("Koniec\n");
	return 0;
}