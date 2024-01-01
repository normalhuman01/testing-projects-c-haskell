#include <limits.h>
#include <string.h>
#include <stdio.h>

#define NO_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

void heuristicaCaracterIncorrecto(char *cadena, int tamaño, int malcaracter[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        malcaracter[i] = -1;

    for (i = 0; i < tamaño; i++)
        malcaracter[(int)cadena[i]] = i;
}

void buscar(char *texto, char *patron)
{
    int m = strlen(patron);
    int n = strlen(texto);

    int malcaracter[NO_OF_CHARS];
    heuristicaCaracterIncorrecto(patron, m, malcaracter);
    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && patron[j] == texto[s + j])
            j--;

        if (j < 0)
        {
            printf("\nEl patrón ocurre en el desplazamiento = %d", s);
            s += (s + m < n) ? m - malcaracter[texto[s + m]] : 1;
        }
        else
            s += max(1, j - malcaracter[texto[s + j]]);
    }
}
