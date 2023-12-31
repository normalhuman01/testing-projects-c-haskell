#include <stdio.h>
#include <string.h>
#include "busqueda_patron_kmp.h"
#include "busqueda_patron_kmp_variante.h"
#include "busqueda_patron_boyermoore.h"

int main()
{
    char texto[1000];
    char patron[100];

    printf("Ingrese el texto: ");
    scanf("%s", texto);

    printf("Ingrese el patrón: ");
    scanf("%s", patron);

    printf("\nUsando el algoritmo KMP:\n");
    algoritmokpm(texto, patron);

    printf("\nUsando el algoritmo KMP Variante:\n");
    algoritmokpm_variante(texto, patron);

    printf("\nUsando el algoritmo Boyer-Moore:\n");
    buscar(texto, patron);

    return 0;
}
