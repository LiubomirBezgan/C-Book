//  multiple book inventory - Exercise3Chapter14.c
//  v1.0
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100                      // maximum number of books

struct book {                           // set up book template
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void str_srt(struct book *library[], int num);

int main(void)
{
    struct book library[MAXBKS];       // array of book structures
    struct book * ptlibrary[MAXBKS];    // array of pointer variables
    int count = 0;                      // input count
    int index;
    float total_value = 0.0;
    puts("Please enter the book title.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        gets(library[count].author);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
        {
            continue;                   // clear input line
        }
        ptlibrary[count] = &library[count];
        total_value += library[count++].value;
        if (count < MAXBKS)
        {
            puts("\nEnter the next title.");
        }
    }
    if (count > 0)
    {
        str_srt(ptlibrary, count);
        puts("Here is the list of your books sorted by title:");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", ptlibrary[index]->title, ptlibrary[index]->author, ptlibrary[index]->value);
        }
        printf("The total value of given books is $%.2f\n", total_value);
    }
    else
    {
        puts("No books? Too bad.");
    }
    return 0;
}


void str_srt(struct book *library[], int num)
{
    struct book *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if (strcmp(library[top]->title, library[seek]->title) > 0) 
            {
                temp = library[top];
                library[top] = library[seek];
                library[seek] = temp;
            }
        }
    }
}