// pola i operatory bitowe
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// STLE DLA POL BITOWYCH
// style linii
#define CIAGLA	0
#define KROPKI	1
#define KRESKI	2

// barwy podstawowe
#define NIEB	4
#define ZIEL	2
#define CZER	1

// barwy mieszane
#define CZARNY		0
#define ZOLTY		(CZER | ZIEL)
#define FIOLET		(CZER | NIEB)
#define ZIELNIEB	(ZIEL | NIEB)
#define BIALY		(CZER | ZIEL | NIEB)

// STALE DLA OPERATOROW BITOWYCH
#define PRZEZR 				0x1
#define WYP_NIEB 			0x8
#define WYP_ZIEL 			0x4
#define WYP_CZER 			0x2
#define WYP_MASKA 			0xE
#define RAMKA	 			0x100
#define RAMKA_NIEB	 		0x800
#define RAMKA_ZIEL	 		0x400
#define RAMKA_CZER	 		0x200
#define RAMKA_MASKA	 		0xE00
#define R_CIAGLA			0x0000
#define R_KROPKI			0x1000
#define R_KRESKI			0x2000
#define STYL_MASKA			0x3000

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

union Widoki
{
	struct wl_okna widok_st;
	unsigned short widok_sh;
};

void wyswietl(const struct wl_okna * wsk_ok);
void wyswietl1(unsigned short);
char * int_do_binar(int n, char * wl);

int main(void)
{
	// tworzy unie okno typu Widoki i inicjalizuje ja korzystajac ze struktury
	union Widoki okno = {{false, ZOLTY, true, ZIEL, KRESKI}};
	char bin_lan[8 * sizeof(int) + 1];

	puts("Poczatkowe ustawienia okna:");
	wyswietl(&okno.widok_st);
	puts("\nUstawienia okna w postaci unsigned short:");
	wyswietl1(okno.widok_sh);
	printf("Uklad bitow jest nastepujacy: %s\n", int_do_binar(okno.widok_sh, bin_lan));

	okno.widok_sh &= ~WYP_MASKA;				// czysci bity wypelnienia
	okno.widok_sh |= (WYP_NIEB | WYP_ZIEL);		// ustawia wypelnienie
	okno.widok_sh ^= PRZEZR;					// przelacza przezroczystosc
	okno.widok_sh |= RAMKA_CZER;				// zle podejscie
	okno.widok_sh &= ~STYL_MASKA;				// czysci bity stylu
	okno.widok_sh |= R_KROPKI;					// wstawia styl ramki

	puts("\nPo dokonaniu zmian:");
	wyswietl(&okno.widok_st);
	puts("\nUstawienia okna w postaci unsigned short:");
	wyswietl1(okno.widok_sh);
	printf("Uklad bitow jest nastepujacy: %s\n", int_do_binar(okno.widok_sh, bin_lan));
	return 0;
}

void wyswietl(const struct wl_okna * okno)
{
	printf("Okno jest %s.\n", okno->przezrocz == true ? "przezroczyste" : "nieprzezroczyste");
	printf("Kolorem wypelnienia jest %s.\n", kolory[okno->kolor_wyp]);
	printf("Ramka jest %s.\n", okno->wid_ramki == true ? "widoczna" : "niewidoczna");
	printf("Ramka jest narysowana linia ");
	switch(okno->styl_ramki)
	{
		case CIAGLA : printf("ciagla.\n"); break;
		case KROPKI : printf("wykropkowana.\n"); break;
		case KRESKI : printf("kreskowana.\n"); break;
		default : printf("nieznanego typu.\n");
	}
	printf("Kolorem ramki jest %s.\n", kolory[okno->kolor_ramki]);
}

void wyswietl1(const unsigned short us)
{
	printf("Okno jest %s.\n", (us & PRZEZR) == PRZEZR ? "przezroczyste" : "nieprzezroczyste");
	printf("Kolorem wypelnienia jest %s.\n", kolory[(us >> 1) & 07]);
	printf("Ramka jest %s.\n", (us & RAMKA) == RAMKA ? "widoczna" : "niewidoczna");
	printf("Ramka jest narysowana linia ");
	switch(us & STYL_MASKA)
	{
		case R_CIAGLA : printf("ciagla.\n"); break;
		case R_KROPKI : printf("wykropkowana.\n"); break;
		case R_KRESKI : printf("kreskowana.\n"); break;
		default : printf("nieznanego typu.\n");
	}
	printf("Kolorem ramki jest %s.\n", kolory [(us >> 9) & 07]);
}

char * int_do_binar(int n, char * wl)
{
	int i;
	static int rozmiar = CHAR_BIT * sizeof(unsigned int);
	for (i = rozmiar - 1; i >= 0; i--, n >>= 1)
	{
		wl[i] = (01 & n) + '0';
	}
	wl[rozmiar] = '\0';
	return wl;
}