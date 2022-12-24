//  PESEL - Exercise5Chapter14.c
//  v1.0
#include <stdio.h>
#define FNLEN 1020
#define SURNLEN 747
#define CSIZE 4
#define EXAMS 5

typedef struct name {
	char first_name[FNLEN];
	char surname[SURNLEN];
} name_t;

typedef struct student {
	name_t students_name;
	float grade[EXAMS];
	float average_grade;
} students_grades_t;

void score_acquisition(students_grades_t * pt_group, int num);
void score_averaging(students_grades_t * pt_group, int num);
void score_printing(students_grades_t * pt_group, int num);

int main(void)
{
	students_grades_t group[CSIZE] = {
		{ {"Mateusz", "Borkowski"}, },
		{ {"Karol", "Palyga"}, },
		{ {"Liubomir","Bezgan"}, },
		{ {"Tomasz", "Bohun"}, }
	};

	score_acquisition(group, CSIZE);

	score_averaging(group, CSIZE);

	score_printing(group, CSIZE);
	
	return 0;
}

void score_acquisition(students_grades_t * pt_group, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		printf("Please enter %s %s's scores:\n", (pt_group + i)->students_name.first_name, (pt_group + i)->students_name.surname);
		for (j = 0; j < EXAMS; j++)
		{
			while ( 1 != scanf("%f", &(pt_group + i)->grade[j]) || (pt_group + i)->grade[j] < 0 || (pt_group + i)->grade[j] > 100)
			{
				while ('\n' != getchar())
				{
					continue;
				}
				puts("Please try again (enter a number from 0 and 100):");
			}
		}
	}
}

void score_averaging(students_grades_t * pt_group, int num)
{
	float total = 0.0;
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < EXAMS; j++)
		{
			total += (pt_group + i)->grade[j];
		}
		(pt_group + i)->average_grade = total / EXAMS;
		total = 0.0;
	}
}

void score_printing(students_grades_t * pt_group, int num)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		printf("%s %s's scores: ", (pt_group + i)->students_name.first_name, (pt_group + i)->students_name.surname);
		for (j = 0; j < EXAMS - 1; j++)
		{
			printf("%g, ", (pt_group + i)->grade[j]);
		}
		printf("%g\n", (pt_group + i)->grade[j]);
		printf("The average score: %g\n", (pt_group + i)->average_grade);
	}
}