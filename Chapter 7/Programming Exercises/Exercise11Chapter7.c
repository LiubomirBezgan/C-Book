//  Firma ABC Wysylka Warzyw - Exercise11Chapter7.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#define CENA_ARBUZY 1.25			// zl/kg
#define CENA_BURAKI 0.65			// zl/kg
#define CENA_CEBULA 0.89			// zl/kg
#define PROG_ZAMOWIENIE 100			// Zamowienia o wartosci powyzej 100 zl premiowane sa
#define RABAT 0.05					// rabatem w wysokosci 5% naliczanym przed dodaniem kosztow przesylki.
#define PROG1 5 					// kg - Pierwszy prog wagi przesylki.
#define PROG2 20 					// kg - Drugi prog wagi przesylki.
#define KOSZT0 3,5 					// zl - Koszt przesylwki o wadze nieprzekraczajacej PROG1
#define KOSZT1 10 					// zl - Koszt przesylwki o wadze mieszcacej sie pomiedzy PROG1 a PROG2
#define KOSZT2 8 					// zl + 0.1 zl za kazdy kilogram - Koszt przesylwki o wadze przekraczajacej PROG2
#define KOSZT_DODATKOWY 0.1 		// 0.1 zl za kazdy kilogram

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	bool symbol = false;			// flaga: czy zostal wprowadzony wlasciwy symbol?
	bool koniec = false;			// flaga: czy nalezy skonczyc przyjmowanie zamowienia?
	float waga_arbuzy=0, waga_buraki=0, waga_cebula=0;
	float zamawiane_kg, do_zaplaty, rabat=0, koszt_przesylki;

	
/*  Description ---------------------------------------------------------------*/
	puts("Program sluzy do skladania zamowienia w firmie ABC Wysylka Warzyw.");
	puts("Podanie odpowiedniej wielkiej litery umozliwia wpisanie ilosci\nwayrzw (A, B, C) albo konczy przyjmowanie zamowienia (K).");
/*  Code ----------------------------------------------------------------------*/
	// wybor kategorii lub opcji
    	puts("************************************************************");
    	puts("Podaj litere odpowiadajaca kategorii lub opcji:");
    	puts("A) arbuzy - 1.25 zl/kg     B) buraki - 0.65 zl/kg");
    	puts("C) cebula - 0.89 zl/kg     K) koniec przyjmowania zamowienia");
    	puts("************************************************************");
    	while(!koniec) 							// umozliwia wielokrotne zamowienie, az uzytkownik wpisze 'K'
    	{	
	    	while (!symbol)						// umozliwia ponowne podanie litery w przypadku niepowodzenia 
	    	{
	    		switch (getchar())
	    		{
	    			case 'A' : {
	    				puts("Podaj wage arbuzow w kilogramach:");
	    				scanf("%f", &zamawiane_kg);
	    				waga_arbuzy += zamawiane_kg;
	    				symbol = true;
	    				break;
	    			}
	    			case 'B' : {
	    				puts("Podaj wage burakow w kilogramach:");
	    				scanf("%f", &zamawiane_kg);
	    				waga_buraki += zamawiane_kg;
	    				symbol = true;
	    				break;
	    			}
	    			case 'C' : {
	    				puts("Podaj wage cybuli w kilogramach:");
	    				scanf("%f", &zamawiane_kg);
	    				waga_cebula += zamawiane_kg;
	    				symbol = true;
	    				break;
	    			}
	    			case 'K' : {
	    				puts("Koniec przyjmowania zamowienia.");
	    				symbol = true;
	    				koniec = true;
	    				break;	    				
	    			}
	    			default :
	    				puts("Zly symbol.\nPodaj litere 'A', 'B', 'C' albo 'K'");
	    				symbol = false;

	    		}
				while ((getchar()) != '\n')
					continue;		                            // czyszczenie bufora
	    	}
	    	if (!koniec)
	    		puts("Podaj kolejna litere");
	    	symbol = false;
	    }
	    // obliczenia
	    if (waga_arbuzy * CENA_ARBUZY + waga_buraki * CENA_BURAKI + waga_cebula * CENA_CEBULA > PROG_ZAMOWIENIE)
	    	rabat = (waga_arbuzy * CENA_ARBUZY + waga_buraki * CENA_BURAKI + waga_cebula * CENA_CEBULA) * RABAT;
	    koszt_przesylki = KOSZT2 + KOSZT_DODATKOWY * (waga_arbuzy + waga_buraki + waga_cebula);
	    do_zaplaty = koszt_przesylki + ((waga_arbuzy * CENA_ARBUZY + waga_buraki * CENA_BURAKI + waga_cebula * CENA_CEBULA) - rabat);
	    // wyświetlenie wyniku
	    printf("Cena jednastkowa za kilogram: %.2f zl/kg\n", (waga_arbuzy * CENA_ARBUZY + waga_buraki * CENA_BURAKI + waga_cebula * CENA_CEBULA)/(waga_arbuzy + waga_buraki + waga_cebula));
	    printf("Ilosc zamowionych warzyw: arbuzy - %.2f kg, buraki - %.2f kg, cebula - %.2f kg\n", waga_arbuzy, waga_buraki, waga_cebula);
	    printf("Wartosc dla kazdego z zamowionych towarow: arbuzy - %.2f zl, buraki - %.2f zl, cebula - %.2f zl\n", waga_arbuzy * CENA_ARBUZY, waga_buraki * CENA_BURAKI, waga_cebula * CENA_CEBULA);
	    printf("Wartosc calosci zamowienia: %.2f zl\n", waga_arbuzy * CENA_ARBUZY + waga_buraki * CENA_BURAKI + waga_cebula * CENA_CEBULA);
	    printf("Wysokosc przyslugujacego rabatu: %.2f zl\n", rabat);
	    printf("Koszt przesylki: %.2f zl\n", koszt_przesylki);
	    printf("Calkowity koszt zamowienia: %.2f zl\n", do_zaplaty);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}