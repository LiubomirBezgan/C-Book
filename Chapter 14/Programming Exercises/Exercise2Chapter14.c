//  months - Exercise2Chapter14.c
//  v1.0
#include "year.h"
int days_improved(int given_day, char * given_month_name, int given_year);
int leap_day(int year);
int months_impact(char * month_name);

int main(void)
{
	char month_name[NAME_LEN];
	int day;
	int given_year;

	puts("Please enter the day:");
	while ( 1 != scanf("%d", &day) || day < 1 || day > (int) year[0].days)
	{
		while ('\n' != getchar())
		{
			continue;
		}
		puts("Please try again (enter a number from 1 and 31):");
	}

	puts("Please enter the month:");
	while ( 1 != scanf("%s", month_name) )
	{
		while ('\n' != getchar())
		{
			continue;
		}
		puts("Please try again \n(The month can be a month number, a month name, or a month abbreviation.):");
	}

	puts("Please enter the year:");
	while ( 1 != scanf("%4d", &given_year) )
	{
		while ('\n' != getchar())
		{
			continue;
		}
		puts("Please try again (enter a number from 1 and 2999):");
	}


	printf("The total number of days in the year up through the given day is %d.\n",  days_improved(day, month_name, given_year));
	return 0;
}

int days_improved(int given_day, char * given_month_name, int given_year)
{
	if ( leap_day(given_year) && (months_impact(given_month_name) >= ( (int) year[0].days + (int) year[1].days)) )
	{
		return given_day + months_impact(given_month_name) + leap_day(given_year);
	}
	else
	{
		return given_day + months_impact(given_month_name);
	}
}

int leap_day(int year)
{
	if (0 == year % 4)
	{
		if (0 == year % 100)
		{
			if (0 == year % 400)
			{
				return 1;
			}
			else
			{
				return 0;
			}

		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int months_impact(char * month_name)
{
	int total = 0;
	int i;

	if (!isdigit(*month_name))
	{
		char * temp = month_name;
		bool found = false;

		while ('\0' != *temp)
		{
			*temp = tolower(*temp);
			temp++;
		}

		for (i = 0; i < MONTHS; i++)
		{
			if (0 == strcmp(month_name, year[i].name) || 0 == strcmp(month_name, year[i].short_form))
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
	else if (atoi(month_name) > 0 && atoi(month_name) <= MONTHS)	// month_name contains digits
	{
		for (i = 0; i < atoi(month_name) - 1; i++)
		{
			total += year[i].days;
		}
		return total;
	}
	else
	{
		return -1;
	}
}