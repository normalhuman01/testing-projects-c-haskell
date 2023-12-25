#pragma once
#include "cliente.h"

class ListaCola {
public:
    ListaCola(int capacidadMaxima);
    int Encolar(const char* nombre, const char* dni, int cantidadEntradas);
    void Atender();
    int getCantidadClientes() const;  // Declaración de getCantidadClientes
    Cliente* desencolar();             // Declaración de desencolar
    int getCapacidadMaxima() const;    // Declaración de getCapacidadMaxima
    void insertarEnPosicion(Cliente* cliente, int posicion); // Declaración de insertarEnPosicion
    void intercambiarPosiciones(int i, int j); // Declaración de intercambiarPosiciones

private:
    int capacidadMaxima;
    Cliente* cola;
    int inicio;
    int fin;
    int cantidadClientes;
};
