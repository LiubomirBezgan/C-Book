//  PESEL - Exercise4aChapter14.c
//  v1.0
#include <stdio.h>
#define FNLEN 1020
#define SURNLEN 747
#define CTI 3

typedef struct full_name {
	char first_name[FNLEN];
	char middle_name[FNLEN];
	char surname[SURNLEN];
} full_name_t;

typedef struct personal_data {
	long long pesel;
	full_name_t fullname;
} personal_data_t;

void print_id(personal_data_t array[], int num);

int main(void)
{
	personal_data_t workers[CTI] = {
		{92041244567, {"Mateusz", "Tomasz", "Borkowski"}},
		{96070823839, {"Karol", "Pawel", "Palyga"}},
		{92022167646, {"Liubomir", "", "Bezgan"}}
	};
	print_id(workers, CTI);

	return 0;
}


void print_id(personal_data_t array[], int num)
{	
	int i;

	for (i = 0; i < num; i++)
	{
		if ('\0' == array[i].fullname.middle_name[0])
		{
			printf("%s, %s - - %lld\n", array[i].fullname.surname, array[i].fullname.first_name, array[i].pesel);
		}
		else
		{
			printf("%s, %s %c. - - %lld\n", array[i].fullname.surname, array[i].fullname.first_name, array[i].fullname.middle_name[0], array[i].pesel);
		}
	
	}
}