#include <stdlib.h>

typedef struct
{
	int wiersze, kolumny;
	float* elementy;
} macierz;

macierz nowa(int wiersze, int kolumny)
{
	return { wiersze, kolumny, (float*)calloc(wiersze * kolumny, sizeof(float)) };
}

void wypisz(macierz m)
{

}

macierz mnozenie(macierz A, macierz B)
{

}

void main()
{
	macierz m = nowa(10, 10);
	free(m.elementy);
}