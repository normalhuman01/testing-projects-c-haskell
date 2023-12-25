#include "independiente.h"
#include <iostream>
#include "lista_cola.h"

int main() {
    ListaCola cola(5);

    int resultadoEncolar1 = cola.Encolar("Juler ", "12345678A", 2);
    int resultadoEncolar2 = cola.Encolar("Hernan Quintana", "12345678B", 3);
    if (resultadoEncolar1 >= 0) {
        std::cout << "Posiciones que le faltan: " << resultadoEncolar1 << std::endl;
    } else {
        std::cout << "No se pudo encolar al cliente 1." << std::endl;
    }
    if (resultadoEncolar2 >= 0) {
        std::cout << "Posiciones que le faltan: " << resultadoEncolar2 << std::endl;
    } else {
        std::cout << "No se pudo encolar al cliente 2." << std::endl;
    }
    std::cout << "Atendiendo al primer cliente en la cola:" << std::endl;
    cola.Atender();

    std::cout << "Atendiendo al siguiente cliente en la cola:" << std::endl;
    cola.Atender();

    return 0;
}
