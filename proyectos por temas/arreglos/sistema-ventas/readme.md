makefile: "all: build
build:
	g++ -c instrumentos.cpp
	g++ instrumentos.o main.cpp -o main
	main.exe

clean:
	-rm -rf *.o
	-rm -rf *.exe", instrumentos.cpp: "#include "instrumentos.h"

// ===================== Instrumento =================================

Instrumento::Instrumento()
{
    this->precio = 0.0f;
    this->codigo = 0;
    this->siguiente = nullptr;
}

Instrumento::Instrumento(int codigo, float precio)
{
    this->precio = precio;
    this->codigo = codigo;
    this->siguiente = nullptr;
}

float Instrumento::GetPrecio()
{
    return precio;
}

// ===================== ListaInstrumentos =================================

ListaInstrumentos::ListaInstrumentos()
{
    this->longitud = 0;
    this->pInst = nullptr;
}
void ListaInstrumentos::AgregarInstrumento(Instrumento* instrumento)
{
    if (this->pInst == nullptr)
    {
        this->pInst = new Instrumento[this->longitud + 1];
        this->pInst[this->longitud].codigo = instrumento->codigo;
        this->pInst[this->longitud].precio = instrumento->precio;
    }else 
    {
        Instrumento* pTemp = new Instrumento[this->longitud + 1];
        for (int i=0 ; i < this->longitud; i++)
        {
            // Copia de data entre arreglo anterior (pInst) y el nuevo (pTemp)
            pTemp[i].codigo = pInst[i].codigo;
            pTemp[i].precio = pInst[i].precio;
        }
        delete[] this->pInst; // Libero el espacio del arreglo anterior
        this->pInst = pTemp;

        this->pInst[this->longitud].codigo = instrumento->codigo;
        this->pInst[this->longitud].precio = instrumento->precio;
    }

    this->longitud++;
}
void ListaInstrumentos::Imprimir()
{
    for (int i=0; i < this->longitud; i++)
    {
        std::cout << this->pInst[i].codigo << " ";
    }
    std::cout << std::endl;
}
int ListaInstrumentos::GetLongitud()
{
    return this->longitud;
}

// ===================== ListaEnlazadaInstrumentos =================================

ListaEnlazadaInstrumentos::ListaEnlazadaInstrumentos()
{
    this->longitud = 0;
    this->pPrimer = nullptr;
}
void ListaEnlazadaInstrumentos::AgregarInstrumento(int codigo, float precio)
{
    if (this->pPrimer == nullptr)
    {
        // No hay elementos
        Instrumento* pNuevoInstrumento = new Instrumento(codigo, precio);
        this->pPrimer = pNuevoInstrumento;
    }else
    {
        Instrumento* pNuevoInstrumento = new Instrumento(codigo, precio);
        pNuevoInstrumento->siguiente = this->pPrimer;
        this->pPrimer = pNuevoInstrumento;
    }
    this->longitud++;
}

void ListaEnlazadaInstrumentos::AgregarInstrumentoAlFinal(int codigo, float precio)
{
    Instrumento* pNuevoInstrumento = new Instrumento(codigo, precio);

    if (this->pPrimer == nullptr)
    {
        // Caso lista vacia
        this->pPrimer = pNuevoInstrumento;
    }else
    {
        Instrumento* pPivot = this->pPrimer;

        while (pPivot->siguiente != nullptr)
        {
            pPivot = pPivot->siguiente;
        }

        pPivot->siguiente = pNuevoInstrumento;
    }
    this->longitud++;
}

void ListaEnlazadaInstrumentos::EliminarInstrumento(int pos)
{
    if (pos == 0)
    {
        // Eliminar el primero
        Instrumento* pTemp = this->pPrimer;
        this->pPrimer = this->pPrimer->siguiente;
        delete pTemp; // libero memoria
    }else
    {
        Instrumento* pPivot = this->pPrimer;
        Instrumento* pAnt = nullptr;
        int indice = 0;
        while (pPivot != nullptr)
        {
            if (indice == pos)
            {
                // Eliminar
                pAnt->siguiente = pPivot->siguiente;
                delete pPivot;
                break;
            }

            pAnt = pPivot;
            pPivot = pPivot->siguiente;
            indice++;
        }
    }
    this->longitud--;
    
}

Instrumento* ListaEnlazadaInstrumentos::BuscarPorCodigo(int codigo)
{
    Instrumento* pPivot = this->pPrimer;

    while(pPivot != nullptr)
    {
        if (pPivot->codigo == codigo)
        {
            // yay lo encontramos!
            return pPivot;
        }
        pPivot = pPivot->siguiente;
    }
    return nullptr;
}

void ListaEnlazadaInstrumentos::Imprimir()
{
    Instrumento* pPivot = this->pPrimer;

    while(pPivot != nullptr)
    {
            std::cout << "(" << pPivot->codigo << "," << pPivot->precio << ") ";
            pPivot = pPivot->siguiente;
    }
    std::cout << std::endl;
}", instrumentos.h: "#include <iostream>

class Instrumento
{
private:
public:
    float precio; // atributo
    int codigo; // atributo
    Instrumento* siguiente; // atributo

    Instrumento(); // Metodo constructor
    Instrumento(int codigo, float precio); // Metodo constructor secundario
    float GetPrecio(); // Metodo
};

class ListaInstrumentos
{
private:
    int longitud;
    Instrumento* pInst;
public:
    ListaInstrumentos();
    void AgregarInstrumento(Instrumento* instrumento);
    void Imprimir();
    int GetLongitud();
};

// ========================================

class ListaEnlazadaInstrumentos
{
public:
    Instrumento* pPrimer;
    int longitud;

    ListaEnlazadaInstrumentos();
    void AgregarInstrumento(int codigo, float precio);
    void AgregarInstrumentoAlFinal(int codigo, float precio);
    void EliminarInstrumento(int pos);
    Instrumento* BuscarPorCodigo(int codigo);
    void Imprimir();
};", main.cpp: "#include "instrumentos.h"
#include <iostream>

int main()
{
    Instrumento i1(1, 30.5f); // i1 es una objeto/instancia de la clase Instrumento
    Instrumento* i2 = new Instrumento(2, 30.5f); // i2 es un objeto/instancia de la clase Instrumento

    // Crear un programa que almacene instrumentos en una lista.
    ListaInstrumentos* lista = new ListaInstrumentos();
    lista->AgregarInstrumento(&i1);
    lista->Imprimir();
    lista->AgregarInstrumento(i2);
    lista->Imprimir();

    ListaEnlazadaInstrumentos* listaEnlazada = new ListaEnlazadaInstrumentos();
    listaEnlazada->AgregarInstrumento(1, 30.5f);
    listaEnlazada->AgregarInstrumento(2, 20.5f);
    listaEnlazada->AgregarInstrumentoAlFinal(3, 10.5f);
    listaEnlazada->Imprimir();

    Instrumento* instrumento = listaEnlazada->BuscarPorCodigo(2);
    std::cout << instrumento->codigo << "," << instrumento->precio <<std::endl;

    listaEnlazada->EliminarInstrumento(0);
    listaEnlazada->Imprimir();
    listaEnlazada->EliminarInstrumento(1);
    listaEnlazada->Imprimir();

    Instrumento* instrumento2 = listaEnlazada->BuscarPorCodigo(2);
    if (instrumento2 != nullptr)
    {
        std::cout << instrumento2->codigo << "," << instrumento2->precio <<std::endl;
    }


    // TAREA
    // Implementar EliminarInstrumento (eliminas el ultimo instrumento de la lista)
    // Implementar EliminarInstrumentoDadoCodigo (eliminas el instrumento de determinado codigo)

    return 0;
}", estructuras.h"

//Carta
Carta::Carta(int valor, Simbolo simbolo){
    this->valor = valor;
    this->simbolo = simbolo;
    siguiente = nullptr;
}
Carta* Baraja :: ObtenerCarta(int pos){
    if(primer==nullptr){
        return nullptr;
    }
    Carta* pPivot = primer;
    Carta* pAnt = nullptr;
    
    if(pos==0){
        primer=pPivot->siguiente;
        longitud--;
        return pPivot;
    }else{
        int cont =0;
        while(pPivot != nullptr){
            if(cont==pos){
                pAnt->siguiente = pPivot->siguiente;
                pPivot -> siguiente = nullptr;
                longitud--;
                return pPivot;
            }
            pAnt = pPivot;
            pPivot= pPivot->siguiente;
            cont++;
        }
    }
    return nullptr;
}
void Carta:: Imprimir(){
    std::cout<<"Carta valor="<<this->valor   
    <<" simbolo="<<(int)this->simbolo<<" />"
    <<std::endl;
}

Baraja::Baraja(){
    primer = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

Simbolo Baraja::ObtenerSimbolo(int num){
    switch(num){
        case 0:
            return Simbolo::Corazon;
        case 1:
            return Simbolo::Espada;
        break;
        case 2:
            return Simbolo::Trebol;
        break;
        case 3:
            return Simbolo::Diamante;
        default:
            return Simbolo::Corazon;
    }
}

void Baraja::AgregarCarta(Carta* carta){
    if(primer ==nullptr){
        // no hay cartas
       primer=carta;
       ultimo=carta; 
    }else{
        ultimo->siguiente = carta;
        ultimo=carta;
    }
    longitud++;
}
void Baraja::CrearCartas(){
    for(int i = 0; i<4; i++){
        for(int j=0;j<13;j++){
            Carta* nuevaCarta = 
            new Carta(j+1, ObtenerSimbolo(i));
            AgregarCarta(nuevaCarta);
        }
    }
}
void Baraja::Imprimir(){
    Carta* pPivot = primer;
    while(pPivot != nullptr){
        pPivot->Imprimir();
        pPivot=pPivot->siguiente;
    }
    std::cout<<"</Baraja>"<<std::endl;
}
" 
estructuras.h: "#pragma once
enum class Simbolo{
    Corazon, Espada, Trebol, Diamante
};

class Carta{
public:
    int valor;
    Simbolo simbolo;
    Carta* siguiente;
    
    Carta(int valor, Simbolo simbolo);
    void Imprimir();
};
class Baraja{
public:
    Carta* primer;
    Carta* ultimo;
    int longitud;
    
    Baraja();
    void CrearCartas();
    Simbolo ObtenerSimbolo(int num);
    void AgregarCarta(Carta* carta);
    Carta* ObtenerCarta(int pos);
    void Imprimir();
};

"
main.cpp:"#include "pregunta1.h"
#include "pregunta2.h"
#include "pregunta3.h"
#include "pregunta4.h"
#include "pregunta5.h"
int main(){
    Baraja* baraja = new Baraja();
    baraja->CrearCartas();

    Carta* carta = pregunta2(baraja);
    carta->Imprimir();
    baraja->Imprimir();
    return 0;
}   


"
pregunta1.cpp:"#include "pregunta1.h"
void pregunta1(Baraja* baraja){
    if(baraja!=nullptr){
        baraja->CrearCartas();
    }
}"
pregunta1.h:"#pragma once
#include "estructuras.h"
void pregunta1(Baraja* baraja);"
pregunta2.cpp:"#include <cstdlib>
#include "pregunta2.h"
Carta* pregunta2(Baraja* baraja){
    int posAleatoria = rand() % baraja->longitud; //TODO
    Carta* carta=
        baraja->ObtenerCarta(posAleatoria);
    return carta;
}
"
pregunta2.h:"#include "estructuras.h"
Carta* pregunta2(Baraja* baraja);
"
pregunta3.cpp:"#include "estructuras.h"
#include "pregunta3.h"
#include <iostream>

void pregunta3(Baraja* baraja, int pos1, int pos2) {
    if (pos1 < 0 || pos1 >= baraja->longitud || pos2 < 0 || pos2 >= baraja->longitud) {
        std::cout << "Posiciones no válidas." << std::endl;
        return;
    }

    Carta* carta1 = baraja->ObtenerCarta(pos1);
    Carta* carta2 = baraja->ObtenerCarta(pos2);

    Carta* siguienteCarta1 = carta1->siguiente;

    carta1->siguiente = carta2->siguiente;
    carta2->siguiente = siguienteCarta1;

    if (pos1 == 0) {
        baraja->primer = carta2;
    } else {
        Carta* cartaAnt1 = baraja->ObtenerCarta(pos1 - 1);
        cartaAnt1->siguiente = carta2;
    }

    if (pos2 == 0) {
        baraja->primer = carta1;
    } else {
        Carta* cartaAnt2 = baraja->ObtenerCarta(pos2 - 1);
        cartaAnt2->siguiente = carta1;
    }
}
"
pregunta3.h:"#pragma once
#include "estructuras.h"

void pregunta3(Baraja* baraja, int pos1, int pos2);"
pregunta4.cpp:"#include "estructuras.h"
#include "pregunta4.h"

Baraja* pregunta4(Baraja* baraja, int numero) {
    Baraja* nuevaBaraja = new Baraja();

    int pos = 0;
    while (pos < baraja->longitud) {
        Carta* pCarta = baraja->ObtenerCarta(pos);
        if (pCarta->valor != numero) {
            nuevaBaraja->AgregarCarta(pCarta);
        } else {
            delete pCarta;
        }
    }

    delete baraja;

    return nuevaBaraja;
}
"
pregunta4.h:"#pragma once
#include "estructuras.h"

Baraja* pregunta4(Baraja* baraja, int numero);"
pregunta5.cpp:"#include "estructuras.h"
#include "pregunta5.h"

void pregunta5(Baraja* baraja, Carta* nuevaCarta) {
    baraja->AgregarCarta(nuevaCarta);
}
"
pregunta5.h:"#pragma once
#include "estructuras.h