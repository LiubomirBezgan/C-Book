// "Samoglos" - wykorzystuje etykiety wielokrotne - Listing_7_12.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch;
	int a_licz, e_licz, i_licz, o_licz, u_licz, y_licz;
	a_licz = e_licz = i_licz = o_licz = u_licz = y_licz = 0;

	puts("Wpisz jakis tekst; '#' konczy program.");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case 'a' :
			case 'A' : a_licz++;
					   break;
			case 'e' :
			case 'E' : e_licz++;
					   break;
			case 'i' :
			case 'I' : i_licz++;
					   break;
			case 'o' :
			case 'O' : o_licz++;
					   break;
			case 'u' :
			case 'U' : u_licz++;
					   break;
			case 'y' :
			case 'Y' : y_licz++;
					   break;
			default :  break;
		}				// koniec switch
	}					// koniec petli while

	puts("Liczba samoglosek:    A    E    I    O    U    Y");
	printf("                   %4d %4d %4d %4d %4d %4d\n", a_licz, e_licz, i_licz, o_licz, u_licz, y_licz);
	getchar();
	getchar();
	return 0;
}