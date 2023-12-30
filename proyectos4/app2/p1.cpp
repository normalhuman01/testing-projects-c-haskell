#include <iostream>
#include <string>

using namespace std;

class Cliente {
public:
    string nombre;
    string dni;
    int cantidadEntradas;

    Cliente(string nombre, string dni, int cantidadEntradas) {
        this->nombre = nombre;
        this->dni = dni;
        this->cantidadEntradas = cantidadEntradas;
    }
};

class Nodo {
public:
    Cliente* cliente;
    Nodo* siguiente;

    Nodo(Cliente* cliente) {
        this->cliente = cliente;
        this->siguiente = nullptr;
    }
};

class ListaCola {
private:
    Nodo* frente;
    Nodo* fin;
    int capacidadMaxima;
    int cantidadActual;

public:
    ListaCola(int capacidadMaxima) {
        this->frente = nullptr;
        this->fin = nullptr;
        this->capacidadMaxima = capacidadMaxima;
        this->cantidadActual = 0;
    }

    int encolar(string nombre, string dni, int cantidadEntradas) {
        if (cantidadActual >= capacidadMaxima) {
            return -1; // Cola llena
        }

        Cliente* nuevoCliente = new Cliente(nombre, dni, cantidadEntradas);
        Nodo* nuevoNodo = new Nodo(nuevoCliente);

        if (frente == nullptr) {
            frente = nuevoNodo;
            fin = nuevoNodo;
        } else {
            fin->siguiente = nuevoNodo;
            fin = nuevoNodo;
        }

        cantidadActual++;
        return capacidadMaxima - cantidadActual;
    }

    void atender() {
        if (frente == nullptr) {
            cout << "La cola está vacía." << endl;
            return;
        }

        Cliente* clienteAtendido = frente->cliente;
        cout << "Nombre: " << clienteAtendido->nombre << endl;
        cout << "DNI: " << clienteAtendido->dni << endl;
        cout << "Cantidad de entradas: " << clienteAtendido->cantidadEntradas << endl;

        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
        cantidadActual--;
    }
};

int main() {
    ListaCola cola(5); // Capacidad máxima de la cola

    // Encolar clientes
    int resultado1 = cola.encolar("Cliente1", "12345678A", 3);
    int resultado2 = cola.encolar("Cliente2", "87654321B", 2);
    int resultado3 = cola.encolar("Cliente3", "98765432C", 1);

    if (resultado1 == -1) {
        cout << "La cola está llena para el Cliente1." << endl;
    } else {
        cout << "Posiciones que faltan para atender al Cliente1: " << resultado1 << endl;
    }

    if (resultado2 == -1) {
        cout << "La cola está llena para el Cliente2." << endl;
    } else {
        cout << "Posiciones que faltan para atender al Cliente2: " << resultado2 << endl;
    }

    if (resultado3 == -1) {
        cout << "La cola está llena para el Cliente3." << endl;
    } else {
        cout << "Posiciones que faltan para atender al Cliente3: " << resultado3 << endl;
    }

    // Atender clientes
    cola.atender();
    cola.atender();
    cola.atender();

    return 0;
}
