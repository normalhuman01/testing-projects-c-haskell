
#include "Pieza.h"
#include <vector>
#include <string>

class PartidaAjedrez {
public:
    PartidaAjedrez();
    void verTurno() const;
    void mostrarPartida() const;
    void mostrarPosiblesMovimientos(const std::string& casilla) const;
    bool moverFicha(const std::string& origen, const std::string& destino);
    void reiniciarPartida();
    bool esFinDePartida() const;
    bool esJaqueMate() const;
    bool esTablas() const;
    void cambiarTurno(); // Agrega este método en la declaración

private:
    std::vector<std::vector<Pieza*>> tablero;
    bool turnoBlanco; // true si es el turno de las blancas, false si es de las negras
    // Otros atributos y métodos que consideres necesarios

    // Método auxiliar para inicializar el tablero y las piezas
    void inicializarTablero();
};

