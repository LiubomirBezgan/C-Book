// rand0.c - generuje liczby losowe stosujac przenosny algorytm ANSI C - Listing_12_7
static unsigned long int nast = 1;		// ziarno (ang. seed)
int rand0(void)
{
	nast = nast * 1103515245 + 12345;
	return (unsigned int) (nast / 65536) % 32768;
}