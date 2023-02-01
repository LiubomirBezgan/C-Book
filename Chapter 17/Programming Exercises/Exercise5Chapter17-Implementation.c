// Exercise5Chapter17-Implementation.c - implementacja typu "stos"
#include "stos.h"

void InicjujStos(Stos * ws)
{
	ws->gora = 0;
}

bool PustyStos(const Stos * ws)
{
	if (0 == ws->gora)
	{
		return true;
	}
	else
	{
		return false;
	}					
}

bool PelnyStos(const Stos * ws)
{
	if (MAXSTOS == ws->gora)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LiczbaPozycji(const Stos * ws)
{
	return ws->gora;
}

bool Poloz(Pozycja pozycja, Stos * ws)
{
	if (!PelnyStos(ws))
	{
		ws->pozycje[ws->gora] = pozycja;
		ws->gora++;
		return true;

	}
	else
	{
		return false;
	}
}

bool Zdejmij(Pozycja *wpozycja, Stos * ws)
{
	if (!PustyStos(ws))
	{
		*wpozycja = ws->pozycje[ws->gora - 1];
		ws->gora--;
		return true;
	}
	else
	{
		return false;
	}
}