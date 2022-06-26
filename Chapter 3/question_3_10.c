// Question 10, Chapter 3
// v1.0
#include <stdio.h>

int main (void)
{
	int krowy, nogi;
	printf ("Ile krowich nog naliczyles?\n");
	scanf ("%d", &nogi);
	krowy = nogi / 4;
	printf ("Wyglada na to, ze masz %d krow.\n", krowy);
	getchar();
	getchar();
	return 0;
}
