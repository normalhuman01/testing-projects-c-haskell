#include "cliente.h"

Cliente::Cliente(const char* nombre, const char* dni, int cantidadEntradas) {
 {
    int i;

    for (i = 0; nombre[i] != '\0'; i++) {
        this->nombre[i] = nombre[i];
    }
    this->nombre[i] = '\0'; 
    for (i = 0; dni[i] != '\0'; i++) {
        this->dni[i] = dni[i];
    }
    this->dni[i] = '\0'; 

    this->cantidadEntradas = cantidadEntradas;
}
}