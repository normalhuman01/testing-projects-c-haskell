#include "Celda.h"
#include "HojaCalculo.h"
#include <iostream>

int main() {
    HojaCalculo hoja;

    // Agregar filas y columnas de ejemplo
    hoja.agregarFila();
    hoja.agregarFila();
    hoja.agregarColumna();
    hoja.agregarColumna();

    // Asignar valores a algunas celdas
    hoja.asignarValor(0, 0, "10");
    hoja.asignarValor(0, 1, "20");
    hoja.asignarValor(1, 0, "30");
    hoja.asignarValor(1, 1, "40");

    // Mostrar la hoja de cálculo
    std::cout << "Hoja de cálculo:" << std::endl;
    hoja.mostrarHoja();

    // Ver valores de algunas celdas
    std::cout << "Valor en la fila 0, columna 0: " << hoja.verValor(0, 0) << std::endl;
    std::cout << "Valor en la fila 1, columna 1: " << hoja.verValor(1, 1) << std::endl;

    // Puedes continuar trabajando con la hoja de cálculo según tus necesidades

    return 0;
}
