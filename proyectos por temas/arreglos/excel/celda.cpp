#include "Celda.h"

Celda::Celda() : valor("") {}

void Celda::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string Celda::getValor() const {
    return valor;
}
