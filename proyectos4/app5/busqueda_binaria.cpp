#include <iostream>
#include <vector>

// Crear un vector con números del 1 al 1000000
std::vector<int> crear_vector() {
    std::vector<int> arreglo;
    for (int i = 1; i <= 1000000; ++i) {
        arreglo.push_back(i);
    }
    return arreglo;
}

// Función de búsqueda binaria para encontrar el índice de un elemento en el vector
int busqueda_binaria(const std::vector<int>& arreglo, int n) {
    int izquierda = 0;
    int derecha = arreglo.size() - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arreglo[medio] == n) {
            return medio;
        } else if (arreglo[medio] < n) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

// Realizar búsqueda binaria de manera paralela utilizando múltiples hilos
int busqueda_binaria_paralela(const std::vector<int>& arreglo, int n, int procesos) {
    int tamano_trozo = arreglo.size() / procesos;
    int resultado = -1;

    for (int i = 0; i < procesos; ++i) {
        int inicio = i * tamano_trozo;
        int fin = (i + 1) * tamano_trozo;

        // Realizar la búsqueda binaria en el trozo del arreglo
        for (int j = inicio; j < fin; ++j) {
            if (arreglo[j] == n) {
                resultado = j;
                break;
            }
        }

        if (resultado != -1) {
            break; // Si se encuentra el elemento, salir del bucle
        }
    }

    return resultado;
}

int main() {
    // Crear el vector utilizando la función anterior
    std::vector<int> arreglo = crear_vector();

    // Ejemplo de búsqueda del índice del número 500000000 sin paralelismo
    int indice = busqueda_binaria(arreglo, 500000000);
    std::cout << "El índice del número 500000000 es: " << indice << std::endl;

    // Ejemplo de búsqueda del índice del número 500000000 usando paralelismo con 4 hilos
    indice = busqueda_binaria_paralela(arreglo, 500000000, 4);
    std::cout << "El índice del número 500000000 es: " << indice << std::endl;

    return 0;
}
