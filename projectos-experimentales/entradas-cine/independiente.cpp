#include "independiente.h"
#include <iostream>

Cliente* pregunta3(ListaCola* listaCola) {
    if (listaCola->getCantidadClientes() == 0) {
        return nullptr; // La cola está vacía
    }

    Cliente* clienteSacado = listaCola->desencolar();

    return clienteSacado;
}

void pregunta4(ListaCola* listaCola, Cliente* cliente, int posicion) {
    if (posicion < 0 || posicion > listaCola->getCantidadClientes()) {
        std::cout << "Posición no válida." << std::endl;
        return;
    }

    if (listaCola->getCantidadClientes() >= listaCola->getCapacidadMaxima()) {
        std::cout << "La cola está llena, no se puede insertar." << std::endl;
        return;
    }

    listaCola->insertarEnPosicion(cliente, posicion);
}

void pregunta5(ListaCola* listaCola, int i, int j) {
    if (i < 0 || i >= listaCola->getCantidadClientes() || j < 0 || j >= listaCola->getCantidadClientes()) {
        std::cout << "Posiciones no válidas." << std::endl;
        return;
    }

    listaCola->intercambiarPosiciones(i, j);
}
