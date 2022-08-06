// "Imiona" - wykorzystuje instrukcje switch - Listing_7_11.c
// v1.0
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;

	puts("Podaj mi wielka litere, a ja podam Ci imie na te litere.");
	puts("Wpisz wielka litere; # konczy zabawe.");

	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;

		if (isupper(ch))		// tylko wielkie litery
			switch (ch)
			{
				case 'A' :
					puts("Amadeusz");
					break;
				case 'B' :
					puts("Barbara");
					break;
				case 'C' :
					puts("Cyryl");
					break;
				case 'D' :
					puts("Dariusz");
					break;
				case 'E' :
					puts("Elzbieta");
					break;
				case 'F' :
					puts("Franciszek");
					break;
				case 'G' :
					puts("Grazyna");
					break;
				case 'H' :
					puts("Hanna");
					break;
				case 'I' :
					puts("Ilona");
					break;
				default :
					puts("To za trudne!");	
			}					// koniec switch
		else
			puts("Rozpoznaje tylko wielkie litery.");
		while (getchar() != '\n')
			continue;
		puts("\nPodaj kolejna litere lub znak '#'.");
	}							// koniec petli while

	puts("Do widzenia!");
	getchar();
	getchar();
	return 0;
}