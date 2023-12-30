Cliente* pregunta3(ListaCola* cola) {
    if (cola->cantidadActual == 0) {
        cout << "La cola está vacía, no se puede sacar a nadie." << endl;
        return nullptr;
    }

    Cliente* clienteSacado = cola->frente->cliente;
    Nodo* temp = cola->frente;
    cola->frente = cola->frente->siguiente;

    delete temp;
    cola->cantidadActual--;

    return clienteSacado;
}
