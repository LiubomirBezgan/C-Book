//  PESEL - Exercise4bChapter14.c
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

void print_id(personal_data_t worker);

int main(void)
{
	personal_data_t workers[CTI] = {
		{92041244567, {"Mateusz", "Tomasz", "Borkowski"}},
		{96070823839, {"Karol", "Pawel", "Palyga"}},
		{92022167646, {"Liubomir", "", "Bezgan"}}
	};
	int i;
	
	for (i = 0; i < CTI; i++)
	{
		print_id(workers[i]);
	}
	return 0;
}


void print_id(personal_data_t worker)
{	

		if ('\0' == worker.fullname.middle_name[0])
		{
			printf("%s, %s - - %lld\n", worker.fullname.surname, worker.fullname.first_name, worker.pesel);
		}
		else
		{
			printf("%s, %s %c. - - %lld\n", worker.fullname.surname, worker.fullname.first_name, worker.fullname.middle_name[0], worker.pesel);
		}
	
}