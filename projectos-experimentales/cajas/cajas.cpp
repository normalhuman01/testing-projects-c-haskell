#include "Caja.h"
#include <iostream>

Caja::Caja(double capacidad, double peso) : capacidad(capacidad), peso(peso), volumen(0) {}

bool Caja::agregarObjeto(const Producto& producto) {
    double nuevoVolumen = volumen + producto.getVolumen();
    if (nuevoVolumen <= capacidad) {
        contenido.push_back(producto);
        volumen = nuevoVolumen;
        return true; // Devuelve true cuando se agrega correctamente
    } else {
        std::cout << "No hay espacio suficiente en la caja." << std::endl;
        return false; // Devuelve false cuando no se puede agregar
    }
}

double Caja::calcularPeso() const {
    double pesoTotal = peso;
    for (const Producto& prod : contenido) {
        pesoTotal += prod.getPeso();
    }
    return pesoTotal;
}
