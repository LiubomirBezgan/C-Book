//  The test of the binstring_to_decnum() function - Exercise1Chapter15.c
//  v1.0
#include <stdio.h>
double to_the_n_power(int base, int power);
int binstring_to_decnum(char * string);

int main(void)
{
	char * pbin = "01001001";

	printf("%s = %d", pbin, binstring_to_decnum(pbin));
	return 0;
}

int binstring_to_decnum(char * string)
{
	int result = 0;
	int length = 0;
	int index = 0;

	while (*(string + length) != '\0')
	{
		length++;
	}
	length--;

	while (length >= 0)
	{
		if ('0' == *(string + length))
		{
			;
		}
		else if ('1' == *(string + length))
		{
			result += (int) to_the_n_power(2, index);
		}
		else
		{
			return -1;
		}
		index++;
		length--;
	}

	return result;
}

double to_the_n_power(int base, int power)
{
	double total = 1.0;
	if (0 == base)
	{
		return 0;
	}
	if (power > 0)
	{
		while (power-- > 0)
		{
			total *= base;
		}
		return total;
	}
	else if (power < 0)
	{
		while (power++ < 0)
		{
			total /= base;
		}
		return total;
	}
	else
	{
		return total;
	}
}