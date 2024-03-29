// definiuje i korzysta z pol
#include <stdio.h>
#include <stdbool.h>

// style linii
#define CIAGLA 0
#define KROPKI 1
#define KRESKI 2

// barwy podstawowe
#define NIEB 4
#define ZIEL 2
#define CZER 1

// barwy mieszane
#define CZARNY 0
#define ZOLTY (CZER | ZIEL)
#define FIOLET (CZER | NIEB)
#define ZIELNIEB (ZIEL | NIEB)
#define BIALY (CZER | ZIEL | NIEB)

const char * kolory[8] = {"czary", "czerwony", "zielony", "zolty", "niebieski", "fioletowy", "zielono-niebieski", "bialy"};

struct wl_okna {
	bool			przezrocz	: 1;
	unsigned int	kolor_wyp	: 3;
	unsigned int				: 4;
	bool			wid_ramki	: 1;
	unsigned int	kolor_ramki	: 3;
	unsigned int	styl_ramki	: 2;
	unsigned int				: 2;	
};

void pokaz_ustawienia(const struct wl_okna * pb);

int main(void)
{
	// tworzy i inicjalizuje strukture typu wl_okna
	struct wl_okna okno = {true, ZOLTY, true, ZIEL, KRESKI};
	puts("Pierwotne ustawienia ramki okna:");
	pokaz_ustawienia(&okno);
	okno.przezrocz = false;
	okno.kolor_wyp = BIALY;
	okno.kolor_ramki = FIOLET;
	okno.styl_ramki = CIAGLA;
	puts("\nPo dokonaniu zmian ustawien okna:");
	pokaz_ustawienia(&okno);

	return 0;
}

void pokaz_ustawienia(const struct wl_okna * pb)
{
	printf("Okno jest %s.\n", pb->przezrocz == true ? "przezroczyste" : "nieprzezroczyste");
	printf("Kolorem wypelnienia jest %s.\n", kolory[pb->kolor_wyp]);
	printf("Ramka jest %s.\n", pb->wid_ramki == true ? "widoczna" : "niewidoczna");
	printf("Kolorem ramki jest %s.\n", kolory[pb->kolor_ramki]);
	printf("Ramka jest narysowana linia ");
	switch(pb->styl_ramki)
	{
	case CIAGLA : printf("ciagla.\n"); break;
	case KROPKI : printf("wykropkowana.\n"); break;
	case KRESKI : printf("kreskowana.\n"); break;
	default 	: printf("nieznanego typu.\n");
	}
}