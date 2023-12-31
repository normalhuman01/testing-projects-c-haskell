#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include "estructura.h"

int main() {
    // Creación de una Pila
    Pila pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.pop();

    // Creación de una Cola
    Cola cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.decolar();

    // Creación de una ColaPila que se comporta como Pila
    ColaPila colaPilaPila(0);
    colaPilaPila.agregar(1);
    colaPilaPila.agregar(2);
    colaPilaPila.agregar(3);
    colaPilaPila.quitar();

    // Creación de una ColaPila que se comporta como Cola
    ColaPila colaPilaCola(1);
    colaPilaCola.agregar(1);
    colaPilaCola.agregar(2);
    colaPilaCola.agregar(3);
    colaPilaCola.quitar();

    // Ejemplo de búsqueda secuencial
    std::vector<int> data(1000000);
    std::fill(data.begin(), data.end(), 42); // Llenamos el vector con 42 para simular datos
    int target = 42;
    int sequentialCount = 0;

    for (int i = 0; i < 1000000; ++i) {
        if (data[i] == target) {
            sequentialCount++;
        }
    }

    std::cout << "Búsqueda secuencial: El elemento " << target << " se encuentra " << sequentialCount << " veces." << std::endl;

    // Ejemplo de búsqueda binaria con paralelismo
    int parallelCount = 0;
    int numThreads = 4;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([&data, i, numThreads, target, &parallelCount]() {
            int start = (i * data.size()) / numThreads;
            int end = ((i + 1) * data.size()) / numThreads;

            for (int j = start; j < end; ++j) {
                if (data[j] == target) {
                    parallelCount++;
                }
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Búsqueda binaria con paralelismo: El elemento " << target << " se encuentra " << parallelCount << " veces." << std::endl;

    return 0;
}
