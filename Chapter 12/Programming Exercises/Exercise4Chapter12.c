//  petla - Exercise4Chapter12.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
unsigned int ile_razy;
unsigned int mnie_wolasz(void);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int input;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla liczbe wywolan funkcji.\nW tym przpadku funkcja zlicza, ile jest mniejszych od\npodanego przez uzytkownika dodatnich liczb calkowitych podzielnych przez 6.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Prosze podac dodatnia liczbe calkowita:");
	scanf("%d", &input);
	if (input > 0)
	{
		while (input > 0)
		{
			if (0 == input % 6)
			{
				mnie_wolasz();
			}
			input--;
		}
		printf("W petli funkcja zostala wywolana %u razy.\n", mnie_wolasz() - 1);
	}
	else
	{
		puts("Prosze nastepnym razem czytac uwazniej.\nDo widzenia!");
	}

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

unsigned int mnie_wolasz(void)
{
	// jakis kod
	return ++ile_razy;
}