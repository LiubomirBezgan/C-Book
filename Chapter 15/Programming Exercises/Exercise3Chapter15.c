//  The test of the on_number() function - Exercise3Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
int on_number(int dec);
void dec_to_bin(int dec);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int dec_number;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to test the on_number() function, that returns the number of \"on\" bits in the argument.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter a decimal number:");
	while (1 == scanf("%d", &dec_number))
	{
		printf("%d = ", dec_number);
		dec_to_bin(dec_number);
		printf(". The number of \"on\" bits is %d.", on_number(dec_number));
		puts("\nPlease enter a decimal number:");
	}

/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

void dec_to_bin(int dec)
{
	if (dec / 2 >= 1)
	{
		dec_to_bin(dec / 2);
		if (0 == dec % 2)
		{
			putchar('0');
		}
		else
		{
			putchar('1');
		}
	}
	else if (dec > 0)
	{
		putchar('1');		
	}
	else if (0 == dec)
	{
		putchar('0');		
	}
	else
	{
		printf("%s\n", "error");
	}
}


int on_number(int dec)
{
	static int result;
	result = 0;
	if (dec / 2 >= 1)
	{
		on_number(dec / 2);
		if (0 == dec % 2)
		{
			;
		}
		else
		{
			result++;
		}
	}
	else if (dec > 0)
	{
		result++;		
	}
	else if (0 == dec)
	{
		;	
	}
	else
	{
		printf("%s\n", "error");
	}
	return result;
}