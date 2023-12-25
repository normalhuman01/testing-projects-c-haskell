#include "lista_cola.h"
#include "cliente.h"
#include <iostream>

ListaCola::ListaCola(int capacidadMaxima) {
    this->capacidadMaxima = capacidadMaxima;
    this->cola = new Cliente[capacidadMaxima];
    this->inicio = 0;
    this->fin = -1;
    this->cantidadClientes = 0;
}

int ListaCola::Encolar(const char* nombre, const char* dni, int cantidadEntradas) {
    if (cantidadClientes >= capacidadMaxima) {
        return -1; // La cola está llena
    }

    fin = (fin + 1) % capacidadMaxima;
    Cliente nuevoCliente(nombre, dni, cantidadEntradas);
    cola[fin] = nuevoCliente;
    cantidadClientes++;

    return (capacidadMaxima - cantidadClientes);
}

void ListaCola::Atender() {
    if (cantidadClientes == 0) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    Cliente clienteAtendido = cola[inicio];
    std::cout << "Nombre: " << clienteAtendido.nombre << std::endl;
    std::cout << "DNI: " << clienteAtendido.dni << std::endl;
    std::cout << "Cantidad de entradas: " << clienteAtendido.cantidadEntradas << std::endl;

    inicio = (inicio + 1) % capacidadMaxima;
    cantidadClientes--;
}
int ListaCola::getCantidadClientes() const {
    return cantidadClientes;
}

Cliente* ListaCola::desencolar() {
    if (cantidadClientes == 0) {
        return nullptr;
    }

    Cliente* clienteSacado = &cola[inicio];
    inicio = (inicio + 1) % capacidadMaxima;
    cantidadClientes--;

    return clienteSacado;
}

int ListaCola::getCapacidadMaxima() const {
    return capacidadMaxima;
}

void ListaCola::insertarEnPosicion(Cliente* cliente, int posicion) {
    if (posicion < 0 || posicion > cantidadClientes) {
        std::cout << "Posición no válida." << std::endl;
        return;
    }

    if (cantidadClientes >= capacidadMaxima) {
        std::cout << "La cola está llena, no se puede insertar." << std::endl;
        return;
    }

    int index = (inicio + posicion) % capacidadMaxima;

    for (int i = cantidadClientes; i > posicion; i--) {
        int prevIndex = (inicio + i - 1) % capacidadMaxima;
        cola[(prevIndex + 1) % capacidadMaxima] = cola[prevIndex];
    }

    cola[index] = *cliente;
    fin = (fin + 1) % capacidadMaxima;
    cantidadClientes++;
}

void ListaCola::intercambiarPosiciones(int i, int j) {
    if (i < 0 || i >= cantidadClientes || j < 0 || j >= cantidadClientes) {
        std::cout << "Posiciones no válidas." << std::endl;
        return;
    }

    int indexI = (inicio + i) % capacidadMaxima;
    int indexJ = (inicio + j) % capacidadMaxima;

    Cliente temp = cola[indexI];
    cola[indexI] = cola[indexJ];
    cola[indexJ] = temp;
}
