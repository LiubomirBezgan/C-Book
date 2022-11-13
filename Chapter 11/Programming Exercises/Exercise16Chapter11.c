//  funkcja main() z argumentami (edycja liter) - Exercise16Chapter11.c
//  v2.0
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char ch;

	if (argc > 1)
	{
		if (!strncmp(argv[1], "-u", 2))
		{
			while ( (ch = getchar())!= EOF)
			{
				putchar(toupper(ch));
			}
		}
		else if (!strncmp(argv[1], "-l", 2))
		{
			while ( (ch = getchar())!= EOF)
			{
				putchar(tolower(ch));
			}
		}
		else if (!strncmp(argv[1], "-p", 2))
		{
			while ( (ch = getchar())!= EOF)
			{
				putchar(ch);
			}
		}
	}
	else if (1 == argc)
	{
		while ( (ch = getchar())!= EOF)
		{
			putchar(ch);
		}
	}
	return 0;
}
