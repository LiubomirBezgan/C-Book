//  months_impact.c tests months_impact() 
//  v1.0
#include "year.h"
int months_impact(char * month_name);

int main(void)
{
	char month_name[NAME_LEN];
	
	puts("The program tests months_impact() function.\n");
	puts("Please enter the name of month:");
	while (1 != scanf("%s", month_name)) 
	{
		while ('\n' != getchar())
		{
			continue;
		}
		puts("Please try again:");
	}
	printf("There are %d days until %s.\n",  months_impact(month_name), month_name);
	return 0;
}

int months_impact(char * month_name)
{
	const int M0NTHS = 12;
	const char * months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"}; 
	int total = 0;
	int i;
	bool found = false;
	char * temp = month_name;

	while ('\0' != *temp)
	{
		*temp = tolower(*temp);
		temp++;
	}

	for (i = 0; i < M0NTHS; i++)
	{
		if (0 == strcmp(month_name, months[i]))
		{
			found = true;
			break;
		}
		else
		{
			total += year[i].days;
		}
	}
	if (found)
	{
		return total;
	}
	else
	{
		return -1;
	}
}