#include <iostream>
#include "perfecto.h"
#include "mcd.h"

int main() {
    std::cout << "Ingrese un número:" << std::endl;
    int numero;
    std::cin >> numero;

    if (perfect(numero)) {
        std::cout << "Es un número perfecto." << std::endl;
    } else {
        std::cout << "No es un número perfecto." << std::endl;
    }

    std::cout << "Ingrese el primer número:" << std::endl;
    int num1;
    std::cin >> num1;

    std::cout << "Ingrese el segundo número:" << std::endl;
    int num2;
    std::cin >> num2;

    int mcd = calcularMCD(num1, num2);
    std::cout << "El MCD de " << num1 << " y " << num2 << " es " << mcd << std::endl;

    return 0;
}
