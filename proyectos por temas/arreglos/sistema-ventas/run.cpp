#include <iostream>

class Cliente {
public:
    std::string nombre;
    std::string dni;
    int cantidadEntradas;

    Cliente(const std::string& nombre, const std::string& dni, int cantidadEntradas)
        : nombre(nombre), dni(dni), cantidadEntradas(cantidadEntradas) {}
};

class ListaCola {
private:
    int capacidadMaxima;
    Cliente* cola;
    int frente; // Índice del primer elemento en la cola
    int final;  // Índice del último elemento en la cola

public:
    ListaCola(int capacidad) : capacidadMaxima(capacidad), frente(0), final(0) {
        cola = new Cliente[capacidadMaxima];
    }

    ~ListaCola() {
        delete[] cola;
    }

    int Encolar(const std::string& nombre, const std::string& dni, int cantidadEntradas) {
        if (final < capacidadMaxima) {
            cola[final] = Cliente(nombre, dni, cantidadEntradas);
            final++;
            return capacidadMaxima - final;
        } else {
            return -1; // La cola está llena
        }
    }

    void Atender() {
        if (frente < final) {
            std::cout << "Cliente: " << cola[frente].nombre << std::endl;
            std::cout << "DNI: " << cola[frente].dni << std::endl;
            std::cout << "Cantidad de entradas: " << cola[frente].cantidadEntradas << std::endl;
            frente++;
        } else {
            std::cout << "La cola está vacía." << std::endl;
        }
    }
};

int main() {
    ListaCola cola(5); // Capacidad máxima de la cola es 5

    int resultado;
    
    resultado = cola.Encolar("Cliente1", "12345678", 3);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    resultado = cola.Encolar("Cliente2", "98765432", 2);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al primer cliente en la cola

    resultado = cola.Encolar("Cliente3", "56789012", 1);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al siguiente cliente en la cola

    resultado = cola.Encolar("Cliente4", "34567890", 4);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al siguiente cliente en la cola

    resultado = cola.Encolar("Cliente5", "45678901", 2);
    std::cout << "Espacio restante en la cola: " << resultado << std::endl;

    cola.Atender(); // Atiende al siguiente cliente en la cola

    cola.Atender(); 
    return 0;
}
