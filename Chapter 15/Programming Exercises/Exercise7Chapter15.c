//  The FONT II - Exercise7Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

#define AL_L 		0x0
#define AL_C 		0x1
#define AL_R 		0x2
#define ID_MASK 	0xFF0000
#define ID_MASK_	0xFF
#define SIZE_MASK 	0xFE00
#define SIZE_MASK_	0x7F
#define AL_MASK 	0xC0
#define AL_MASK_ 	0x3
#define BOLD_MASK 	0x20
#define IT_MASK 	0x10
#define UND_MASK 	0x8

const char * al_options[] = {"left", "center", "right"};

struct font_par {
	unsigned long 			: 8;	
	unsigned long font_id	: 8;
	unsigned long font_size	: 7;
	unsigned long 			: 1;
	unsigned long alignment	: 2;
	bool         bold		: 1;
	bool         italic		: 1;
	bool         underline	: 1;
	unsigned long 			: 3;				
};

union Bitwise_font {
	struct font_par my_font_st;
	unsigned long my_font_int;
};

void show_font_par(unsigned long font_par_int);
char font_menu (void);
bool conversion(char option, unsigned long * font_par_int);
void set_font_id(unsigned long * font_par_int);
void set_font_size(unsigned long * font_par_int);
void set_alignment(unsigned long * font_par_int);
void set_bold(unsigned long * font_par_int);
void set_italic(unsigned long * font_par_int);
void set_underline(unsigned long * font_par_int);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	union Bitwise_font my_font;
	char option;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to set the parameters of font.\n");
	
/*  Code ----------------------------------------------------------------------*/
	my_font.my_font_int = 0xEB28AF;
	puts("The default font parameters set:");
	show_font_par(my_font.my_font_int);
	option = font_menu();
	while (!conversion(option, &(my_font.my_font_int)))
	{
		putchar('\n');
		show_font_par(my_font.my_font_int);
		option = font_menu();
	}


/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

char font_menu (void)
{
	const char * letters = "fsabiuq";
	char choice;
	puts("f) change font    s) change size      a) change alignment");
	puts("b) toggle bold    i) toggle italic    u) toggle underline");
	puts("q) quit");
	scanf("%c", &choice);
	clear_buffer();
	while (NULL == strchr(letters, choice))
	{
		puts("Please enter letter 'f', 's', 'a', 'b', 'i', 'u' or 'q'.");
		scanf("%c", &choice);
		clear_buffer();
	}
	return choice;
}

void show_font_par(unsigned long font_par_int)
{
	puts(" ID    SIZE    ALIGNMENT    B    I    U");
	printf("%3d    %4d     %6s     ", ( (font_par_int >> 16) & ID_MASK_ ), ( (font_par_int >> 9) & SIZE_MASK_ ), al_options[ (font_par_int >> 6) & AL_MASK_ ]);
	printf("%-3s  %-3s  %-3s\n", ( BOLD_MASK == (font_par_int & BOLD_MASK) ) ? "on" : "off", ( IT_MASK ==  (font_par_int & IT_MASK) ) ? "on" : "off", ( UND_MASK ==  (font_par_int & UND_MASK) ) ? "on" : "off");
}

bool conversion(char option, unsigned long * pt_font_par_int)
{
	bool end = false;
	switch(option)
	{
	case 'f' : set_font_id(pt_font_par_int); break;
	case 's' : set_font_size(pt_font_par_int); break;
	case 'a' : set_alignment(pt_font_par_int); break;
	case 'b' : set_bold(pt_font_par_int); break;
	case 'i' : set_italic(pt_font_par_int); break;
	case 'u' : set_underline(pt_font_par_int); break;
	default : end = true;
	}
	return end;
}

void set_font_id(unsigned long * font_par_int)
{
	int id;

	printf("%s", "Enter font ID (0-255): ");
	while ( (1 != scanf("%d", &id)) || (id > 255) || (id < 0) )
	{
		clear_buffer();
		printf("%s", "Incorrect value. Enter font ID (0-255): ");
	}
	clear_buffer();
	
	*font_par_int &= ~ID_MASK;
	*font_par_int |= (id << 16);

}

void set_font_size(unsigned long * font_par_int)
{
	int size;

	printf("%s", "Enter font size (0-127): ");
	while ( (1 != scanf("%d", &size)) || (size > 127) || (size < 0) )
	{
		clear_buffer();
		printf("%s", "Incorrect value. Enter font size (0-127): ");
	}
	clear_buffer();

	*font_par_int &= ~SIZE_MASK;
	*font_par_int |= (size << 9);
}

void set_alignment(unsigned long * font_par_int)
{
	char choice_al;
	const char * letters_al = "lcr";

	puts("Select alignment:");
	puts("l) left    c) center    r) right");
	scanf("%c", &choice_al);
	clear_buffer();
	while (NULL == strchr(letters_al, choice_al))
	{
		puts("Please enter letter 'l', 'c' or 'r'.");
		scanf("%c", &choice_al);
		clear_buffer();
	}
	*font_par_int &= ~AL_MASK;
	switch(choice_al)
	{
	case 'l' : *font_par_int |= (AL_L << 6); break;
	case 'c' : *font_par_int |= (AL_C << 6); break;
	 default : *font_par_int |= (AL_R << 6);		
	}
}

void set_bold(unsigned long * font_par_int)
{
	*font_par_int ^= BOLD_MASK;
}

void set_italic(unsigned long * font_par_int)
{
	*font_par_int ^= IT_MASK;
}

void set_underline(unsigned long * font_par_int)
{
	*font_par_int ^= UND_MASK;
}