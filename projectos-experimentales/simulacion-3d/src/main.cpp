#include "..\include\clases.h"
#include "..\include\funciones.h"

using namespace std;

int main(void) {
    short requerimiento;

    // Ingreso de requerimiento a probar
    cout << "Ingrese el numero del requerimiento que desee probar: ";
    cin >> requerimiento;

    const int screenWidth = 720; // Ancho de ventana
    const int screenHeight = 720; // Alto de ventana

    InitWindow(screenWidth, screenHeight, "Ventana de prueba"); // Apertura de ventana

    Camera3D objCamara; // Declaracion de objeto tipo Camera3D
    objCamara.position = {10.0f, 10.0f, 10.0f}; // Ubicacion de la camara
    objCamara.target = {0.0f, 0.0f, 0.0f}; // Punto de observacion de la camara
    objCamara.up = {0.0f, 1.0f, 0.0f}; // Eje de rotacion de la camara
    objCamara.fovy = 45.0f; // Angulo de vision de la camara
    objCamara.projection = CAMERA_PERSPECTIVE; // Tipo de proyeccion de la camara

    int modoDeCamara = CAMERA_ORBITAL; // Modo de la camara

    SetTargetFPS(60); // Frecuencia de actualizacion de ventana

    ListaDeVertices* listaV; // Usado en requerimientos 1 y 2
    ListaDeTriangulos* listaT; // Usado en requerimientos 1 y 2 
    MallaDeTriangulos* malla; // Usado en requerimientos 1, 2 y 3

    float ancho; // Usado en requerimiento 3
    float alto; // Usado en requerimiento 3
    float profundidad; // Usado en requerimiento 3 y 4
    Vector3 centro; // Usado en requerimiento 3 y 4
    MallaDeTriangulos* mallaInvertida; // Usado en requerimiento 3
    ListaDeTriangulos* listaInvertidaT; // Usado en requerimiento 3
    Triangulo* pivote; // Usado en requerimiento 3

    // Seleccion de requerimiento ingresado
    switch (requerimiento) {
        //========================================================================
        case 1:
            // Vertices y triangulos para una piramide
            listaV = new ListaDeVertices();
            listaT = new ListaDeTriangulos();
            malla = new MallaDeTriangulos();

            listaV->agregarVertice(new Vertice(0.0f, 2.0f, 1.0f)); // Vertice 0
            listaV->agregarVertice(new Vertice(1.0f, 2.0f, 0.0f)); // Vertice 1
            listaV->agregarVertice(new Vertice(0.0f, 5.0f, 0.0f)); // Vertice 2
            listaV->agregarVertice(new Vertice(0.0f, 2.0f, -1.0f)); // Vertice 3
            listaV->agregarVertice(new Vertice(-1.0f, 2.0f, 0.0f)); // Vertice 4

            listaT->agregarTriangulo(new Triangulo(0, 1, 2)); // Triangulo 0
            listaT->agregarTriangulo(new Triangulo(1, 3, 2)); // Triangulo 1
            listaT->agregarTriangulo(new Triangulo(3, 4, 2)); // Triangulo 2
            listaT->agregarTriangulo(new Triangulo(4, 0, 2)); // Triangulo 3
            listaT->agregarTriangulo(new Triangulo(3, 1, 0)); // Triangulo 4
            listaT->agregarTriangulo(new Triangulo(3, 0, 4)); // Triangulo 5

            malla->setListaDeVertices(listaV);
            malla->setListaDeTriangulos(listaT);

            malla->verMalla();

            if (verificarMesh(malla)) {
                cout << "True" << endl;
            }
            else {
                cout << "False" << endl;
            }

            break;
        
        //========================================================================
        case 2:
            // Vertices para un solo triangulo
            listaV = new ListaDeVertices();
            listaT = new ListaDeTriangulos();
            malla = new MallaDeTriangulos();

            listaV->agregarVertice(new Vertice(-2.0f, 2.0f, 3.0f)); // Vertice 0
            listaV->agregarVertice(new Vertice(2.0f, 2.0f, 0.0f)); // Vertice 1
            listaV->agregarVertice(new Vertice(0.0f, 5.0f, 1.5f)); // Vertice 2

            listaT->agregarTriangulo(new Triangulo(0, 1, 2)); // Triangulo 0

            malla->setListaDeVertices(listaV);
            malla->setListaDeTriangulos(listaT);

            malla->verMalla();

            break;

        //========================================================================
        case 3:
            // Dimensiones de un rectangulo y las coordenadas de su centro
            ancho = 4.0f;
            alto = 2.0f;
            centro = {0.0f, 3.0f, 3.0f};
            listaInvertidaT = new ListaDeTriangulos();
            mallaInvertida = new MallaDeTriangulos();

            malla = crearRectangulo(ancho, alto, centro);

            pivote = malla->getListaDeTriangulos()->getPrimerTriangulo();

            for(int i = 0; i < malla->getListaDeTriangulos()->getCantidadDeTriangulos(); i++) {
                listaInvertidaT->agregarTriangulo(new Triangulo(pivote->getABC()[2],
                                                                pivote->getABC()[1],
                                                                pivote->getABC()[0]));

                pivote = pivote->getTrianguloSiguiente();
            }

            mallaInvertida->setListaDeVertices(malla->getListaDeVertices());
            mallaInvertida->setListaDeTriangulos(listaInvertidaT);

            malla->verMalla();
            mallaInvertida->verMalla();

            break;
        
        //========================================================================
        case 4:
            // Dimensiones de un cubo y las coordenandas de su centro
            ancho = 4.0f;
            alto = 4.0f;
            profundidad = 4.0f;
            centro = {2.0f, 2.0f, 2.0f};

            malla = crearCubo(ancho, alto, profundidad, centro);

            malla->verMalla();

            break;
        
        case 5:
            // Vertices y triangulos para un rectangulo
            listaV = new ListaDeVertices();
            listaT = new ListaDeTriangulos();
            malla = new MallaDeTriangulos();

            listaV->agregarVertice(new Vertice(2.0f, 2.0f, 2.0f)); // Vertice 0
            listaV->agregarVertice(new Vertice(6.0f, 2.0f, 2.0f)); // Vertice 1
            listaV->agregarVertice(new Vertice(2.0f, 5.0f, 2.0f)); // Vertice 2
            listaV->agregarVertice(new Vertice(6.0f, 5.0f, 2.0f)); // Vertice 3

            listaT->agregarTriangulo(new Triangulo(0, 1, 2)); // Triangulo 0
            listaT->agregarTriangulo(new Triangulo(1, 3, 2)); // Triangulo 1

            malla->setListaDeVertices(listaV);
            malla->setListaDeTriangulos(listaT);

            malla->verMalla();

            break;
        
        case 6:
            // Vertices y triangulos para una piramide
            listaV = new ListaDeVertices();
            listaT = new ListaDeTriangulos();
            malla = new MallaDeTriangulos();

            listaV->agregarVertice(new Vertice(0.0f, 2.0f, 1.0f)); // Vertice 0
            listaV->agregarVertice(new Vertice(1.0f, 2.0f, 0.0f)); // Vertice 1
            listaV->agregarVertice(new Vertice(0.0f, 5.0f, 0.0f)); // Vertice 2
            listaV->agregarVertice(new Vertice(0.0f, 2.0f, -1.0f)); // Vertice 3
            listaV->agregarVertice(new Vertice(-1.0f, 2.0f, 0.0f)); // Vertice 4

            listaT->agregarTriangulo(new Triangulo(0, 1, 2)); // Triangulo 0
            listaT->agregarTriangulo(new Triangulo(1, 3, 2)); // Triangulo 1
            listaT->agregarTriangulo(new Triangulo(3, 4, 2)); // Triangulo 2
            listaT->agregarTriangulo(new Triangulo(4, 0, 2)); // Triangulo 3
            listaT->agregarTriangulo(new Triangulo(3, 1, 0)); // Triangulo 4
            listaT->agregarTriangulo(new Triangulo(3, 0, 4)); // Triangulo 5

            malla->setListaDeVertices(listaV);
            malla->setListaDeTriangulos(listaT);

            moverMesh(malla, {0.0f, 0.0f, 0.0f});

            malla->verMalla();

            break;

        case 7:
            // Vertices y triangulos para una piramide
            listaV = new ListaDeVertices();
            listaT = new ListaDeTriangulos();
            malla = new MallaDeTriangulos();

            listaV->agregarVertice(new Vertice(0.0f, 2.0f, 1.0f)); // Vertice 0
            listaV->agregarVertice(new Vertice(1.0f, 2.0f, 0.0f)); // Vertice 1
            listaV->agregarVertice(new Vertice(0.0f, 5.0f, 0.0f)); // Vertice 2
            listaV->agregarVertice(new Vertice(0.0f, 2.0f, -1.0f)); // Vertice 3
            listaV->agregarVertice(new Vertice(-1.0f, 2.0f, 0.0f)); // Vertice 4

            listaT->agregarTriangulo(new Triangulo(0, 1, 2)); // Triangulo 0
            listaT->agregarTriangulo(new Triangulo(1, 3, 2)); // Triangulo 1
            listaT->agregarTriangulo(new Triangulo(3, 4, 2)); // Triangulo 2
            listaT->agregarTriangulo(new Triangulo(4, 0, 2)); // Triangulo 3
            listaT->agregarTriangulo(new Triangulo(3, 1, 0)); // Triangulo 4
            listaT->agregarTriangulo(new Triangulo(3, 0, 4)); // Triangulo 5

            malla->setListaDeVertices(listaV);
            malla->setListaDeTriangulos(listaT);

            malla->verMalla();

            break;

        default:

            break;

    }

    while (!WindowShouldClose()) {
        UpdateCamera(&objCamara, modoDeCamara);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(objCamara);
                DrawGrid(10, 1.0f); // Plano XZ
                DrawLine3D({0.0f, 0.0f, 0.0f}, {5.0f, 0.0f, 0.0f}, RED); // Eje x positivo
                DrawLine3D({0.0f, 0.0f, 0.0f}, {0.0f, 5.0f, 0.0f}, GREEN); // Eje y positivo
                DrawLine3D({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 5.0f}, BLUE); // Eje z positivo

                switch (requerimiento) {
                    case 1:
                        malla->dibujarMalla();
                        break;
                    
                    case 2:
                        pintarTriangulo(malla);
                        break;
                    
                    case 3:
                        malla->dibujarMalla();
                        mallaInvertida->dibujarMalla();
                        break;
                    
                    case 4:
                        malla->dibujarMalla();
                        break;

                    case 5:
                        pintarRectangulo(malla);
                        break;
                    
                    case 6:
                        malla->dibujarMalla();
                        break;
                    
                    case 7:
                        animar(malla);
                        break;

                    default:
                        break;

                }

            EndMode3D();
        EndDrawing();
    }
    
    CloseWindow(); // Cierre de ventana
    return 0;
}
