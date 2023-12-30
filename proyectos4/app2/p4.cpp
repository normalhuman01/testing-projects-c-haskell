void pregunta5(ListaCola* cola, int posicion1, int posicion2) {
    if (posicion1 < 0 || posicion1 >= cola->cantidadActual ||
        posicion2 < 0 || posicion2 >= cola->cantidadActual || posicion1 == posicion2) {
        cout << "Las posiciones ingresadas no son válidas o son iguales." << endl;
        return;
    }

    if (posicion1 > posicion2) {
        swap(posicion1, posicion2); // Asegurarse de que posicion1 < posicion2
    }

    Nodo* actual = cola->frente;
    Nodo* nodo1 = nullptr;
    Nodo* nodo2 = nullptr;
    int posicionActual = 0;

    while (actual != nullptr) {
        if (posicionActual == posicion1) {
            nodo1 = actual;
        }
        if (posicionActual == posicion2) {
            nodo2 = actual;
        }

        actual = actual->siguiente;
        posicionActual++;
    }

    // Intercambiar los clientes en las posiciones
    Cliente* temp = nodo1->cliente;
    nodo1->cliente = nodo2->cliente;
    nodo2->cliente = temp;
}
