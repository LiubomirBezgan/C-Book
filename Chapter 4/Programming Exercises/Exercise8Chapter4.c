// opis - Exercise8Chapter4.c
// v1.0
#include <stdio.h>
#define L_PRZEZ_G 3.785 // jeden galon to 3,785 litra
#define KL_PRZEZ_M 1.609 // jedna mila to ok. 1,609 kilometra

int main(void)
{
	float mile, galony;
	puts("Prosze podac liczbe przebytych mil: ");
	scanf("%f", &mile);
	puts("Prosze podac liczbe zuzytych galonow paliwa: ");
	scanf("%f", &galony);
	puts("");
	printf("Poniewaz przebyles %.2f mil ( %.2f km), zuzywajac przy tym %.2f galonow (%.2f litrow),\n", mile, mile * KL_PRZEZ_M, galony, galony * L_PRZEZ_G);
	printf("poziom zuzyczia paliwa wynosi %.1f mile/galon (%.1f litry/100km).\n", mile/galony, (100 * galony * L_PRZEZ_G)/(mile * KL_PRZEZ_M));



	getchar();
	getchar();
	return 0;
}