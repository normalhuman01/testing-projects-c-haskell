#include "..\include\funciones.h"

using namespace std;

// Requerimiento 1 (aun por corregir)
bool verificarMesh(MallaDeTriangulos* malla) {
    if ((malla->getListaDeVertices() == nullptr) || (malla->getListaDeTriangulos() == nullptr)) {
        cout << "Se ha ingresado una malla sin lista de vertices o triangulos" << endl;
        return false;
    }
    else {
        Triangulo* pivotePrimario = malla->getListaDeTriangulos()->getPrimerTriangulo();

        // Se recorre todos los triangulos de la malla
        for (int i = 0; i < malla->getListaDeTriangulos()->getCantidadDeTriangulos(); i++) {
            if (pivotePrimario->getABC()[0] == pivotePrimario->getABC()[1]) return false; // Se verifica A != B
            if (pivotePrimario->getABC()[1] == pivotePrimario->getABC()[2]) return false; // Se verifica B != C
            if (pivotePrimario->getABC()[2] == pivotePrimario->getABC()[0]) return false; // Se verifica C != A

            pivotePrimario = pivotePrimario->getTrianguloSiguiente();
        }

        pivotePrimario = malla->getListaDeTriangulos()->getPrimerTriangulo();

        // Se recorre cada triangulo de la malla excepto el ultimo
        for (int i = 0; i < malla->getListaDeTriangulos()->getCantidadDeTriangulos() - 1; i++) {
            // Se forma 3 vectores con los 3 vertices del triangulo actual dados en sentido antihorario
            string vectorT1_1 = to_string(pivotePrimario->getABC()[0]) + to_string(pivotePrimario->getABC()[1]); // Vector AB
            string vectorT1_2 = to_string(pivotePrimario->getABC()[1]) + to_string(pivotePrimario->getABC()[2]); // Vector BC
            string vectorT1_3 = to_string(pivotePrimario->getABC()[2]) + to_string(pivotePrimario->getABC()[0]); // Vector CA

            // Se forma 3 vectores con direccion opuesta al de los anteriores
            string vectorT1_1_Invertido(vectorT1_1.rbegin(), vectorT1_1.rend()); // Vector BA
            string vectorT1_2_Invertido(vectorT1_2.rbegin(), vectorT1_2.rend()); // Vector CB
            string vectorT1_3_Invertido(vectorT1_3.rbegin(), vectorT1_3.rend()); // Vector AC

            // Contadores para cantidad de veces que cada vector con direccion opuesta del
            // triangulo actual resulta igual a los vectores del resto de triangulos
            int repeticionesT1_1 = 0, repeticionesT1_2 = 0, repeticionesT1_3 = 0;

            Triangulo* pivoteSecundario = pivotePrimario->getTrianguloSiguiente();

            
            cout << "============================================================" << endl <<endl;
            cout << "Triangulo ABC" << "\t" << "Vector AB" << "\t" << "Vector BC" << "\t" << "Vector CA" << endl; 
            cout << i << "\t\t" << vectorT1_1 << "\t\t" << vectorT1_2 << "\t\t" << vectorT1_3 << endl;
            

            // Se recorre los triangulos siguientes al triangulo actual para su comparacion
            for (int j = i + 1; j < malla->getListaDeTriangulos()->getCantidadDeTriangulos(); j++) {
                // Se forma 3 vectores con los 3 vertices del triangulo con el que se va a comparar dados en sentido antihorario
                string vectorT2_1 = to_string(pivoteSecundario->getABC()[0]) + to_string(pivoteSecundario->getABC()[1]); // Vector AB
                string vectorT2_2 = to_string(pivoteSecundario->getABC()[1]) + to_string(pivoteSecundario->getABC()[2]); // Vector BC
                string vectorT2_3 = to_string(pivoteSecundario->getABC()[2]) + to_string(pivoteSecundario->getABC()[0]); // Vector CA

                if ((vectorT1_1 == vectorT2_1) || (vectorT1_1 == vectorT2_2) || (vectorT1_1 == vectorT2_3)) return false;
                if ((vectorT1_2 == vectorT2_1) || (vectorT1_2 == vectorT2_2) || (vectorT1_2 == vectorT2_3)) return false;
                if ((vectorT1_3 == vectorT2_1) || (vectorT1_3 == vectorT2_2) || (vectorT1_3 == vectorT2_3)) return false;

                if ((vectorT1_1_Invertido == vectorT2_1) || (vectorT1_1_Invertido == vectorT2_2) || (vectorT1_1_Invertido == vectorT2_3)) {
                    repeticionesT1_1++;
                }
                if ((vectorT1_2_Invertido == vectorT2_1) || (vectorT1_2_Invertido == vectorT2_2) || (vectorT1_2_Invertido == vectorT2_3)) {
                    repeticionesT1_2++;
                }
                if ((vectorT1_3_Invertido == vectorT2_1) || (vectorT1_3_Invertido == vectorT2_2) || (vectorT1_3_Invertido == vectorT2_3)) {
                    repeticionesT1_3++;
                }

                pivoteSecundario = pivoteSecundario->getTrianguloSiguiente();

                cout << j << "\t\t" << vectorT2_1 << "\t\t" << vectorT2_2 << "\t\t" << vectorT2_3 << endl;
                
            }

            if ((repeticionesT1_1 + repeticionesT1_2 + repeticionesT1_3) == 0) return false;
            if ((repeticionesT1_1 > 1) || (repeticionesT1_2 > 1) || (repeticionesT1_3 > 1)) return false;

            pivotePrimario = pivotePrimario->getTrianguloSiguiente();

            
            cout << endl<< "Vectores invertidos del triangulo " << i << ": ";
            cout << vectorT1_1_Invertido << ", " << vectorT1_2_Invertido << ", " << vectorT1_3_Invertido << endl << endl;

            cout << "Nro de veces compartido de cada arista en el triangulo " << i << ":" << endl;
            cout << "AB: " << repeticionesT1_1 << "\t\t";
            cout << "BC: " << repeticionesT1_2 << "\t\t";
            cout << "CA: " << repeticionesT1_3 << endl << endl;
            
        }

        // Se retorna verdadero al haber superado todas las pruebas
        return true;
    }
}

// Requerimiento 2
void pintarTriangulo(MallaDeTriangulos* malla) {
    if ((malla->getListaDeVertices() == nullptr) || (malla->getListaDeTriangulos() == nullptr)) {
        cout << "Se ha ingresado una malla sin lista de vertices o triangulos" << endl;
    }
    else if ((malla->getListaDeVertices()->getCantidadDeVertices() == 3) && (malla->getListaDeTriangulos()->getCantidadDeTriangulos() == 1)) {
        ListaDeTriangulos* listaInvertidaT = new ListaDeTriangulos();
        MallaDeTriangulos* mallaInvertida = new MallaDeTriangulos();

        listaInvertidaT->agregarTriangulo(new Triangulo(malla->getListaDeTriangulos()->getPrimerTriangulo()->getABC()[2],
                                                        malla->getListaDeTriangulos()->getPrimerTriangulo()->getABC()[1],
                                                        malla->getListaDeTriangulos()->getPrimerTriangulo()->getABC()[0]));

        mallaInvertida->setListaDeVertices(malla->getListaDeVertices());
        mallaInvertida->setListaDeTriangulos(listaInvertidaT);

        malla->dibujarMalla();
        mallaInvertida->dibujarMalla();
    }
    else {
        cout << "Se ha ingresado una malla con una cantidad invalida de vertices o triangulos" << endl;
    }
}

// Requerimiento 3
MallaDeTriangulos* crearRectangulo(float ancho, float alto, Vector3 centro) {
    if ((ancho <= 0) || (alto <= 0)) {
        cout << "Se ha ingresado un valor de ancho o alto invalido" << endl;
        return nullptr;
    }
    else {
        ListaDeVertices* listaV = new ListaDeVertices();
        ListaDeTriangulos* listaT = new ListaDeTriangulos();
        MallaDeTriangulos* malla = new MallaDeTriangulos();

        listaV->agregarVertice(new Vertice(centro.x - ancho/2, centro.y - alto/2, centro.z)); // Esquina inferior izquierda
        listaV->agregarVertice(new Vertice(centro.x + ancho/2, centro.y - alto/2, centro.z)); // Esquina inferior derecha
        listaV->agregarVertice(new Vertice(centro.x - ancho/2, centro.y + alto/2, centro.z)); // Esquina superior izquierda
        listaV->agregarVertice(new Vertice(centro.x + ancho/2, centro.y + alto/2, centro.z)); // Esquina superior derecha

        listaT->agregarTriangulo(new Triangulo(0, 1, 2));
        listaT->agregarTriangulo(new Triangulo(1, 3, 2));

        malla->setListaDeVertices(listaV);
        malla->setListaDeTriangulos(listaT);

        return malla;
    }
}

// Requerimiento 4
MallaDeTriangulos* crearCubo(float ancho, float alto, float profundidad, Vector3 centro) {
    if ((ancho <= 0) || (alto <= 0) || (profundidad <= 0)) {
        cout << "Se ha ingresado un valor de ancho, alto o profundidad invalido" << endl;
        return nullptr;
    }
    else {
        ListaDeVertices* listaV = new ListaDeVertices();
        ListaDeTriangulos* listaT = new ListaDeTriangulos();
        MallaDeTriangulos* malla = new MallaDeTriangulos();

        listaV->agregarVertice(new Vertice(centro.x - ancho/2, centro.y - alto/2, centro.z + profundidad/2)); // Esquina inferior izquierda de cara delantera
        listaV->agregarVertice(new Vertice(centro.x + ancho/2, centro.y - alto/2, centro.z + profundidad/2)); // Esquina inferior derecha de cara delantera
        listaV->agregarVertice(new Vertice(centro.x - ancho/2, centro.y + alto/2, centro.z + profundidad/2)); // Esquina superior izquierda de cara delantera
        listaV->agregarVertice(new Vertice(centro.x + ancho/2, centro.y + alto/2, centro.z + profundidad/2)); // Esquina superior derecha de cara delantera
        listaV->agregarVertice(new Vertice(centro.x - ancho/2, centro.y - alto/2, centro.z - profundidad/2)); // Esquina inferior izquierda de cara trasera
        listaV->agregarVertice(new Vertice(centro.x + ancho/2, centro.y - alto/2, centro.z - profundidad/2)); // Esquina inferior derecha de cara trasera
        listaV->agregarVertice(new Vertice(centro.x - ancho/2, centro.y + alto/2, centro.z - profundidad/2)); // Esquina superior izquierda de cara trasera
        listaV->agregarVertice(new Vertice(centro.x + ancho/2, centro.y + alto/2, centro.z - profundidad/2)); // Esquina superior derecha de cara trasera

        listaT->agregarTriangulo(new Triangulo(0, 1, 2));
        listaT->agregarTriangulo(new Triangulo(1, 3, 2));
        listaT->agregarTriangulo(new Triangulo(1, 5, 3));
        listaT->agregarTriangulo(new Triangulo(5, 7, 3));
        listaT->agregarTriangulo(new Triangulo(5, 4, 7));
        listaT->agregarTriangulo(new Triangulo(4, 6, 7));
        listaT->agregarTriangulo(new Triangulo(4, 0, 6));
        listaT->agregarTriangulo(new Triangulo(0, 2, 6));
        listaT->agregarTriangulo(new Triangulo(5, 1, 0));
        listaT->agregarTriangulo(new Triangulo(4, 5, 0));
        listaT->agregarTriangulo(new Triangulo(2, 3, 6));
        listaT->agregarTriangulo(new Triangulo(3, 7, 6));

        malla->setListaDeVertices(listaV);
        malla->setListaDeTriangulos(listaT);

        return malla;
    }
}

// Requerimiento 5
void pintarRectangulo(MallaDeTriangulos* malla) {
    if ((malla->getListaDeVertices() == nullptr) || (malla->getListaDeTriangulos() == nullptr)) {
        cout << "Se ha ingresado una malla sin lista de vertices o triangulos" << endl;
    }
    else if ((malla->getListaDeVertices()->getCantidadDeVertices() == 4) && (malla->getListaDeTriangulos()->getCantidadDeTriangulos() == 2)) {
        ListaDeVertices* listaV_T0 = new ListaDeVertices();
        ListaDeVertices* listaV_T1 = new ListaDeVertices();
        ListaDeTriangulos* listaT_T0 = new ListaDeTriangulos();
        ListaDeTriangulos* listaT_T1 = new ListaDeTriangulos();
        
        Triangulo* t0 = malla->getListaDeTriangulos()->getPrimerTriangulo();
        Triangulo* t1 = t0->getTrianguloSiguiente();
        
        
        for (int i = 0; i < 3; i++) {
            listaV_T0->agregarVertice(new Vertice(*(malla->getListaDeVertices()->buscarVertice(t0->getABC()[i]))));
            listaV_T1->agregarVertice(new Vertice(*(malla->getListaDeVertices()->buscarVertice(t1->getABC()[i]))));         
        }
        
        listaT_T0->agregarTriangulo(new Triangulo(0, 1, 2));
        listaT_T1->agregarTriangulo(new Triangulo(0, 1, 2));
        
        pintarTriangulo(new MallaDeTriangulos(listaV_T0, listaT_T0));
        pintarTriangulo(new MallaDeTriangulos(listaV_T1, listaT_T1));
    }
}

// Requerimiento 6
void moverMesh(MallaDeTriangulos* malla, Vector3 destino) {
    Vector3 origen = malla->getListaDeVertices()->getPrimerVertice()->getXYZ();
    float desplazamientoEnX = destino.x - origen.x;
    float desplazamientoEnY = destino.y - origen.y;
    float desplazamientoEnZ = destino.z - origen.z;
    
    Vertice* pivote = malla->getListaDeVertices()->getPrimerVertice();

    for (int i = 0; i < malla->getListaDeVertices()->getCantidadDeVertices(); i++) {
        pivote->setXYZ(pivote->getXYZ().x + desplazamientoEnX,
                        pivote->getXYZ().y + desplazamientoEnY,
                        pivote->getXYZ().z + desplazamientoEnZ);

        pivote = pivote->getVerticeSiguiente();
    }
}

// Requerimiento 7 (aun por corregir)
void animar(MallaDeTriangulos* malla) {
    float desplazamientoEnX = 0.1f;

    if ((-5.0f <= malla->getListaDeVertices()->getUltimoVertice()->getXYZ().x) || (malla->getListaDeVertices()->getUltimoVertice()->getXYZ().x <= 5.0f)) {
        desplazamientoEnX = desplazamientoEnX * -1;
    }

    Vertice* pivote = malla->getListaDeVertices()->getPrimerVertice();

    for (int i = 0; i < malla->getListaDeVertices()->getCantidadDeVertices(); i++) {
        pivote->setXYZ(pivote->getXYZ().x + desplazamientoEnX,
                        pivote->getXYZ().y,
                        pivote->getXYZ().z);

        pivote = pivote->getVerticeSiguiente();
    }

    malla->dibujarMalla();
}
