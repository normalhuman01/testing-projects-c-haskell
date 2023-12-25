#ifndef PIEZA_H
#define PIEZA_H

#include <string>
#include <vector>

class Pieza {
protected:
    std::string posicion;
    bool colorBlanco;
    bool capturada;

public:
    Pieza(); // Constructor si es necesario
    virtual ~Pieza(); // Destructor virtual

    std::string getPosicion();
    void setPosicion(const std::string& nuevaPosicion);
    bool esBlanca();
    void setBlanca(bool nuevoColorBlanco);
    bool estaCapturada();
    void setCapturada(bool estadoCapturada);

    virtual std::vector<std::string> movimientosPosibles() = 0; // Método virtual puro para los movimientos posibles
};

#endif // PIEZA_H
