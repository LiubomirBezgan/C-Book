//  The Colossus Airlines fleet I - Exercise8Chapter14.c
//  v0.1
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#define NUM_OF_SEATS 12			// the number of seats
#define FNLEN 1020
#define SURNLEN 747

typedef struct name {
	char first_name[FNLEN];
	char surname[SURNLEN];
} name_t;

typedef struct airplane_seat {
	int id_number;
	bool assigned;
	name_t seat_holder;
} seat_t;

char my_getchar(void);
char seat_assignment_menu(void);
void show_number_of_empty_seats(seat_t * pt_airplane, int num);
void show_list_of_empty_seats(seat_t * pt_airplane, int num);
void show_alphabetical_list_of_seats(seat_t * pt_airplane, int num);
int assign_a_customer_to_a_seat_assignment(seat_t * pt_airplane);
int delete_a_seat_assignment(seat_t * pt_airplane);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	seat_t airplane_one[NUM_OF_SEATS] = {
		{1, false, {"jojo", "ba"}}, {2, false, {"jojo", "ba"}}, {3, false, {"jojo", "ba"}},
		{4, false, {"jojo", "ba"}}, {5, false, {"jojo", "ba"}}, {6, false, {"jojo", "ba"}},
		{7, false, {"jojo", "ba"}}, {8, true, {"jojo", "ba"}}, {9, false, {"jojo", "ba"}},
		{10, false, {"jojo", "ba"}}, {11, false, {"jojo", "ba"}}, {12, false, {"jojo", "ba"}}
	};
	
/*  Description ---------------------------------------------------------------*/
	puts("The Colossus Airlines.");
	puts("The program is used for seating reservation.");
	
/*  Code ----------------------------------------------------------------------*/
	
	while ( 'f' != (ch = seat_assignment_menu()) )
	{
		switch (ch)
		{
		case 'a' :
			show_number_of_empty_seats(airplane_one, NUM_OF_SEATS);
			break;
		case 'b' :
			show_list_of_empty_seats(airplane_one, NUM_OF_SEATS);
			break;
		case 'c' :
			show_alphabetical_list_of_seats(airplane_one, NUM_OF_SEATS);
			break;
		case 'd' :
			assign_a_customer_to_a_seat_assignment(airplane_one);
			break;
		default :
			delete_a_seat_assignment(airplane_one);
		} 
	}

/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

char seat_assignment_menu(void)
{
	char ch;

	puts("\n-------------------------------------------------------------------------------");
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats         d) Assign a customer to a seat assignment");
	puts("b) Show list of empty seats           e) Delete a seat assignment");
	puts("c) Show alphabetical list of seats    f) Quit");
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

void show_alphabetical_list_of_seats(seat_t * pt_airplane, int num)
{
	int i;
	puts("Here is the alphabetical list of seats:");

	for (i = 1; i <= num; i++)
	{
		printf("%2d", (pt_airplane + i - 1)->id_number);
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

int assign_a_customer_to_a_seat_assignment(seat_t * pt_airplane)
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

	if ( !((pt_airplane + temp - 1)->assigned) )
	{
		(pt_airplane + temp - 1)->assigned = true;
		printf("The seat %d has been assigned successfully.", temp);
	}
	else
	{
		puts("The place is already assigned.");
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
		printf("The assignment of seat %d has been deleted successfully.", temp);
	}
	else
	{
		puts("The place is not assigned.");
		return 0;
	}
	return 1;
}