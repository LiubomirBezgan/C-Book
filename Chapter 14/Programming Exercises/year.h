//  year.h
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MONTHS 12
#define NAME_LEN 10
#define SHORT_FROM_LEN 4

int days(char * month_name);

struct month {
	char name[NAME_LEN];
	char short_form[SHORT_FROM_LEN];
	unsigned char days;
	unsigned char number; 
};

struct month year[MONTHS] = {
	{"january", "jan", 31, 1},
	{"february", "feb", 28, 2},
	{"march", "mar", 31, 3},
	{"april", "apr", 30, 4},
	{"may", "may", 31, 5},
	{"june", "jun", 30, 6},
	{"july", "jul", 31, 7},
	{"august", "aug", 31, 8},
	{"september", "sep", 30, 9},
	{"october", "oct", 31, 10},
	{"november", "nov", 30, 11},
	{"december", "dec", 31, 12},
};