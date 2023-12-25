#include "ListaCola.h"
#include <iostream>

ListaCola::ListaCola(int capacidad)
    : capacidadMaxima(capacidad), frente(0), final(0) {
    cola = new Cliente[capacidadMaxima];
}

ListaCola::~ListaCola() {
    delete[] cola;
}

int ListaCola::Encolar(const std::string& nombre, const std::string& dni, int cantidadEntradas) {
    if (final < capacidadMaxima) {
        cola[final] = Cliente(nombre, dni, cantidadEntradas);
        final++;
        return capacidadMaxima - final;
    } else {
        return -1;
    }
}

void ListaCola::Atender() {
    if (frente < final) {
        std::cout << "Cliente: " << cola[frente].nombre << std::endl;
        std::cout << "DNI: " << cola[frente].dni << std::endl;
        std::cout << "Cantidad de entradas: " << cola[frente].cantidadEntradas << std::endl;
        frente++;
    } else {
        std::cout << "La cola está vacía." << std::endl;
    }
}
