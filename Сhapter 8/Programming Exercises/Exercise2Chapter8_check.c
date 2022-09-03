//  sprawdzenie: znak - kod ASCII (dziesietny) - Exercise2Chapter8_check.c
//  v1.1
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void kod_ASCII_pary(char ch);			// sprawdzana funkcja
#define WIERSZ 10						// maksymalna liczba par w wierszu
#define PRZESUNIECIE 64					// kod ASCII litery A jest o 64 wiekszy niz kod znaku Ctrl+A 
#define NUL 0 							// kod ASCII - \0 - Null
#define BEL 7  							// kod ASCII - \a - Alert
#define BS 8  							// kod ASCII - \b - Backspace
#define HT 9  							// kod ASCII - \t - Horizontal Tabulation
#define LF 10  							// kod ASCII - \n - Line Feed						
#define VT 11  							// kod ASCII - \v - Vertical Tabulation
#define FF 12  							// kod ASCII - \f - Form Feed
#define CR 13  							// kod ASCII - \r - Carriage Return 
#define SPACE 32						// kod ASCII
#define DEL 127							// kod ASCII

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program sluzy do podania kodow ASCII odpowiednich znakow.");
/*  Code ----------------------------------------------------------------------*/
	for (ch = NUL; ch < DEL; ch++)
	{
		kod_ASCII_pary(ch);
		puts("");
	}
	kod_ASCII_pary(DEL);
	return 0;
}

void kod_ASCII_pary(char ch)
{
	if (ch >= SPACE && ch < DEL)
			printf("%2c - %3d   ", ch, ch);
		else if (ch < SPACE)
			switch (ch)
		{
			case NUL :
				printf("\\0 - %3d   ", ch);
				break;
			case BEL :
				printf("\\a - %3d   ", ch);
				break;
			case BS :
				printf("\\b - %3d   ", ch);
				break;
			case HT : 
				printf("\\t - %3d   ", ch);
				break; 
			case LF : 
				printf("\\n - %3d   ", ch);
				break;
			case VT : 
				printf("\\v - %3d   ", ch);
				break;
			case FF : 
				printf("\\f - %3d   ", ch);
				break;
			case CR : 
				printf("\\r - %3d   ", ch);
				break;
			default : printf("^%c - %3d   ", ch + PRZESUNIECIE, ch);
		}
		else
			printf("^? - %3d   ", ch);
}