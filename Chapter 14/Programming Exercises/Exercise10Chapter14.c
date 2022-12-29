//  calculator (an array of pointers to functions) - Exercise10Chapter14.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

char my_getchar(void);
int calculator_menu(void);
double my_addition(double a, double b);
double my_subtraction(double a, double b);
double my_multiplication(double a, double b);
double my_division(double a, double b);
double my_exponentiation(double a, double b);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int choice;
	double a, b, c;
	double (*pf[6])(double a, double b) = { my_addition, my_subtraction, my_multiplication, my_division, my_exponentiation };

	
/*  Description ---------------------------------------------------------------*/
	puts("Here is my calculator.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter the first number:");
	scanf("%lf", &a);
	clear_buffer();

	puts("Please enter the second number:");
	scanf("%lf", &b);
	clear_buffer();
	printf("\na = %f\nb = %f\n", a, b);

	while ( 5 != (choice = calculator_menu()) )
	{
		printf("\na = %f\nb = %f\n", a, b);
		c = pf[choice](a, b);
		printf ("c = %f", c);
	}
/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

int calculator_menu(void)
{
	char ch;

	puts("\n-------------------------------------------------------------------------------");
	puts("To choose a  operation, enter its letter label:");
	puts("a) Addition          d) Division");
	puts("b) Subtraction       e) Exponentiation");
	puts("c) Multiplication    f) Quit");
	puts("-------------------------------------------------------------------------------");

	ch = my_getchar();
	while ( (ch < 'a') || (ch > 'f') )
	{
		puts("Please enter a letter from a to f");
		ch = my_getchar();
	}
	return (int) ch - 97;
}


char my_getchar(void)
{
	char ch;
	ch = getchar();
	while (getchar() != '\n')
    {
        continue;
    }
    return tolower(ch);
}



double my_addition(double a, double b)
{
	return (a + b);
}

double my_subtraction(double a, double b)
{
	return (a - b);
}

double my_multiplication(double a, double b)
{
	return (a * b);
}

double my_division(double a, double b)
{
	return (a / b);
}

double my_exponentiation(double a, double b)
{
	int i;
	double total = 1.0;
	for (i = 0; i < b; i++)
	{
		total *= a;
	}
	return total;
}
