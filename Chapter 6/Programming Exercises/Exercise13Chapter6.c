// tablica poteg - Exercise13Chapter6.c
// v1.0
#include <stdio.h>
int potdwa(int a);


int main(void)
{
	int j, array[8];
	array[0] = 1;
	for (j=1; j <= 7; j++)
		array[j] = potdwa(j);
	do {
	printf("%d ", array[8-j]);
	}while (--j > 0); 		

	getchar();
	return 0;
}

int potdwa(int a)
{
	int i, out;
	for (i = 1, out = 1; i <= a; i++)
		out *= 2;
	return out;
}