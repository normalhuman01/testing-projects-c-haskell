#include "Producto.h"

Producto::Producto(double volumen, double peso) : volumen(volumen), peso(peso) {}

double Producto::getVolumen() const {
    return volumen;
}

double Producto::getPeso() const {
    return peso;
}
