// statassert
#include <stdio.h>
#include <limits.h>

_Static_assert(CHAR_BIT == 16, "Niepoprawne zalozenie: 16-bitowy char");

int main(void)
{
	puts("Char ma 16 bitow.");
	return 0;
}