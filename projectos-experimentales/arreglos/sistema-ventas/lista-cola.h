#pragma once
#include "Cliente.h"

class ListaCola {
private:
    int capacidadMaxima;
    Cliente* cola;
    int frente;
    int final;

public:
    ListaCola(int capacidad);
    ~ListaCola();
    int Encolar(const std::string& nombre, const std::string& dni, int cantidadEntradas);
    void Atender();
};
