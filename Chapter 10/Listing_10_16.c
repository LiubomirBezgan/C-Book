//  inormacje o zippo poprzez zmienna wskaznikowa - Listing_10_16.c
//  v1.0
#include <stdio.h>
int main(void)
{
	int (* pz)[2];
	int zippo[4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
	pz = zippo;

	printf("       pz = %p,    pz + 1 = %p\n", pz, pz + 1);
	printf("    pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
	printf("      *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
	printf("&pz[0][0] = %p, &pz[0][1] = %p\n", &pz[0][0], &pz[0][1]);
	printf("&pz[1][0] = %p, &pz[1][1] = %p\n", &pz[1][0], &pz[1][1]);
	printf(" pz[0][0] = %d,         pz[0][1] = %d\n", pz[0][0], pz[0][1]);
	printf(" pz[1][0] = %d,         pz[1][1] = %d\n", pz[1][0], pz[1][1]);	
	printf("        pz[0][0] = %d\n", pz[0][0]);
	printf("          *pz[0] = %d\n", *pz[0]);
	printf("            **pz = %d\n", **pz);
	printf("        pz[2][1] = %d\n", pz[2][1]);
	printf("*(*(pz + 2) + 1) = %d\n", *(*(pz + 2) + 1));
	return 0;
}

// zippo[m][n] == *(*(zippo + m) + n)
//    pz[m][n] == *(*(pz + m) + n)