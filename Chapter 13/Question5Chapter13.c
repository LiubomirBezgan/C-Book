// Question5Chapter13.c
// v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DL_WIERSZA 256
int main(int argc, char * argv[])
{
	FILE * wp;
	char wiersz[DL_WIERSZA];

	if (3 == argc)
	{
		if (NULL == (wp = fopen(argv[2], "r")))
		{
			fprintf(stderr, "Blad otwarcia pliku %s do odczytu\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while (NULL != fgets(wiersz, DL_WIERSZA, wp))
		{
			if (NULL != strchr(wiersz, *argv[1]))
			{
				fputs(wiersz, stdout);
			}
		}
	}
	else
	{
		printf("Sposob uzycia: %s.exe znak nazwa_pliku", argv[0]);
		exit(1);
	}
	fclose(wp);
	return 0;
}
