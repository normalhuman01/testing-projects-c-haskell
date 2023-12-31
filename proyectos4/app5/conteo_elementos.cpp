#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <ctime>
#include <cstdlib>

// Esta función contará los elementos dentro de un vector
int contar_elementos(const std::vector<int>& arr, int objetivo, int inicio, int fin, int& contador, std::mutex& mtx) {
    int local_contador = 0;
    for (int i = inicio; i < fin; ++i) {
        if (arr[i] == objetivo) {
            local_contador++;
        }
    }

    std::lock_guard<std::mutex> lock(mtx);
    contador += local_contador;

    return local_contador;
}

// Esta función permite realizar el conteo de forma paralela dividiendo el vector en fragmentos
int conteo_paralelo(const std::vector<int>& arr, int objetivo, int num_procesos = 4) {
    int contador = 0;
    std::mutex mtx;

    int tamano_fragmento = arr.size() / num_procesos;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_procesos; ++i) {
        int inicio = i * tamano_fragmento;
        int fin = (i < num_procesos - 1) ? (inicio + tamano_fragmento) : arr.size();

        threads.emplace_back(contar_elementos, std::ref(arr), objetivo, inicio, fin, std::ref(contador), std::ref(mtx));
    }

    for (std::thread& thread : threads) {
        thread.join();
    }

    return contador;
}

// Esta función es para el conteo secuencial dentro de un vector
int conteo_secuencial(const std::vector<int>& arr, int objetivo) {
    int contador = 0;
    for (int elemento : arr) {
        if (elemento == objetivo) {
            contador++;
        }
    }
    return contador;
}

int main() {
    // Genero un vector aleatorio de 1 millón de elementos
    std::vector<int> arreglo;
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000000; ++i) {
        arreglo.push_back(std::rand() % 11);
    }

    int elemento_objetivo = std::rand() % 11;

    // Demora secuencial
    std::clock_t tiempo_inicio = std::clock();
    int conteo_sec = conteo_secuencial(arreglo, elemento_objetivo);
    double tiempo_secuencial = static_cast<double>(std::clock() - tiempo_inicio) / CLOCKS_PER_SEC;
    std::cout << "Resultado secuencial: " << conteo_sec << " veces. Tiempo secuencial: " << tiempo_secuencial << " segundos" << std::endl;

    // Demora paralela
    tiempo_inicio = std::clock();
    int resultado_conteo_paralelo = conteo_paralelo(arreglo, elemento_objetivo);
    double tiempo_paralelo = static_cast<double>(std::clock() - tiempo_inicio) / CLOCKS_PER_SEC;
    std::cout << "Resultado paralelo: " << resultado_conteo_paralelo << " veces. Tiempo paralelo: " << tiempo_paralelo << " segundos" << std::endl;

    return 0;
}
