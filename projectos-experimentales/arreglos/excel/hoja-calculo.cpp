#include "HojaCalculo.h"
#include "Celda.h" // Incluye Celda.h aquí
#include <iostream>
// Resto del código de HojaCalculo.cpp
HojaCalculo::HojaCalculo() {}

void HojaCalculo::agregarFila() {
    if (filas.empty()) {
        filas.push_back(std::vector<Celda>());
    } else {
        std::vector<Celda> nuevaFila(filas[0].size());
        filas.push_back(nuevaFila);
    }
}

void HojaCalculo::agregarColumna() {
    for (auto& fila : filas) {
        fila.push_back(Celda());
    }
}

std::string HojaCalculo::verValor(int fila, int columna) const {
    if (fila < filas.size() && columna < filas[fila].size()) {
        return filas[fila][columna].getValor();
    }
    return ""; // O manejo de error
}

void HojaCalculo::asignarValor(int fila, int columna, const std::string& valor) {
    if (fila < filas.size() && columna < filas[fila].size()) {
        filas[fila][columna].setValor(valor);
    }
    // O manejo de error
}

void HojaCalculo::mostrarHoja() const {
    for (const auto& fila : filas) {
        for (const auto& celda : fila) {
            std::cout << celda.getValor() << " ";
        }
        std::cout << std::endl;
    }
}

void HojaCalculo::asignarValorSuma(int fila, int columna, int fila1, int col1, int fila2, int col2) {
    // Implementación de la suma
    // Asumiendo que los valores son numéricos y convertibles a double
}

void HojaCalculo::asignarValorResta(int fila, int columna, int fila1, int col1, int fila2, int col2) {
    // Implementación de la resta
    // Asumiendo que los valores son numéricos y convertibles a double
}
