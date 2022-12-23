//  months - Exercise1Chapter14.c
//  v1.0
#include "year.h"

int main(void)
{
	char month_name[NAME_LEN];

	puts("Please enter the name of month:");
	while (1 != scanf("%s", month_name)) 
	{
		while ('\n' != getchar())
		{
			continue;
		}
		puts("Please try again:");
	}
	printf("%d days have passed.\n",  days(month_name));
	return 0;
}

int days(char * month_name)
{
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

	for (i = 0; i < MONTHS; i++)
	{
		total += year[i].days;
		if (0 == strcmp(month_name, months[i]))
		{
			found = true;
			break;
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