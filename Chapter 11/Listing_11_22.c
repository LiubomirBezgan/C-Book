//  wartosci zwracane przez strcmp() - Listing_11_22.c
//  v1.0
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("strcmp(\"A\", \"A\") = %d\n", strcmp("A", "A"));
	printf("strcmp(\"A\", \"B\") = %d\n", strcmp("A", "B"));
	printf("strcmp(\"B\", \"A\") = %d\n", strcmp("B", "A"));
	printf("strcmp(\"C\", \"A\") = %d\n", strcmp("C", "A"));
	printf("strcmp(\"Z\", \"a\") = %d\n", strcmp("Z", "a"));
	printf("strcmp(\"koty\", \"kot\") = %d\n", strcmp("koty", "kot"));
	puts("Gotowe.");
	return 0;
}