// do_wile - Listing_6_15.c
// v1.0
#include <stdio.h>

int main(void)
{
	const int tajny_kod = 13;
	int wprowadzony_kod;

	do
	{
		puts("Aby wejsc do klubu terapeutycznego agorafobii,");
		printf("wprowadz wlasciwy kod: ");
		scanf("%d", &wprowadzony_kod);
	} while (wprowadzony_kod != tajny_kod);

	puts("Gratulacje! Jestes wyleczony!");
	
	getchar();
	getchar();
	return 0;
}