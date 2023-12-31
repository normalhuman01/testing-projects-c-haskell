#include <stdio.h>
#include <string.h>

void calcularlps(char *patron, int longitud, int *arreglo)
{
    int longitud1 = 0;
    int i = 1;
    arreglo[0] = 0;

    while (i < longitud)
    {
        if (patron[i] == patron[longitud1])
        {
            longitud1++;
            arreglo[i] = longitud1;
            i++;
        }
        else
        {
            if (longitud1 != 0)
            {
                longitud1 = arreglo[longitud1 - 1];
            }
            else
            {
                arreglo[i] = 0;
                i++;
            }
        }
    }
}

void algoritmokpm(char *text, char *patron)
{
    int n = strlen(text);
    int longitud = strlen(patron);

    int arreglo[longitud];
    calcularlps(patron, longitud, arreglo);
    int t = 0;
    int p = 0;

    while (t < n)
    {
        if (patron[p] == text[t])
        {
            t++;
            p++;
        }

        if (p == longitud)
        {
            printf("indice: %d\n", t - p);
            p = arreglo[p - 1];
        }
        else if (t < n && patron[p] != text[t])
        {
            if (p != 0)
            {
                p = arreglo[p - 1];
            }
            else
            {
                t++;
            }
        }
    }
}
