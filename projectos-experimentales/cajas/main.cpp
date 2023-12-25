#include <iostream>
#include "Caja.h"  // Incluye solo Caja.h, no Producto.h

int main() {
    Caja caja1(1000, 500); // capacidad y peso
    Producto prod1(200, 10); // volumen y peso

    if (caja1.agregarObjeto(prod1)) {
        std::cout << "Producto agregado a la caja." << std::endl;
    } else {
        std::cout << "No se pudo agregar el producto a la caja." << std::endl;
    }

    std::cout << "Peso total de la caja: " << caja1.calcularPeso() << " kg." << std::endl;

    return 0;
}
