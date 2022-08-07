// opis - Question3Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	int waga, wzrost;		// waga w kg, wzrost w cm

	printf("Podaj wage [kg] i wzrost [cm]:\n");
	scanf("%d %d", &waga, &wzrost);

	if (waga < 45 && wzrost > 135)
	{
		if (wzrost >= 182)
			printf("Jestes bardzo wysoki jak na swoja wage.\n");
		else if (wzrost > 163)
			printf("Jestes wysoki jak na swoja wage.\n");
	}
	else if (waga > 135 && wzrost < 122)
		printf("Jestes dosc niski jak na swoja wage.\n");

	else
		printf("Twoja waga jest idealna.\n");
	
	return 0;
}