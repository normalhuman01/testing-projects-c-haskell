#include "ListaCola.h"
#include <iostream>

int main() {
    ListaCola cola(5); // Capacidad máxima de la cola es 5

    int resultado;
    
    resultado = cola.Encolar("Cliente1", "12345678", 3);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    resultado = cola.Encolar("Cliente2", "98765432", 2);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al primer cliente en la cola

    resultado = cola.Encolar("Cliente3", "56789012", 1);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al siguiente cliente en la cola

    resultado = cola.Encolar("Cliente4", "34567890", 4);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al siguiente cliente en la cola

    resultado = cola.Encolar("Cliente5", "45678901", 2);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al siguiente cliente en la cola

    cola.Atender(); // Atiende al último cliente en la cola

    return 0;
}
