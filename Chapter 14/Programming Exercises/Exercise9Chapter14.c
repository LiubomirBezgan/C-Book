//  The Colossus Airlines fleet II - Exercise9Chapter14.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#define NUM_OF_SEATS 12			// the number of seats
#define NUM_OF_FLIGHTS 4
#define FNLEN 1020
#define SURNLEN 747

const int flight_number[] = {102, 311, 444, 519};
const char * files[] = {"flight102.dat", "flight311.dat", "flight444.dat", "flight519.dat"};

typedef struct name {
	char first_name[FNLEN];
	char surname[SURNLEN];
} name_t;

typedef struct airplane_seat {
	int id_number;
	bool assigned;
	name_t seat_holder;
} seat_t;

int choice_of_flights(void);
char my_getchar(void);
char seat_assignment_menu_flights(int choice);
void show_number_of_empty_seats(seat_t * pt_airplane, int num);
void show_list_of_empty_seats(seat_t * pt_airplane, int num);
void show_alphabetical_list_of_seats_flights(seat_t * pt_airplane, int num);
int assign_a_customer_to_a_seat_assignment(seat_t * pt_airplane);
int delete_a_seat_assignment(seat_t * pt_airplane);
FILE * set_up_input (const char * file_name);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	FILE * fp;
	int size = sizeof (seat_t);
	int index;
	int j;
	int choice;
	char ch;
	seat_t airplane[NUM_OF_FLIGHTS][NUM_OF_SEATS];
	
/*  Description ---------------------------------------------------------------*/
	puts("The Colossus Airlines.");
	puts("The program is used for seating reservation.\n");
	
/*  Code ----------------------------------------------------------------------*/

	// a choice of flights
	choice = choice_of_flights();

	while (choice >= 0)
	{
		// set up input
		fp = set_up_input(files[choice]);

		// set up the array of structures
		index = 0;
		while (index < NUM_OF_SEATS && 1 == fread(&airplane[choice][index++], size, 1, fp))
		{
			continue;
		}
		if (index != NUM_OF_SEATS)
		{
			for (j = 0; j < NUM_OF_SEATS; j++)
			{
				airplane[choice][j].id_number = j + 1;
				airplane[choice][j].assigned = false;
			}
			puts("All assignments have been reset.");
		}

		// main loop
		while ( 'f' != (ch = seat_assignment_menu_flights(choice)) )
		{
			switch (ch)
			{
			case 'a' :
				show_number_of_empty_seats(airplane[choice], NUM_OF_SEATS);
				break;
			case 'b' :
				show_list_of_empty_seats(airplane[choice], NUM_OF_SEATS);
				break;
			case 'c' :
				show_alphabetical_list_of_seats_flights(airplane[choice], NUM_OF_SEATS);
				break;
			case 'd' :
				assign_a_customer_to_a_seat_assignment(airplane[choice]);
				break;
			default :
				delete_a_seat_assignment(airplane[choice]);
			} 
		}

		// set up input
		rewind(fp);
		fwrite(airplane[choice], size, NUM_OF_SEATS, fp);
		fclose(fp);

		choice = choice_of_flights();
	}



/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

int choice_of_flights(void)
{
	int temp;
	int i;
	bool found = false;
	puts("\nPlease select a flight (q to quit):");
	puts("    102        311    ");
	puts("    444        519    ");
	if (1 != scanf("%d", &temp))
	{
		puts("Thank you and goodbye.");
		return -1;
	}
	clear_buffer();
	for (i = 0; i < NUM_OF_FLIGHTS; i++)
	{
		if (temp == flight_number[i])
		{
			found = true;
			break;
		}
	}
	while (!found)
	{
		puts("Please enter 102, 311, 444, 519 or q to quit:");
		if (1 != scanf("%d", &temp))
		{
			puts("Thank you and goodbye.");
			return -1;
		}
		clear_buffer();
		for (i = 0; i < NUM_OF_FLIGHTS; i++)
		{
			if (temp == flight_number[i])
			{
				found = true;
				break;
			}
		}
	}
	return i;

}

char seat_assignment_menu_flights(int choice)
{
	char ch;

	puts("\n-------------------------------------------------------------------------------");
	printf("Welcome to flight %d menu! ", flight_number[choice]);
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats         d) Assign a customer to a seat assignment");
	puts("b) Show list of empty seats           e) Delete a seat assignment");
	puts("c) Show alphabetical list of seats    f) Choose a flight");
	puts("-------------------------------------------------------------------------------");

	ch = my_getchar();
	while ( (ch < 'a') || (ch > 'f') )
	{
		puts("Please enter a letter from a to f");
		ch = my_getchar();
	}
	return ch;
}

char my_getchar(void)
{
	char ch;
	ch = getchar();
	while (getchar() != '\n')
    {
        continue;
    }
    return tolower(ch);
}

void show_number_of_empty_seats(seat_t * pt_airplane, int num)
{
	int total = 0;
	int i;
	for (i = 0; i < num; i++)
	{
		if ( !((pt_airplane + i)->assigned) )
		{
			total++;
		}
	}
	printf("The total number of empty seats is %d.\n", total);
}

void show_list_of_empty_seats(seat_t * pt_airplane, int num)
{
	int i;
	puts("Here is the list of empty seats:");

	for (i = 1; i <= num; i++)
	{
		if ( !((pt_airplane + i - 1)->assigned) )
		{
			printf("%2d", (pt_airplane + i - 1)->id_number);
		}
		else
		{
			printf("%s", "__");
		}

		if (0 != i % 2)
		{
			printf("%s", "    ");
		}
		else
		{
			putchar('\n');
		}
	}
}

void show_alphabetical_list_of_seats_flights(seat_t * pt_airplane, int num)
{
	int i;
	puts("Here is the alphabetical list of seats:");

	for (i = 1; i <= num; i++)
	{
		if ((pt_airplane + i - 1)->assigned)
		{
			printf("%2d - %s %s\n", (pt_airplane + i - 1)->id_number, (pt_airplane + i - 1)->seat_holder.first_name, (pt_airplane + i - 1)->seat_holder.surname);
		}
		else
		{
			printf("%2d\n", (pt_airplane + i - 1)->id_number);
		}
	}
}

int assign_a_customer_to_a_seat_assignment(seat_t * pt_airplane)
{
	int temp;
	int i;
	printf("%s", "Please enter a seat number (0 to quit): ");
	while ( (1 != scanf("%d", &temp)) || (temp < 0) || (temp > 12) )
	{
		clear_buffer();
		printf("%s", "Please enter a seat number from 1 to 12 (0 to quit): ");
	}
	clear_buffer();
	if (!temp)
	{
		return 0;
	}

	if ( !((pt_airplane + temp - 1)->assigned) )
	{
		puts("Please enter a seat holder's first name (press [enter] at the start of a line to stop.):");
		get_string((pt_airplane + temp - 1)->seat_holder.first_name, FNLEN);
		if ('\0' == (pt_airplane + temp - 1)->seat_holder.first_name[0])
		{
			return 0;
		}		

		puts("Please enter a seat holder's surname (press [enter] at the start of a line to stop.):");
		get_string((pt_airplane + temp - 1)->seat_holder.surname, SURNLEN);
		if ('\0' == (pt_airplane + temp - 1)->seat_holder.surname[0])
		{
			return 0;
		}

		(pt_airplane + temp - 1)->assigned = true;
		printf("The seat %d has been assigned for %s %s successfully.\n", temp, (pt_airplane + temp - 1)->seat_holder.first_name, (pt_airplane + temp - 1)->seat_holder.surname);
	}
	else
	{
		printf("The place is already assigned by %c", (pt_airplane + temp - 1)->seat_holder.first_name[0]);
		for (i = 0; i < (strlen((pt_airplane + temp - 1)->seat_holder.first_name) - 1); i++)
		{
			putchar('*');
		}
		putchar(' ');
		printf("%c", (pt_airplane + temp - 1)->seat_holder.surname[0]);
		for (i = 0; i < (strlen((pt_airplane + temp - 1)->seat_holder.surname) - 1); i++)
		{
			putchar('*');
		}
		putchar('.');
		putchar('\n');
		return 0;
	}
	return 1;
}

int delete_a_seat_assignment(seat_t * pt_airplane)
{
	int temp;
	printf("%s", "Please enter a seat number (0 to quit): ");
	while ( (1 != scanf("%d", &temp)) || (temp < 0) || (temp > 12) )
	{
		clear_buffer();
		printf("%s", "Please enter a seat number from 1 to 12 (0 to quit): ");
	}
	clear_buffer();
	if (!temp)
	{
		return 0;
	}

	if ( ((pt_airplane + temp - 1)->assigned) )
	{
		(pt_airplane + temp - 1)->assigned = false;
		printf("The assignment of seat %d has been deleted successfully.\n", temp);
	}
	else
	{
		puts("The place is not assigned.\n");
		return 0;
	}
	return 1;
}

FILE * set_up_input (const char * file_name)
{
	FILE * fpt;
	if ( (fpt = fopen(file_name, "r+b")) == NULL )
	{
		fprintf(stderr, "Can't open %s file.\n", file_name);
		if ( (fpt = fopen(file_name, "w+b")) == NULL )
		{
			fprintf(stderr, "Can't create %s\n", file_name);
			exit(EXIT_FAILURE);			
		}
		fprintf(stdout, "The new %s file has been created.\n", file_name);
	}
	rewind(fpt);
	return fpt;
}