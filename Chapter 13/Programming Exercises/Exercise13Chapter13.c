//  rysowanie znakami II (VLA) - Exercise13Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENGTH 255
int ch_to_dig(char ch);
char conversion(int digit);

int main()
{
    char ch;
    FILE *plik_in, *plik_out;
    char nazwa_in[MAX_LENGTH], nazwa_out[MAX_LENGTH];
    int x = 0, y = 0;                       // pozycja
    int dlugosc_wiersza_biezaca = 0;
    int liczba_wierszy_biezaca = 1;
    int dlugosc_wiersza_max = 0;                // Xmax
    int liczba_wierszy_max = 1;                 // Ymax
    
    puts("Program przetwarza plik skladajacy sie z cyfr na rysunek w pliku testowym.\n");

    // plik wejsciowy    
    puts("Podaj nazwe pliku wejsciowego:");
    while ( 1 != scanf("%s", nazwa_in) || '\0' == nazwa_in[0])
    {
        while (getchar() != '\n')
		{
			continue;
		}
        puts("Blad. Podaj nazwe pliku wejsciowego:");
    }
	if ( (plik_in = fopen(nazwa_in, "r")) == NULL )
	{
		fprintf(stderr, "Nie moge otworzyc pliku %s.\n", nazwa_in);
		exit(EXIT_FAILURE);
	}

    // okreslenie rozmiarow tablic VLA na podstawie pliku zrodlowego
    while ( (ch = getc(plik_in)) != EOF )
    {
        if (isdigit(ch))
        {
            dlugosc_wiersza_biezaca++;
        }
        else if ('\n' == ch)
        {
            liczba_wierszy_biezaca++;
            if (dlugosc_wiersza_biezaca > dlugosc_wiersza_max)
            {
                dlugosc_wiersza_max = dlugosc_wiersza_biezaca;
            }
            dlugosc_wiersza_biezaca = 0;
        }
    }
    liczba_wierszy_max = liczba_wierszy_biezaca;
    
    // przesuniecie kursora odczytu danych na początek wskazanego strumienia
    rewind(plik_in);

    // deklaracja VLA
    int array_dig[liczba_wierszy_max][dlugosc_wiersza_max];
    char array_ch[liczba_wierszy_max][dlugosc_wiersza_max + 1];

    // uzupelnienie array_dig
    while (EOF != (ch = getc(plik_in)))    
    {
        if (isdigit(ch))
        {
            array_dig[y][x++] = ch_to_dig(ch);
            if (x > 0 && 0 == x % dlugosc_wiersza_max)
            {
                y++;
                x = 0;
            }
            if (y > liczba_wierszy_max)
            {
                break;
            }
        }
    }

    // uzupelnienie array_ch
    for (y = 0; y < liczba_wierszy_max; y++)
    {
        for (x = 0; x < dlugosc_wiersza_max; x++)
        {
            array_ch[y][x] = conversion(array_dig[y][x]);
        }
        array_ch[y][dlugosc_wiersza_max] = '\0';
    }

    // plik wyjsciowy    
    puts("Podaj nazwe pliku wyjsciowego:");
    while ( 1 != scanf("%s", nazwa_out) || '\0' == nazwa_out[0])
    {
        while (getchar() != '\n')
		{
			continue;
		}
        puts("Blad. Podaj nazwe pliku wyjsciowego:");
    }
	if ( (plik_out = fopen(nazwa_out, "w")) == NULL )
	{
		fprintf(stderr, "Nie moge otworzyc pliku %s.\n", nazwa_out);
		exit(EXIT_FAILURE);
	}
    
    // zapisywanie danych do pliku wyjsciowego
    for (y = 0; y < liczba_wierszy_max; y++)
    {
        fputs(array_ch[y], plik_out);
        putc('\n', plik_out);   
    }
    
    // sprzatanie
    if (fclose(plik_in) != 0 || fclose(plik_out) != 0)
	{
		fprintf(stderr, "Blad przy zamykaniu plikow.\n");
	}
    return 0;
}

int ch_to_dig(char ch)
{
    int i = ch - '0';
    return i;
}

char conversion(int digit)
{
    char symbol;
    switch( digit )
    {
        case 0:
            symbol = ' ';
            break;
        case 1:
            symbol = '.';
            break;
        case 2:
            symbol = '\'';
            break;
        case 3:
            symbol = ':';
            break;
        case 4:
            symbol = '~';
            break;
        case 5:
            symbol = '*';
            break;
        case 6:
            symbol = '=';
            break;
        case 7:
            symbol = '$';
            break;
        case 8:
            symbol = '%';
            break;
        default :
            symbol = '#';
    }
    return symbol;
}