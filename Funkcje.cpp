#include<stdio.h>

int silnia(int n)
{
	/*if (n == 0)
		return 1;
	else
		return n * silnia(n - 1);*/

	// <warunek> ? <wartosc jesli spelniony> : <wartosc jesli nie jest spelniony>

	return n ? n * silnia(n - 1) : 1;
}

int dodaj(int a, int b)
{
	return a + b;
}

void zaszyfruj(char* text)
{
	//for (int i = 0; text[i]; i++)
	//	text[i] = text[i] + 1;
	
	//for (int i = 0; *text;)
	//	*text = *text++ + 1;

	while (*text && (*text++)++);
}

void odszyfruj(char* text)
{
	while (*text && (*text++)--);
}

int czy_identyczne(char* txtA, char* txtB)
{
	// return 0 jesli txtA i txtB sa identyczne
	// dowolna inna wartosc w przeciwnym wypadku

	for (; *txtA && *txtB && !(*txtA - *txtB); txtA++, txtB++);
	return !(*txtA - *txtB);
}

char* znajdz(char* txt, const char* poszukiwany)
{
	// wskaznik do wystapienia tekstu "poszukiwany" w tekscie "txt"
	// NULL w przeciwnym wypadku
	for (int i; *txt; txt++)
	{
		for (i = 0; !(txt[i] - poszukiwany[i]); i++);
		if (!poszukiwany[i])
			return txt;
	}
	return NULL;
}

void dodawanie(char* liczbaA, char* liczbaB, char* wynik)
{
	char* qniecA = liczbaA, * qniecB = liczbaB, *poczatekW = wynik;
	while (*++qniecA);
	while (*++qniecB);
	qniecA--; qniecB--;

	if (qniecA - liczbaA < qniecB - liczbaB)
	{
		char* ptr = liczbaA;
		liczbaA = liczbaB;
		liczbaB = ptr;

		ptr = qniecA;
		qniecA = qniecB;
		qniecB = ptr;
	}
	
	int przeniesienie = 0, x;
	for (; (qniecB + 1) != liczbaB;)
	{
		x = *qniecA-- - '0' + *qniecB-- - '0' + przeniesienie;
		*wynik++ = (x % 10) + '0';
		przeniesienie = x / 10;
	}
	for (; (qniecA + 1) != liczbaA;)
	{
		x = *qniecA-- - '0' + przeniesienie;
		*wynik++ = (x % 10) + '0';
		przeniesienie = x / 10;
	}
	if (przeniesienie)
		* wynik++ = przeniesienie + '0';
	*wynik-- = 0;

	for (; poczatekW <= wynik; poczatekW++, wynik--)
	{
		char x = *poczatekW;
		*poczatekW = *wynik;
		*wynik = x;
	}

}

void main()
{
	char lA[] = "999",
		lB[] = "999";
	char wynik[100];

	dodawanie(lA, lB, wynik);
	printf("%s\n", wynik);
}