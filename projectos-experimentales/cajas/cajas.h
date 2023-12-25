#include <vector>
#include "Producto.h"

class Caja {
private:
    double capacidad;
    double volumen;
    std::vector<Producto> contenido;
    double peso;

public:
    Caja(double capacidad, double peso);
    bool agregarObjeto(const Producto& producto);
    double calcularPeso() const;
};
