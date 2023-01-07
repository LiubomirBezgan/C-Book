//  The test of the on_number() function - Exercise3Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#include <limits.h>
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
	int i;
	const int length = CHAR_BIT * sizeof(unsigned int);
	const int MASK = 0x1;
	for (i = 0; i < length; i++)
	{
		if ( ( ( dec >> (length - i - 1) ) & MASK) == MASK )
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
		if ( 0 == (i + 1) % 4 )
		{
			putchar(' ');
		}
	}
}


int on_number(int dec)
{
	int i;
	int result = 0;
	const int length = CHAR_BIT * sizeof(unsigned int);
	const int MASK = 0x1;
	for (i = 0; i < length; i++, dec >>= 1)
	{
		if ( (dec & MASK) == MASK )
		{
			result++;
		}
	}

	return result;
}