#include <iostream>
#include <vector>
#include <map>
#include "PartidaAjedrez.h" // Agrega la inclusión del encabezado

int main() {
    PartidaAjedrez partida;
    
    while (!partida.esFinDePartida()) {
        partida.verTurno();
        partida.mostrarPartida();
        
        std::cout << "Ingresa las coordenadas de la ficha a mover (ejemplo: A2): ";
        std::string origen;
        std::cin >> origen;
        
        std::cout << "Ingresa las coordenadas de destino (ejemplo: A4): ";
        std::string destino;
        std::cin >> destino;
        
        if (partida.moverFicha(origen, destino)) {
            partida.cambiarTurno();
        } else {
            std::cout << "Movimiento incorrecto. Inténtalo de nuevo." << std::endl;
        }
    }

    if (partida.esJaqueMate()) {
        std::cout << "Jaque mate!" << std::endl;
    } else if (partida.esTablas()) {
        std::cout << "Tablas!" << std::endl;
    } else {
        std::cout << "Fin de la partida." << std::endl;
    }

    return 0;
}
