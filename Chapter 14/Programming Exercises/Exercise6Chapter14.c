//  a basketball team - Exercise6Chapter14.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#define PMNBT 13							// Poland men's national basketball team
#define FILE_NAME "PMNBT.txt"
#define FNLEN 1020
#define SURNLEN 747

typedef struct name {
	char first_name[FNLEN];
	char surname[SURNLEN];
} name_t;

typedef struct player {
	unsigned int number;
	name_t players_name;
	unsigned int two_pointers_shooting;
	unsigned int two_pointers_scored;
	unsigned int assists;
	unsigned int fouls;
	float efficiency;
} bask_player_t;

void print_stats(bask_player_t * pt_team, int members);
void efficiency_analysis(bask_player_t * pt_team, int members);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	FILE * fp;
	bask_player_t pmnbt[PMNBT] = {{0, }};
	unsigned int c_number = 0;				// current player's number
	char c_first_name[FNLEN];
	char c_surname[SURNLEN];
	unsigned int c_two_pointers_shooting;
	unsigned int c_two_pointers_scored;
	unsigned int c_assists;
	unsigned int c_fouls;
	int i;
	int pos = 0;
	bool found = false;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to analyze statistics of basketball team's members.\n");
	
/*  Code ----------------------------------------------------------------------*/
	
	// set up input
	if ( (fp = fopen(FILE_NAME, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}

	printf("%s contains:\n", FILE_NAME);
	while (7 == fscanf(fp, "%u %s %s %u %u %u %u", &c_number, c_first_name, c_surname, &c_two_pointers_shooting, &c_two_pointers_scored, &c_assists, &c_fouls))
	{
		if(ferror(fp))
		{
			fprintf(stderr, "A read error has occurred.\n");
			exit(EXIT_FAILURE);		
		}
		else
		{
			printf("%2u %-10s %-11s %2u %2u %2u %2u\n", c_number, c_first_name, c_surname, c_two_pointers_shooting, c_two_pointers_scored, c_assists, c_fouls);
			for (i = 0; i < PMNBT; i++)
			{
				if (pmnbt[i].number == c_number)
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				pmnbt[i].two_pointers_shooting += c_two_pointers_shooting;
				pmnbt[i].two_pointers_scored += c_two_pointers_scored;
				pmnbt[i].assists += c_assists;
				pmnbt[i].fouls += c_fouls;
			}
			else
			{
				if (pos < PMNBT)
				{
					pmnbt[pos].number = c_number;
					strcpy(pmnbt[pos].players_name.first_name, c_first_name);
					strcpy(pmnbt[pos].players_name.surname, c_surname);
					pmnbt[pos].two_pointers_shooting += c_two_pointers_shooting;
					pmnbt[pos].two_pointers_scored += c_two_pointers_scored;
					pmnbt[pos].assists += c_assists;
					pmnbt[pos].fouls += c_fouls;
					pos++;
				}
			}
			found = false;
		}
	}

	efficiency_analysis(pmnbt, PMNBT);

	print_stats(pmnbt, PMNBT);
/*  Ending --------------------------------------------------------------------*/
	fclose(fp);
	end('#');
	return 0;
}

void print_stats(bask_player_t * pt_team, int members)
{
	int i;

	puts("\nHere is the team's statistics:");
	puts("\t\t\t\t2-pointers\t2-pointers");
	puts(" #\tname\t\t\tshooting\tscored\t\tassists\tfouls\tefficiency");
	for (i = 0; i < members; i++)
	{
		printf("%2u\t%-10s %-11s\t%u\t\t%u\t\t%u\t%u\t%.2f\n",
			(pt_team + i)->number, (pt_team + i)->players_name.first_name, (pt_team + i)->players_name.surname,
			(pt_team + i)->two_pointers_shooting, (pt_team + i)->two_pointers_scored,
			(pt_team + i)->assists, (pt_team + i)->fouls, (pt_team + i)->efficiency);
	}
}

void efficiency_analysis(bask_player_t * pt_team, int members)
{
	int i;
	for (i = 0; i < members; i++)
	{
		(pt_team + i)->efficiency = (float) (pt_team + i)->two_pointers_scored / (pt_team + i)->two_pointers_shooting;
	}
}