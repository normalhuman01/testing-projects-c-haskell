#include <iostream>
#include <vector>

using namespace std;
//creamos la clase estructura que tiene como atributo una estructura de datos que puede ser un arreglo o lista
class Estructura {
protected:
    vector<int> estructura;
};
//creamos la clase pila que puede realizar las operaciones push y pop

class Pila : public Estructura {
public:
    void push(int n) {
        estructura.push_back(n);
    }

    int pop() {
        if(estructura.empty()) {
            throw "Esta pila esta vacia";
        }
        int ultimo = estructura.back();
        estructura.pop_back();
        return ultimo;
    }
};
//de la misma forma tenemos a la clase cola para poder realizar la funcion de encolar como decolar 
class Cola : public Estructura {
public:
    void encolar(int n) {
        estructura.push_back(n);
    }

    int decolar() {
        if(estructura.empty()) {
            throw "Esta cola esta vacia";
        }
        int primero = estructura.front();
        estructura.erase(estructura.begin());
        return primero;
    }
};
//cada estructura recibe una variable denominada tipo en este caso si el tipo es 0 entonces se comportara como  una pila. Por otro lado si es 1 pues entonces se comportara como una cola.
class ColaPila : public Pila, public Cola {
public:
//En caso sea tipo 0 realizara la funcion push que viene de la funcion pila. Por otro lado hara la funcion de cola de encolar
    void agregar(int n, int tipo) {
        if(tipo == 0) {
            Pila::push(n);
        } else {
            Cola::encolar(n);
        }
    }
//En caso sea tipo 0 realizara la funcion pop que viene de la funcion pila. Por otro lado hara la funcion de cola de decolar
    int quitar(int tipo) {
        if(tipo == 0) {
            return Pila::pop();
        } else {
            return Cola::decolar();
        }
    }
};

int main() {
  //ejemplos para la pila
    Pila pila;
    pila.push(4);
    pila.push(6);
    cout << "Pila: " << pila.pop() << endl;
//ejemplos para cola
    Cola cola;
    cola.encolar(1);
    cola.encolar(2);
    cout << "Cola: " << cola.decolar() << endl;
//ejemplos para colapila
    ColaPila colaPila;
    colaPila.agregar(1, 0);
    colaPila.agregar(2, 1);
    cout << "ColaPila Pila: " << colaPila.quitar(0) << endl;
    cout << "ColaPila Cola: " << colaPila.quitar(1) << endl;

    return 0;
}