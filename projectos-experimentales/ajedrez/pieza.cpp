#include <string>

class Pieza {
public:
    Pieza(bool esBlanca);
    virtual ~Pieza();

    std::string getPosicion();
    void setPosicion(const std::string& nuevaPosicion);
    bool esBlanca();
    void setBlanca(bool nuevoColorBlanco);
    bool estaCapturada();
    void setCapturada(bool estadoCapturada);

    // Método abstracto para verificar si un movimiento es válido
    virtual bool esMovimientoValido(const std::string& destino) = 0;

private:
    std::string posicion;
    bool colorBlanco;
    bool capturada;
};

// Ejemplo de una clase derivada (Peon)
class Peon : public Pieza {
public:
    Peon(bool esBlanca);
    ~Peon();

    bool esMovimientoValido(const std::string& destino) override;
};
