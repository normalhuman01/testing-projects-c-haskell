#pragma once
#include "raylib.h"
#include <iostream>

class Vertice {
    private:
    // Atributos
    Vector3 xyz;
    Vertice* verticeSiguiente;

    public:
    // Constructores
    Vertice();
    Vertice(float x, float y, float z);

    // Getters
    Vector3 getXYZ();
    Vertice* getVerticeSiguiente();

    // Setters
    void setXYZ(float x, float y, float z);
    void setVerticeSiguiente(Vertice* verticeSiguiente);
};

class ListaDeVertices {
    private:
    // Atributos
    Vertice* primerVertice;
    Vertice* ultimoVertice;
    int cantidadDeVertices;

    public:
    // Constructor
    ListaDeVertices();

    // Getters
    Vertice* getPrimerVertice();
    Vertice* getUltimoVertice();
    int getCantidadDeVertices();

    // Setters
    void setPrimerVertice(Vertice* primerVertice);
    void setUltimoVertice(Vertice* ultimoVertice);
    void setCantidadDeVertices(int cantidadDeVertices);

    // Metodos adicionales
    void agregarVertice(Vertice* nuevoVertice);
    Vertice* buscarVertice(int posicion);
    void verLista();
};

class Triangulo {
    private:
    // Atributos
    int ABC[3];
    Triangulo* trianguloSiguiente;

    public:
    // Constructor
    Triangulo(int A, int B, int C);

    // Getters
    int* getABC();
    Triangulo* getTrianguloSiguiente();

    // Setters
    void setABC(int A, int B, int C);
    void setTrianguloSiguiente(Triangulo* trianguloSiguiente);
};

class ListaDeTriangulos {
    private:
    // Atributos
    Triangulo* primerTriangulo;
    Triangulo* ultimoTriangulo;
    int cantidadDeTriangulos;

    public:
    // Constructor
    ListaDeTriangulos();

    // Getters
    Triangulo* getPrimerTriangulo();
    Triangulo* getUltimoTriangulo();
    int getCantidadDeTriangulos();

    // Setters
    void setPrimerTriangulo(Triangulo* primerTriangulo);
    void setUltimoTriangulo(Triangulo* ultimoTriangulo);
    void setCantidadDeTriangulos(int cantidadDeTriangulos);

    // Metodos adicionales
    void agregarTriangulo(Triangulo* nuevoTriangulo);
    Triangulo* buscarTriangulo(int posicion);
    void verLista();
};

class MallaDeTriangulos {
    private:
    // Atributos
    ListaDeVertices* listaV;
    ListaDeTriangulos* listaT;

    public:
    // Constructor
    MallaDeTriangulos();
    MallaDeTriangulos(ListaDeVertices* listaV, ListaDeTriangulos* listaT);

    // Getters
    ListaDeVertices* getListaDeVertices();
    ListaDeTriangulos* getListaDeTriangulos();

    // Setters
    void setListaDeVertices(ListaDeVertices* listaV);
    void setListaDeTriangulos(ListaDeTriangulos* listaT);

    // Metodos adicionales
    void verMalla();
    void dibujarMalla();
};
