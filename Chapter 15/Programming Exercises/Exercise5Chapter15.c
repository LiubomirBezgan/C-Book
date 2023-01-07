//  The test of the rotate_l() function - Exercise5Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#include <limits.h>
unsigned int rotate_l(unsigned int value, int move);
char * itobs(int n, char * ps);
void show_bstr(const char * str);
/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int dec_number;
	int shift;
	char bin_str[CHAR_BIT * sizeof(int) + 1];	
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to test the rotate_l() function.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter a positive decimal number:");
	while (1 == scanf("%u", &dec_number))
	{
		itobs(dec_number, bin_str);
		printf("%10u = ", dec_number);
		show_bstr(bin_str);
		putchar('\n');

		puts("How many bits should be shifted?");
		while ( (1 != scanf("%d", &shift)) && (shift < 0) )
		{
			puts("How many bits should be shifted?\nPlease enter the positive decimal number of shift:");
		}

		
		itobs(rotate_l(dec_number, shift), bin_str);
		printf("%s", " New value = ");
		show_bstr(bin_str);
		putchar('\n');


		puts("Please enter a decimal number:");
	}



/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

unsigned int rotate_l(unsigned int value, int move)
{
	int i;
	bool temp;
	const int length = CHAR_BIT * sizeof(unsigned int);
	const int MASK = 0x1;
	for (i = 0; i < move; i++)
	{
		if ( MASK == ( (value >> (length - 1) ) & MASK) )
		{	
			temp = true;	
		}
		else
		{
			temp = false;
		}
		value <<= 1;
		if (temp)
		{
			value |= MASK;
		}
		else
		{
			value &= ~MASK;
		}
	}
	return value;
}

char * itobs(int n, char * ps)
{
	int i;
	static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i--, n >>= 1)
	{
		ps[i] = (01 & n) + '0';	// ASCII
	}
	ps[size] = '\0';
	return ps;
}

void show_bstr(const char * str)
{
	int i = 0;
	while (str[i])		// not the null character
	{
		putchar(str[i]);
		if ( (0 == ++i % 4) && str[i] )
		{
			putchar(' ');
		}
	}
}