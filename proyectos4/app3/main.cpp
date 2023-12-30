// main.cpp

#include <iostream>
#include <vector>
#include "ProblemasPrevios.h"

int main() {
    // Problema 1: Problemas previos dejados en BB como parte 1 de la presente nota.

    std::vector<int> problemasPrevios = {1, 2, 3, 4, 5};

    // Utiliza la función declarada en el archivo de encabezado
    int suma = ProblemasPrevios::sumaProblemas(problemasPrevios);

    std::cout << "La suma de los problemas previos es: " << suma << std::endl;

    return 0;
}
