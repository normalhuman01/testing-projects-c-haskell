void pregunta4(ListaCola* cola, Cliente* nuevoCliente, int posicion) {
    if (posicion < 0 || posicion > cola->cantidadActual) {
        cout << "La posición ingresada no es válida." << endl;
        return;
    }

    Nodo* nuevoNodo = new Nodo(nuevoCliente);

    if (posicion == 0) {
        // Insertar al principio
        nuevoNodo->siguiente = cola->frente;
        cola->frente = nuevoNodo;
        if (cola->cantidadActual == 0) {
            cola->fin = nuevoNodo;
        }
    } else if (posicion == cola->cantidadActual) {
        // Insertar al final
        cola->fin->siguiente = nuevoNodo;
        cola->fin = nuevoNodo;
    } else {
        // Insertar en posición arbitraria
        Nodo* anterior = cola->frente;
        for (int i = 0; i < posicion - 1; i++) {
            anterior = anterior->siguiente;
        }
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevoNodo;
    }

    cola->cantidadActual++;
}
