//  The test of the bit_state() function - Exercise4Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#include <limits.h>
void dec_to_bin(int dec);
int bit_state(int value, int bit_position);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int dec_number, position;	
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to test the bit_state() function.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter a decimal number:");
	while (1 == scanf("%d", &dec_number))
	{
		puts("Please enter a bit position:");
		while (1 != scanf("%d", &position) || position < 0 || position > 31)
		{
			puts("Please enter a bit position in the range of 0 to 31:");
		}

		printf("%d = ", dec_number);
		dec_to_bin(dec_number);
		printf(". There is %d at bit position number %d.\n", bit_state(dec_number, position), position);
		puts("\nPlease enter a decimal number:");
	}

/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

int bit_state(int value, int bit_position)
{
	const int MASK = 0x1;
	if ( MASK == ( (value >> bit_position) & MASK) )
	{	
		return 1;	
	}
	else
	{
		return 0;
	}
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