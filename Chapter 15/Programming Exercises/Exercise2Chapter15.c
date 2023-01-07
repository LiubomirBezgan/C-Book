//  The application of C's bitwise operators - Exercise2Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
double to_the_n_power(int base, int power);
int binstring_to_decnum(const char * string);
void printf_titulus(const char * binstring);
void dec_to_bin(int dec);

/*  Main ----------------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
	int first, second;

	puts("The program is used for the application of C's bitwise operators\nto two binary strings, which both are command-line arguments.\n");
	if (argc < 3)
	{
		printf("Usage: %s binary_numer_1 binary_numer_2\n", argv[0]);
	}
	else
	{
		first = binstring_to_decnum(argv[1]);
		second = binstring_to_decnum(argv[2]);

		printf("~%s = ", argv[1]);
		printf_titulus(argv[1]);
		putchar('\n');

		printf("~%s = ", argv[2]);
		printf_titulus(argv[2]);
		putchar('\n');

		printf("\n%s & %s = ", argv[1], argv[2]);
		dec_to_bin(first & second);
		printf("\n%s | %s = ", argv[1], argv[2]);
		dec_to_bin(first | second);
		printf("\n%s ^ %s = ", argv[1], argv[2]);
		dec_to_bin(first ^ second);
	}

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

void printf_titulus(const char * binstring)
{
	int i = -1;
	while (*(binstring + ++i) != '\0')
	{
		if ('1' == *(binstring + i))
		{
			putchar('0');
		}
		else if ('0' == *(binstring + i))
		{
			putchar('1');
		}
		else
		{
			putchar('e');
		}
	}
}

int binstring_to_decnum(const char * string)
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