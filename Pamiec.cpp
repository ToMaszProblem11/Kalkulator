#include <stdlib.h>
#include <stdio.h>

float* macierz_losowa(int wiersze, int kolumny)
{
	float* m = (float*)calloc(wiersze * kolumny, sizeof(float));
	for (int i = 0; i < wiersze * kolumny; i++)
		m[i] = (rand() % 10) - 5;
	return m;
}

void wypisz_macierz(float* elementy, int wiersze, int kolumny)
{
	for (int w = 0; w < wiersze; w++)
	{
		for (int k = 0; k < kolumny; k++)
			printf("%.3f, ", elementy[w * kolumny + k]);
		printf("\n");
	}
}

float* mnozenie(float* A, int wierszeA, int kolumnyA, float* B, int wierszeB, int kolumnyB)
{
	if (kolumnyA != wierszeB)
		return NULL;
	float *wynik = (float*)calloc(wierszeA * kolumnyB, sizeof(float));
	// Mnozenie
	for(int w = 0; w < wierszeA; w++)
		for (int k = 0; k < kolumnyB; k++)
		{
			float suma = 0;
			for (int i = 0; i < kolumnyA; i++)
				suma += A[w * kolumnyA + i] * B[i * kolumnyB + k];
			wynik[w * kolumnyB + k] = suma;
		}
	// Zwrto wyniku
	return wynik;
}

void main()
{
	srand(89476);
	float *A = macierz_losowa(2, 5), *B = macierz_losowa(5, 2), *wynik;

	wypisz_macierz(A, 2, 5);
	printf("\n");
	wypisz_macierz(B, 5, 2);
	printf("\n");
	wynik = mnozenie(A, 2, 5, B, 5, 2);
	wypisz_macierz(wynik, 2, 2);

	free(A);
	free(B);
	free(wynik);
}