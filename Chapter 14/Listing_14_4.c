//  wykorzystuje wskaznik do struktur - Listing_14_4.c
//  v1.0
#include <stdio.h>
#define DL 20

struct daneos {					// pierwszy szablon
	char imie[DL];
	char nazw[DL];
};

struct facet {					// drugi szablon
	struct daneos person;		// struktura zagniezdzona
	char ulub_jedz[DL];
	char zawod[DL];
	float dochody;
};

int main(void)
{
	struct facet gosc[2] = {
		{{ "Chip", "Hyperlink" },
		"talerz chipsow",
		"trener osobisty",
		36827.00
		},
		{{"Norbert", "Brzuchacz"},
		"mus lososiowy",
		"redaktor brukowca",
		148500.00
		}
	};
	struct facet * on;			// oto wskaznik do struktury
	printf("adres #1: %p #2: %p\n", on, on + 1);
	on = &gosc[0];				// ustawia wskaznik;
	printf("wskaznik #1: %p #2: %p\n", on, on + 1);
	printf("on->dochody ma wartosc %0.2f $:  (*on).dochody ma wartosc %0.2f $\n", on->dochody, (*on).dochody);
	on++;						// wskazuje na nastepna strukture
	printf("on->ulub_jedz ma wartosc %s $:  on->person.nazw ma wartosc %s\n", on->ulub_jedz, on->person.nazw);
	return 0;
}