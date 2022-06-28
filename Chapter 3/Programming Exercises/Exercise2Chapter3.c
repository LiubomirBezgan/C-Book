// wyswietla symbol ASCII
// v1.1
#include <stdio.h>

int main(void)
{
	char symbol;
	short kod;
	printf("Prosze podac kod symbolu: ____\b\b\b\b");
	scanf("%hd", &kod);
	symbol = kod;
	printf("\nSymbol %#c ma kod %hd", symbol, symbol);
	getchar();
	getchar();
	return 0;
}