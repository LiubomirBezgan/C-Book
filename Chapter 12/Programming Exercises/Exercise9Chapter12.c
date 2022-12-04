// cwiczenie z pamiecia przydzielana dynamicznie - Exercise9Chapter12.c
// v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mylib.h>
#define MAX_LENGTH 46

int main(void)
{
	char slowo[MAX_LENGTH];
	int liczba_slow;
	char ** tabl_wsk;
	int i = 0;

	printf("Podaj liczbe slow do wprowadzenia: ");
	while (1 != scanf("%d", &liczba_slow) || liczba_slow <= 0)
	{
		czysty_bufor();
		printf("Blad. Podaj dodatnia liczbe slow do wprowadzenia: ");
	}
	tabl_wsk = (char **) malloc(liczba_slow * sizeof(char *));
	printf("Wprowadz %d slow:\n", liczba_slow);
	while (i < liczba_slow && 1 == scanf("%s", slowo))
	{
		*(tabl_wsk + i) = (char *) malloc(strlen(slowo) * sizeof(char));
		strcpy(*(tabl_wsk + i), slowo);
		i++;
	}
	puts("Oto wprowadzone slowa:");
	for (i = 0; i < liczba_slow; i++)
	{
		puts(*(tabl_wsk + i));
		free(*(tabl_wsk + i));
	}
	free(tabl_wsk);

	return 0;
}