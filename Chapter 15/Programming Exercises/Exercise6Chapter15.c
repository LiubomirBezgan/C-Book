//  The FONT I - Exercise6Chapter15.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

#define AL_L 0x0
#define AL_C 0x1
#define AL_R 0x2

const char * al_options[] = {"left", "center", "right"};

struct font_par {
	unsigned int font_id	: 8;
	unsigned int font_size	: 7;
	unsigned int 			: 1;
	unsigned int alignment	: 2;
	bool         bold		: 1;
	bool         italic		: 1;
	bool         underline	: 1;
	unsigned int 			: 3;				
};

void show_font_par(struct font_par * pt_font_par);
char font_menu (void);
bool conversion(char option, struct font_par * pt_font_par);
void set_font_id(struct font_par * pt_font_par);
void set_font_size(struct font_par * pt_font_par);
void set_alignment(struct font_par * pt_font_par);
void set_bold(struct font_par * pt_font_par);
void set_italic(struct font_par * pt_font_par);
void set_underline(struct font_par * pt_font_par);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	struct font_par my_font = {0, 0, AL_C, false, false, false};
	char option;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to set the parameters of font.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("The default font parameters set:");
	show_font_par(&my_font);
	option = font_menu();
	while (!conversion(option, &my_font))
	{
		show_font_par(&my_font);
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

void show_font_par(struct font_par * pt_font_par)
{
	puts(" ID    SIZE    ALIGNMENT    B    I    U");
	printf("%3d    %4d     %6s     ", pt_font_par->font_id, pt_font_par->font_size, al_options[pt_font_par->alignment]);
	printf("%-3s  %-3s  %-3s\n", pt_font_par->bold ? "on" : "off", pt_font_par->italic ? "on" : "off", pt_font_par->underline ? "on" : "off");
}

bool conversion(char option, struct font_par * pt_font_par)
{
	bool end = false;
	switch(option)
	{
	case 'f' : set_font_id(pt_font_par); break;
	case 's' : set_font_size(pt_font_par); break;
	case 'a' : set_alignment(pt_font_par); break;
	case 'b' : set_bold(pt_font_par); break;
	case 'i' : set_italic(pt_font_par); break;
	case 'u' : set_underline(pt_font_par); break;
	default : end = true;
	}
	return end;
}

void set_font_id(struct font_par * pt_font_par)
{
	int id;

	printf("%s", "Enter font ID (0-255): ");
	while ( (1 != scanf("%d", &id)) || (id > 255) || (id < 0) )
	{
		clear_buffer();
		printf("%s", "Incorrect value. Enter font ID (0-255): ");
	}
	clear_buffer();
	pt_font_par->font_id = id;
}

void set_font_size(struct font_par * pt_font_par)
{
	int size;

	printf("%s", "Enter font size (0-127): ");
	while ( (1 != scanf("%d", &size)) || (size > 127) || (size < 0) )
	{
		clear_buffer();
		printf("%s", "Incorrect value. Enter font size (0-127): ");
	}
	clear_buffer();
	pt_font_par->font_size = size;
}

void set_alignment(struct font_par * pt_font_par)
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
	switch(choice_al)
	{
	case 'l' : pt_font_par->alignment = AL_L; break;
	case 'c' : pt_font_par->alignment = AL_C; break;
	default : pt_font_par->alignment = AL_R;		
	}
}

void set_bold(struct font_par * pt_font_par)
{
	pt_font_par->bold = !(pt_font_par->bold);
}

void set_italic(struct font_par * pt_font_par)
{
	pt_font_par->italic = !(pt_font_par->italic);
}

void set_underline(struct font_par * pt_font_par)
{
	pt_font_par->underline = !(pt_font_par->underline);
}