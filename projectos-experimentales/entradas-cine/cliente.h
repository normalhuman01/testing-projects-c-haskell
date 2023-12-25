#pragma once

class Cliente {
public:
    char nombre[50];
    char dni[10];
    int cantidadEntradas;

    Cliente() : cantidadEntradas(0) {
    }

    Cliente(const char* nombre, const char* dni, int cantidadEntradas);
};
