#include <stdio.h>

#define KROK 1 // Zmienione na 1, bo funkcja wypisuje 3 spacje naraz

void spacja(int poziom)
{
    // DODANO: 'int' przed i
    for (int i = 0; i < poziom; i++)
    {
        printf("   "); 
    }
}

int main() 
{
    int znak = 0;
    int poziom = 0;

    while ((znak = getchar()) != -1) 
    {
        // 1. Obsługa klamry otwierającej
        if (znak == '{') {
            printf("\n");
            spacja(poziom);
            printf("{\n");
            poziom += KROK;
            spacja(poziom);
            continue;
        }

        // 2. Obsługa klamry zamykającej
        if (znak == '}') 
        {
            poziom -= KROK; // Zmniejszamy poziom przed wypisaniem klamry
            if (poziom < 0) poziom = 0;
            printf("\n");
            spacja(poziom);
            printf("}\n");
            spacja(poziom);
            continue;
        }

        // 3. Obsługa średnika
        if (znak == ';') 
        {
            printf(";\n");
            spacja(poziom);
            continue;
        }

        // 4. Wypisywanie reszty znaków (pomijając stare entery)
        if (znak != '\n' && znak != '\r') {
            printf("%c", znak);
        }
    }
    return 0;
}