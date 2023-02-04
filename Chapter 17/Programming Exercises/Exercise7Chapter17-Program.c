//  The Word Frequency Counter - Exercise7Chapter17-Program.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

// protototypes for local functions
bool fill_tree_from_file(Tree_t * ptree, char * file_name);
char word_tree_menu(void);
char my_getchar(void);
void show_word_list(Tree_t * ptree);
void show_occurrences_num(Tree_t * ptree);

void print_word_list(Item_t item);

// description
int main(void)
{
	char ch;
	Tree_t word_tree;
	char * f_name = "Abstract.txt";

	// description
	puts("The Word Frequency Counter");

	// initialization
	InitializeTree(&word_tree);

	// gather from a file and store
	if (fill_tree_from_file(&word_tree, f_name))
	{
		printf("%s has been analyzed successfully.", f_name);
	}
	else
	{
		puts("Something's gone wrong!");
		exit(EXIT_FAILURE);
	}

	// main loop
	while ( 'c' != (ch = word_tree_menu()) )
	{
		switch (ch)
		{
		case 'a' :
			show_word_list(&word_tree);
			break;
		default :
			show_occurrences_num(&word_tree);
		}
	}

	DeleteAll(&word_tree);
	puts("Thank you and goodbye.");
	return 0;
}

bool fill_tree_from_file(Tree_t * ptree, char * file_name)
{
	FILE * fp;
	Item_t temp;
	bool result = true;

	if ( (fp = fopen(file_name, "r")) == NULL )
	{
		fprintf(stderr, "Can't open file %s.\n", file_name);
		result = false;			
	}
	while (1 == fscanf(fp, "%s", temp.word))
	{
		temp.occurrences = 1;
		AddItem(&temp, ptree);
	}
	if (0 != fclose(fp))
	{
		fprintf(stderr, "Error in closing file %s.\n", file_name);
		result = false;
	}
	return result;
}

char word_tree_menu(void)
{
	char ch;

	puts("\n-------------------------------------------------------------------------------");
	puts("To choose a function, enter its letter label:");
	puts("a) List all the words along with the number of occurrences,");
	puts("b) Show how many times the word occurred in the file,");
	puts("c) Quit");
	puts("-------------------------------------------------------------------------------");

	while ( ( (ch = my_getchar()) < 'a' ) || (ch > 'c') )
	{
		puts("Please enter a letter from a to c:");
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

void show_word_list(Tree_t * ptree)
{
	Traverse(ptree, print_word_list);
}

void show_occurrences_num(Tree_t * ptree)
{
	Item_t look;

	puts("Please enter a word:");
	while (1 != scanf("%s", look.word))
	{
		while (getchar() != '\n')
		{
        	continue;
		}
		puts("Try again. Please enter a word:");
	}
	while (getchar() != '\n')
	{
        continue;
	}
	if (InTree(&look, ptree))
	{
		print_word_list(SeekItem(&look, ptree).child->item);
	}
	else
	{
		puts("There is no such word.");
	}
}

void print_word_list(Item_t item)
{
	printf("%3d - %s\n", item.occurrences, item.word);
}