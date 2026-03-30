#include <stdio.h>
#include <string.h>

typedef struct
{
	char imie[10], nazwisko[20];
	int rok_urodzenia;
	float srednia;
} student;

student zmiencos(student s)
{
	s.rok_urodzenia += 100;
	return s;
}

void main()
{
	student s, x = { "Tadek", "Niejadek", 2007, 3.08 };
	strcpy_s(s.imie, 10, "Bronek");
	strcpy_s(s.nazwisko, 20, "Skowronek");
	s.srednia = 2.54;
	s.rok_urodzenia = 2005;
	
	printf("%s %s urodzil sie w %d roku i ma srednia %.2f\n", s.imie, s.nazwisko, s.rok_urodzenia, s.srednia);
	x = zmiencos(x);
	printf("%s %s urodzil sie w %d roku i ma srednia %.2f\n", x.imie, x.nazwisko, x.rok_urodzenia, x.srednia);
}