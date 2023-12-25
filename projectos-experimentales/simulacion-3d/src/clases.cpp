#include "..\include\clases.h"

using namespace std;

//============================ Metodos de la clase Vertice ============================//

// Constructores
Vertice::Vertice() {
    this->xyz = {0.0f, 0.0f, 0.0f};
    this->verticeSiguiente = nullptr;
}

Vertice::Vertice(float x, float y, float z) {
    this->xyz = {x, y, z};
    this->verticeSiguiente = nullptr;
}

// Getters
Vector3 Vertice::getXYZ() {
    return this->xyz;
}

Vertice* Vertice::getVerticeSiguiente() {
    return this->verticeSiguiente;
}

// Setters
void Vertice::setXYZ(float x, float y, float z) {
    this->xyz = {x, y, z};
}

void Vertice::setVerticeSiguiente(Vertice* verticeSiguiente) {
    this->verticeSiguiente = verticeSiguiente;
}



//============================ Metodos de la clase ListaDeVertices ============================//

// Constructor
ListaDeVertices::ListaDeVertices() {
    this->primerVertice = nullptr;
    this->ultimoVertice = nullptr;
    this->cantidadDeVertices = 0;
}

// Getters
Vertice* ListaDeVertices::getPrimerVertice() {
    return this->primerVertice;
}

Vertice* ListaDeVertices::getUltimoVertice() {
    return this->ultimoVertice;
}

int ListaDeVertices::getCantidadDeVertices() {
    return this->cantidadDeVertices;
}

// Setters
void ListaDeVertices::setPrimerVertice(Vertice* primerVertice) {
    this->primerVertice = primerVertice;
}

void ListaDeVertices::setUltimoVertice(Vertice* ultimoVertice) {
    this->ultimoVertice = ultimoVertice;
}

void ListaDeVertices::setCantidadDeVertices(int cantidadDeVertices) {
    this->cantidadDeVertices = cantidadDeVertices;
}

// Metodos adicionales
void ListaDeVertices::agregarVertice(Vertice* nuevoVertice) {
    if (this->cantidadDeVertices == 0) {
        this->primerVertice = nuevoVertice;
        this->ultimoVertice = nuevoVertice;
    }
    else {
        this->ultimoVertice->setVerticeSiguiente(nuevoVertice);
        this->ultimoVertice = nuevoVertice;
    }

    this->cantidadDeVertices++;
}

Vertice* ListaDeVertices::buscarVertice(int posicion) {
    if (posicion < 0) {
        cout << "Posicion ingresada invalida" << endl;
        return nullptr;
    }
    else if (posicion >= this-> cantidadDeVertices) {
        cout << "Todavia no hay un vertice en la posicion " << posicion << endl;
        return nullptr;
    }
    else {
        Vertice* ptrPivote = this->primerVertice;

        for (int i = 0; i < posicion; i++) {
            ptrPivote = ptrPivote->getVerticeSiguiente();
        }

        return ptrPivote;
    }
}

void ListaDeVertices::verLista() {
    cout << "Actualmente hay " << this->cantidadDeVertices << " vertice(s) en la lista:" << endl << endl;
    cout << "Nro" << "\t" << "x" << "\t" << "y" << "\t" << "z" << endl;

    Vertice* ptrPivote = this->primerVertice;

    for (int i = 0; i < this->cantidadDeVertices; i++) {
        cout << i << "\t" << ptrPivote->getXYZ().x << "\t" << ptrPivote->getXYZ().y << "\t" << ptrPivote->getXYZ().z << endl;
        ptrPivote = ptrPivote->getVerticeSiguiente();
    }

    cout << endl;
}



//============================ Metodos de la clase Triangulo ============================//

// Constructor
Triangulo::Triangulo(int A, int B, int C) {
    this->ABC[0] = A;
    this->ABC[1] = B;
    this->ABC[2] = C;
    this->trianguloSiguiente = nullptr;
}

// Getters
int* Triangulo::getABC() {
    return this->ABC;
}

Triangulo* Triangulo::getTrianguloSiguiente() {
    return this->trianguloSiguiente;
}

// Setters
void Triangulo::setABC(int A, int B, int C) {
    this->ABC[0] = A;
    this->ABC[1] = B;
    this->ABC[2] = C;
}

void Triangulo::setTrianguloSiguiente(Triangulo* trianguloSiguiente) {
    this->trianguloSiguiente = trianguloSiguiente;
}



//============================ Metodos de la clase ListaDeTriangulos ============================//

// Constructor
ListaDeTriangulos::ListaDeTriangulos() {
    this->primerTriangulo = nullptr;
    this->ultimoTriangulo = nullptr;
    this->cantidadDeTriangulos = 0;
}

// Getters
Triangulo* ListaDeTriangulos::getPrimerTriangulo() {
    return this->primerTriangulo;
}

Triangulo* ListaDeTriangulos::getUltimoTriangulo() {
    return this->ultimoTriangulo;
}

int ListaDeTriangulos::getCantidadDeTriangulos() {
    return this->cantidadDeTriangulos;
}

// Setters
void ListaDeTriangulos::setPrimerTriangulo(Triangulo* primerTriangulo) {
    this->primerTriangulo = primerTriangulo;
}

void ListaDeTriangulos::setUltimoTriangulo(Triangulo* ultimoTriangulo) {
    this->ultimoTriangulo = ultimoTriangulo;
}

void ListaDeTriangulos::setCantidadDeTriangulos(int cantidadDeTriangulos) {
    this->cantidadDeTriangulos = cantidadDeTriangulos;
}

// Metodos adicionales
void ListaDeTriangulos::agregarTriangulo(Triangulo* nuevoTriangulo) {
    if (this->cantidadDeTriangulos == 0) {
        this->primerTriangulo = nuevoTriangulo;
        this->ultimoTriangulo = nuevoTriangulo;
    }
    else {
        this->ultimoTriangulo->setTrianguloSiguiente(nuevoTriangulo);
        this->ultimoTriangulo = nuevoTriangulo;
    }

    this->cantidadDeTriangulos++;
}

Triangulo* ListaDeTriangulos::buscarTriangulo(int posicion) {
    if (posicion < 0) {
        cout << "Posicion ingresada invalida" << endl;
        return nullptr;
    }
    else if (posicion >= this->cantidadDeTriangulos) {
        cout << "Todavia no hay un triangulo en la posicion " << posicion << endl;
        return nullptr;
    }
    else {
        Triangulo* ptrPivote = this->primerTriangulo;

        for (int i = 0; i < posicion; i++) {
            ptrPivote = ptrPivote->getTrianguloSiguiente();
        }

        return ptrPivote;
    }
}

void ListaDeTriangulos::verLista() {
    cout << "Actualmente hay " << this->cantidadDeTriangulos << " triangulo(s) en la lista:" << endl << endl;
    cout << "Nro" << "\t" << "A" << "\t" << "B" << "\t" << "C" << endl;

    Triangulo* ptrPivote = this->primerTriangulo;

    for (int i = 0; i < this->cantidadDeTriangulos; i++) {
        cout << i << "\t" << ptrPivote->getABC()[0] << "\t" << ptrPivote->getABC()[1] << "\t" << ptrPivote->getABC()[2] << endl;
        ptrPivote = ptrPivote->getTrianguloSiguiente();
    }

    cout << endl;
}



//============================ Metodos de la clase MallaDeTriangulos ============================//

// Constructor
MallaDeTriangulos::MallaDeTriangulos() {
    this->listaV = nullptr;
    this->listaT = nullptr;
}

MallaDeTriangulos::MallaDeTriangulos(ListaDeVertices* listaV, ListaDeTriangulos* listaT) {
    this->listaV = listaV;
    this->listaT = listaT;
}

// Getters
ListaDeVertices* MallaDeTriangulos::getListaDeVertices() {
    return this->listaV;
}

ListaDeTriangulos* MallaDeTriangulos::getListaDeTriangulos() {
    return this->listaT;
}

// Setters
void MallaDeTriangulos::setListaDeVertices(ListaDeVertices* listaV) {
    this->listaV = listaV;
}

void MallaDeTriangulos::setListaDeTriangulos(ListaDeTriangulos* listaT) {
    this->listaT = listaT;
}

// Metodos adicionales
void MallaDeTriangulos::verMalla() {
    this->listaV->verLista();
    this->listaT->verLista();
}

void MallaDeTriangulos::dibujarMalla() {
    Triangulo* ptrPivote = this->listaT->getPrimerTriangulo();

    for (int i = 0; i < this->listaT->getCantidadDeTriangulos(); i++) {
        DrawTriangle3D(this->listaV->buscarVertice(ptrPivote->getABC()[0])->getXYZ(),
                        this->listaV->buscarVertice(ptrPivote->getABC()[1])->getXYZ(),
                        this->listaV->buscarVertice(ptrPivote->getABC()[2])->getXYZ(), RED);
        
        ptrPivote = ptrPivote->getTrianguloSiguiente();
    }
}
