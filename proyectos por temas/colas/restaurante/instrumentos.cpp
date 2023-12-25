#include "instrumentos.h"

// ===================== Instrumento =================================

Instrumento::Instrumento()
{
    this->precio = 0.0f;
    this->codigo = 0;
}

Instrumento::Instrumento(int codigo, float precio)
{
    this->precio = precio;
    this->codigo = codigo;
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