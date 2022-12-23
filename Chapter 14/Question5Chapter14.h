// Question5Chapter14.h
// v1.0
#include <stdio.h>
#define MIESIACE 12

struct miesiac {
	char nazwa[12];
	char skrot[4];
	unsigned char dni;
	unsigned char numer; 
};


struct miesiac rok[MIESIACE] = {
	{"Styczen", "st", 31, 1},
	{"Luty", "lut", 28, 2},
	{"Marzec", "mrz", 31, 3},
	{"Kwiecien", "kw", 30, 4},
	{"Maj", "maj", 31, 5},
	{"Czerwiec", "cz", 30, 6},
	{"Lipiec", "lip", 31, 7},
	{"Sierpien", "sie", 31, 8},
	{"Wrzesien", "wrz", 30, 9},
	{"Pazdziernik", "paz", 31, 10},
	{"Listopad", "lis", 30, 11},
	{"Grudzien", "gr", 31, 12},
};