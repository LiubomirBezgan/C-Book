// n n+1 n+2 ... n+10 - Exercise2Chapter5.c
// v1.0
#include <stdio.h>

int main(void)
{
	int liczba;
	int i = 0;
	
	puts("Prosze o podanie liczby calkowitej: ");
	scanf("%d", &liczba);

	while (i < 10)
		printf("%d\n", ++i + liczba);

	getchar();
	getchar();
	return 0;
}