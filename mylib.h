// mylib.h
#define _USE_MATH_DEFINES       // for M_PI definition
#define HARMONIC_MEAN(X, Y) ( 2 / ( (1/(X)) + (1/(Y)) ) )
#define DEG_TO_RAD(X) ( (M_PI / 180) * (X) )

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int chtoi(char cyfra);
void ciag_znakow(char znak, unsigned int ile);

// Sluzy do zamkniecia programu poprzez wprowadzenie znaku ch.
void end(char ch)						
{
	printf("\nPlease enter '%c' to close the program: ", ch);
	while (getchar() != ch)
    {
		continue;
    }
}

void koniec(char ch)
{
    printf("\nWpisz '%c', zeby zamknac program: ", ch);
    while (getchar() != ch)
    {
        continue;
    }
}

// Sluzy do wczytywania calych wierszy i "recznego" zastepowania znakow
// nowego wiersza znakami pustymi badz wczytywania tylko tego, co sie miesci
// do tablicy docelowej, i ignorowania reszty wiersza.
char * wczytaj(char *z, int ile)
{
	char * wynik;
	wynik = fgets(z, ile, stdin);
	if (wynik)							// wynik rozny od NULL
	{
		while (*z != '\n' && *z != '\0')
		{
			z++;
		}
		if (*z == '\n')
		{
			*z = '\0'; 					// znak nowego wiersza -> znak pusty
		}
		else							// z[i] == '\0'
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return wynik;
}

char * get_string(char *from, int num)
{
    char * result;
    result = fgets(from, num, stdin);
    if (result)                          
    {
        while (*from != '\n' && *from != '\0')
        {
            from++;
        }
        if (*from == '\n')
        {
            *from = '\0';                  // '\n' -> '\0'
        }
        else                            // from[i] == '\0'
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return result;
}

// Sluzy do wyswietlenia menu, skladajacego sie z 5 opcji, pobrania znaku odpowiednio
// wybranej opcji oraz zwroceniu numeru opcji (od 1 do 5)).
int menu_5(char * first, char * second, char * third, char * fourth, char * fifth)
{
    size_t str_length;
    int i;
    const int LENGTH = 81;
    const int OPTIONS = 5;
    char str_array[OPTIONS][LENGTH];
    bool symbol = false;                                            // flaga: czy zostal wprowadzony wlasciwy symbol
    int numer_opcji;
    char ch;

    strncpy(*(str_array + 0), first, LENGTH);
    strncpy(*(str_array + 1), second, LENGTH);
    strncpy(*(str_array + 2), third, LENGTH);
    strncpy(*(str_array + 3), fourth, LENGTH);
    strncpy(*(str_array + 4), fifth, LENGTH);

    for (i = 0; i < OPTIONS; i++)
    {
        if (str_length < strlen(str_array[i]))
        {
            str_length = strlen(str_array[i]);
        }
    }

    ciag_znakow('*', 2 * str_length + 3);
    printf("%-*s   %-*s\n", str_length, str_array[0], str_length, str_array[1]);
    printf("%-*s   %-*s\n", str_length, str_array[2], str_length, str_array[3]);
    printf("%-*s\n", str_length, str_array[4]);
    ciag_znakow('*', 2 * str_length + 3);

    printf("Wpisz symbol opcji: ");
    ch = getchar();
    while (!symbol)
    {
        for (i = 0; i < OPTIONS; i++)
        {
            if (ch == str_array[i][0])
            {
                numer_opcji = i + 1;
                symbol = true;
            }
        }
        if (!symbol)
        {
            puts("Zly symbol.");
            printf("\nWpisz symbol ");
            for (i = 0; i < OPTIONS - 2; i++)
            {
                printf("%c, ", str_array[i][0]);
            }
            printf("%c lub ", str_array[i++][0]);
            printf("%c:\n", str_array[i++][0]);
            while ((getchar()) != '\n')
            {
                continue;                                           // czyszczenie bufora
            }
            ch = getchar();
        }
    }
    return numer_opcji;
}

// Sluzy do wyswietlenia znaku odpowiednia liczbe razy (w jednym wierszu).
void ciag_znakow(char znak, unsigned int ile)
{
    int i;
    for (i = 0; i < ile; i++)
     {
         putchar(znak);
     }
    putchar('\n');
}

// Sluzy do potegowania
double potega(double liczba, int do_potegi)
{
    double wynik = 1;
    int i;
    if (do_potegi > 0)
    {
        for (i = 0; i < do_potegi; i++)
        {
            wynik *= liczba;
        }
    }
    else if (do_potegi < 0)
    {
        for (i = 0; i < (do_potegi * -1); i++)
        {
            wynik /= liczba;
        }
    }
    return wynik;
}

// Sluzy do konwersji lancucha na liczbe calkowita
int myatoi(char * array)
{
    int dlugosc = 0;
    int i = 0;
    int wynik = 0;

    while (array[dlugosc] != '\0')
    {
        dlugosc++;
    }
    if (0 == dlugosc)
    {
        return -1;
    }
    else
    {
        i = dlugosc;
        while (--i >= 1)
        {
            if ( !isdigit(array[i]) )
            {
                return 0;
            }
            else
            {
                wynik += (chtoi(array[i]) * potega(10, dlugosc - i - 1));
            }
        }
        if ('-' == array[i])
        {
            wynik *= -1;
        }
        else
        {
            if ( !isdigit(array[i]) )
            {
                return 0;
            }
            else
            {
                wynik += (chtoi(array[i]) * potega(10, dlugosc - i - 1));
            }
        }

    }
    return wynik;
}

// Sluzy do konwersji znaku na liczbe calkowita
int chtoi(char cyfra)
{
    int wynik;

    if (isdigit(cyfra))
    {
        switch (cyfra)
        {
            case '0' :  wynik = 0;
                        break;
            case '1' :  wynik = 1;
                        break;
            case '2' :  wynik = 2;
                        break;
            case '3' :  wynik = 3;
                        break;
            case '4' :  wynik = 4;
                        break;
            case '5' :  wynik = 5;
                        break;
            case '6' :  wynik = 6;
                        break;
            case '7' :  wynik = 7;
                        break;              
            case '8' :  wynik = 8;
                        break;
            default :   wynik = 9;
                        break;
        }
    }
    else
    {
        wynik = -1;
    }
    return wynik;
}

// Sluzy do czyszczenia bufora
void czysty_bufor (void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void clear_buffer (void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

// Sluzy do porownania dwoch lancuchow first i second, ktore nie sa dluzsze niz max_length.
// Wielkosc liter nie jest brana pod uwage (a == A).
int title_comp(char * first, char * second, unsigned int max_length)
{
    char array1[max_length], array2[max_length];

    strncpy(array1, first, max_length);
    strncpy(array2, second, max_length);

    int i = 0;
    while ('\0' != array1[i])
    {
        array1[i] = tolower(array1[i]);
        i++;
    }

    i = 0;
    while ('\0' != array2[i])
    {
        array2[i] = tolower(array2[i]);
        i++;
    }

    if (0 == strcmp(array1, array2))
    {
        return 0;
    }
    return 1;
}

// Sluzy do konwersji znaku cyfry na liczbe calkowita
int ch_to_dig(char ch)
{
    int i = ch - '0';
    return i;
}

