#pragma once
#include <string>

class Cliente {
public:
    std::string nombre;
    std::string dni;
    int cantidadEntradas;

    Cliente(const std::string& nombre, const std::string& dni, int cantidadEntradas);
};
