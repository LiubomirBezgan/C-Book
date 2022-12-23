//  leap_year.c tests leap_day() 
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
int leap_day(int year);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int year;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program tests leap_day() function.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter the year:");
	while (1 == scanf("%d", &year))
	{
		if (leap_day(year))
		{
			puts("Leap year");
		}
		else
		{
			puts("Common year");
		}
	}

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

int leap_day(int year)
{
	if (0 == year % 4)
	{
		if (0 == year % 100)
		{
			if (0 == year % 400)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}