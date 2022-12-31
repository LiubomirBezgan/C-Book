//  transform() - Exercise11Chapter14.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#include <math.h>
#define NUM_OF_FUN 4
#define SAMPLES 100

void transform(const double * source, double * target, int num, double (* fun)(double));
double my_fun_first(double input);
double my_fun_second(double input);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int j, k;
	int column;
	int temp = 1;
	double source_arr[SAMPLES] = {0}, target_arr[SAMPLES];
	double (*fun_arr[NUM_OF_FUN])(double) = {sin, cos, my_fun_first, my_fun_second};
	char * titles[] = {"sin", "cos", "my_fun_first", "my_fun_second"};
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to test a function called transform().\n");
	
/*  Code ----------------------------------------------------------------------*/
	printf("%s\n","The source array:");
	for (k = 0, column = 0; k < SAMPLES; k++)
	{
		
		source_arr[k] = temp++;
		column++;
		printf("%6.2f ", source_arr[k]);
		if (0 == column % 10)
		{
			putchar('\n');
		}
	}


	for (j = 0; j < NUM_OF_FUN; j++)
	{
		transform(source_arr, target_arr, SAMPLES, fun_arr[j]);
		printf("\nHere is the result of %s function:\n", titles[j]);
		for (k = 0, column = 0; k < SAMPLES; k++)
		{
			printf("%6.2f ", target_arr[k]);
			if (0 == ++column % 10)
			{
				putchar('\n');
			}
		}
	}

/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

void transform(const double * source, double * target, int num, double (* fun)(double))
{
	int i;
	for (i = 0; i < num; i++)
	{
		*(target + i) = fun( *(source + i) );
	}
}

double my_fun_first(double input)
{
	return input * 1.1;
}

double my_fun_second(double input)
{
	return input + 1.1;
}