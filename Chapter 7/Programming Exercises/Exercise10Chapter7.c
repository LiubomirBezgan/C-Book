//  obliczenie podatku na podstawie amerykanskiej skali podatkowej z roku 1988 - Exercise10Chapter7.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#define PODATEK1 0.15               // ponizej progu
#define PODATEK2 0.28               // powyzej progu
#define PROGSW 17850                // prog podatkowy w przypadku stanu wolnego
#define PROGGR 23900                // prog podatkowy w przypadku glowy rodziny
#define PROGMRW 29750               // prog podatkowy w przypadku malzenstwa, rozliczenia wspolnego
#define PROGMRO 14875               // prog podatkowy w przypadku malzenstwa, rozliczenia osobnego

/*  Main ----------------------------------------------------------------------*/
int main(void)
{

/*  Variables -----------------------------------------------------------------*/
    char *kategoria;				// wskaznik; nazwa kategorii
	float dochod_brutto, podatek_odprowadzony;
	unsigned int prog = 1;			
	bool symbol = false;			// flaga: czy zostal wprowadzony wlasciwy symbol

/*  Description ---------------------------------------------------------------*/
	puts("Program oblicza podatek na podstawie amerykanskiej skali podatkowej z roku 1988.\n");

/*  Code ----------------------------------------------------------------------*/
	while (0 != prog)
    {	
    	// wybor kategorii lub opcji
    	puts("********************************************************");
    	puts("Podaj cyfre odpowiadajaca kategorii lub opcji:");
    	puts("1) stan wolny         3) malzenstwo, rozliczenie wspolne");
    	puts("2) glowa rodziny      4) malzenstwo, rozliczenie osobne");
    	puts("                      5) wyjscie");
    	puts("********************************************************");	
    	while (!symbol)
    	{
    		switch (getchar())
    		{
    			case '1' : {
    				prog = PROGSW;
    				kategoria = "stanu wolnego";
    				symbol = true;
    				break;
    			}
    			case '2' : {
    				prog = PROGGR;
    				kategoria = "glowy rodziny";
    				symbol = true;
    				break;
    			}
    			case '3' : {
    				prog = PROGMRW;
    				kategoria = "malzenstwa, rozliczenia wspolnego";
    				symbol = true;
    				break;
    			}
    			case '4' : {
    				prog = PROGMRO;
    				kategoria = "malzenstwa, rozliczenia osobnego";
    				symbol = true;
    				break;
    			}
    			case '5' : {
    				prog = 0;
    				symbol = true;
    				break;
    			}
    			default :
    				puts("Zly symbol.\nPodaj cyfre od 1 do 5");
    				symbol = false;
    				while ((getchar()) != '\n')
    					continue;		                            // czyszczenie bufora
    		}
    	}
    	// obliczenia i wyswietlenie wynikow
        if (prog == 0)			                                   	// 5) wyjscie
    		puts("Milego dnia!");
    	else
    	{
    	    // wprowadzenie dochodu podlegajacego opodatkowaniu
    		puts("Podaj dochod podlegajacy opodatkowaniu:");	
    		scanf("%f", &dochod_brutto);
    		symbol = false;    		
    		while ((getchar()) != '\n')
    		    continue;											// czyszczenie bufora
    		if (dochod_brutto <= prog)
    			podatek_odprowadzony = PODATEK1 * dochod_brutto;
    		else
    			podatek_odprowadzony = PODATEK1 * prog + PODATEK2 * (dochod_brutto - prog);
    		// wyswietlenie wyniku
    		printf("W przypadku %s i dochodu %.2f $ wysokosc kwoty podatku wynosi %.2f $.\n\n", kategoria, dochod_brutto, podatek_odprowadzony);
    	}
    }
	return 0;
}