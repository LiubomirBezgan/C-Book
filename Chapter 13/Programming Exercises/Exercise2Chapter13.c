//  kopiowanie pliku (tryb binarny)- Exercise2Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>				// prototyp funkcji exit()

int main(int argc, char * argv[])
{
	FILE *wp_zro, *wp_doc;			// wskazniki plikowe
	char byte;

	if (argc != 3)
	{
		printf("Sposob uzycia: %s.exe nazwa_pliku_zrodlowego nazwa_pliku_docelowego\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ( (wp_zro = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Nie mozna otworzyc %s do odczytu\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ( (wp_doc = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Nie mozna utworzyc %s do zapisu\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ( 0 != fread(&byte, sizeof(char), 1, wp_zro) )
	{
		fwrite(&byte, sizeof(char), 1, wp_doc);
	}
	fclose(wp_zro);
	fclose(wp_doc);
	return 0;
}