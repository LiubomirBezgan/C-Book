//  rysowanie znakami III (poprawa jakosci obrazu) - Exercise14Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define ROWS 20
#define COLUMNS 30
#define MAX_LENGTH 255
int ch_to_dig(char ch);
char conversion(int digit);
int de_glitching_int(int array[][COLUMNS], int pos_x, int pos_y);

int main()
{
    char ch;
    int array_dig[ROWS][COLUMNS];
    int array_dig_deglitched[ROWS][COLUMNS];  
    char array_ch[ROWS][COLUMNS + 1];
    FILE *plik_in, *plik_out;
    char nazwa_in[MAX_LENGTH], nazwa_out[MAX_LENGTH];
    int x = 0, y = 0;                       // pozycja
    
    puts("Program przetwarza plik skladajacy sie z 600 cyfr (30x20) na rysunek w pliku testowym.\n");

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
	if ( (plik_in = fopen(nazwa_in, "r")) == NULL)
	{
		fprintf(stderr, "Nie moge otworzyc pliku %s.\n", nazwa_in);
		exit(EXIT_FAILURE);
	}

    // uzupelnienie array_dig
    while (EOF != (ch = getc(plik_in)))    
    {
        if (isdigit(ch))
        {
            array_dig[y][x++] = ch_to_dig(ch);
            if (x > 0 && 0 == x % COLUMNS)
            {
                y++;
                x = 0;
            }
            if (y > ROWS)
            {
                break;
            }
        }
    }
    
    // de-glitching array_dig[][]
    for (y = 0; y < ROWS; y++)
    {
        for (x = 0; x < COLUMNS; x++)
        {
            array_dig_deglitched[y][x] = de_glitching_int(array_dig, x, y);
        }
    }

    // uzupelnienie array_ch
    for (y = 0; y < ROWS; y++)
    {
        for (x = 0; x < COLUMNS; x++)
        {
            array_ch[y][x] = conversion(array_dig_deglitched[y][x]);
        }
        array_ch[y][COLUMNS] = '\0';
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
    for (y = 0; y < ROWS; y++)
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

int de_glitching_int(int array[][COLUMNS], int pos_x, int pos_y)
{
    if (0 == pos_x && 0 == pos_y)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y][pos_x + 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y + 1][pos_x]) > 1 ) )
        {
            return (int) round((array[pos_y][pos_x + 1] + array[pos_y + 1][pos_x]) / 2.0);
        }
    }
    else if ( (COLUMNS - 1) == pos_x && 0 == pos_y)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y][pos_x - 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y + 1][pos_x]) > 1 ) )
        {
            return (int) round((array[pos_y][pos_x - 1] + array[pos_y + 1][pos_x]) / 2.0);
        }
    }
    else if ( 0 == pos_x && (ROWS - 1) == pos_y)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y - 1][pos_x]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x + 1]) > 1 ) )
        {
            return (int) round((array[pos_y - 1][pos_x] + array[pos_y][pos_x + 1]) / 2.0);
        }        
    }
    else if ( (COLUMNS - 1) == pos_x && (ROWS - 1) == pos_y)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y - 1][pos_x]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x - 1]) > 1 ) )
        {
            return (int) round((array[pos_y - 1][pos_x] + array[pos_y][pos_x - 1]) / 2.0);
        }       
    }
    else if (0 == pos_y)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y][pos_x - 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x + 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y + 1][pos_x]) > 1 ) )
        {
            return (int) round((array[pos_y][pos_x - 1] + array[pos_y][pos_x + 1] + array[pos_y + 1][pos_x]) / 3.0);
        }
    }
    else if (0 == pos_x)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y - 1][pos_x]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x + 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y + 1][pos_x]) > 1 ) )
        {
            return (int) round((array[pos_y - 1][pos_x] + array[pos_y][pos_x + 1] + array[pos_y + 1][pos_x]) / 3.0);
        }
    }
    else if ( (COLUMNS - 1) == pos_x)  
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y - 1][pos_x]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x - 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y + 1][pos_x]) > 1 ) )
        {
            return (int) round((array[pos_y - 1][pos_x] + array[pos_y][pos_x - 1] + array[pos_y + 1][pos_x]) / 3.0);
        }       
    }
    else if ( (ROWS - 1) == pos_y)
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y - 1][pos_x]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x - 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x + 1]) > 1 ) )
        {
            return (int) round((array[pos_y - 1][pos_x] + array[pos_y][pos_x - 1] + array[pos_y][pos_x + 1]) / 3.0);
        }        
    }
    else
    {
        if ( ( abs(array[pos_y][pos_x] - array[pos_y - 1][pos_x]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x - 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y][pos_x + 1]) > 1 ) && ( abs(array[pos_y][pos_x] - array[pos_y + 1][pos_x]) > 1 ) )
        {
            return (int) round((array[pos_y - 1][pos_x] + array[pos_y][pos_x - 1] + array[pos_y][pos_x + 1] + array[pos_y + 1][pos_x]) / 4.0);
        }       
    }
    return array[pos_y][pos_x];     
}