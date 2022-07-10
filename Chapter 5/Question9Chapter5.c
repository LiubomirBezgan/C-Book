// od 'a' do 'g' - Question9Chapter5.c
// v1.0
#include <stdio.h>
#define G 103

int main(void)
{
	signed char n = 96; // 96 = '`'

	while (n++ < G)
		printf("%5c", n);
	printf("\n");

	getchar();
	return 0;
}