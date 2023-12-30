#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Problema 1: Problemas previos dejados en BB como parte 1 de la presente nota.

    // Supongamos que tienes una lista de problemas previos en Blackboard (BB).
    std::vector<int> problemasPrevios = {1, 2, 3, 4, 5};

    // Queremos encontrar la suma de los problemas previos.
    int suma = std::accumulate(problemasPrevios.begin(), problemasPrevios.end(), 0);

    // Imprimir la suma de los problemas previos.
    std::cout << "La suma de los problemas previos es: " << suma << std::endl;

    return 0;
}
