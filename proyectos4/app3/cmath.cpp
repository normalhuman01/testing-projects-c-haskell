#include <iostream>
#include <cmath>

// Función para calcular la sumatoria de los dígitos de un número utilizando tail recursion
int sumatoriaDigitos(int num, int suma = 0) {
    if (num == 0) {
        return suma;
    }
    int digito = num % 10;
    return sumatoriaDigitos(num / 10, suma + digito);
}

// Función para contar la cantidad de dígitos en un número
int contarDigitos(int num) {
    if (num < 10) {
        return 1;
    }
    return 1 + contarDigitos(num / 10);
}

// Función para verificar si un número cumple con la propiedad especificada
bool cumplePropiedad(int num) {
    int sumaPotencias = 0;
    int original = num;
    int numDigitos = contarDigitos(num);

    while (num > 0) {
        int digito = num % 10;
        sumaPotencias += pow(digito, numDigitos);
        num /= 10;
    }

    return sumaPotencias == original;
}

// Función para calcular la distancia de Manhattan entre dos puntos
int distanciaManhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Función para determinar si un número es perfecto
bool esPerfecto(int num) {
    int sumaDivisores = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sumaDivisores += i;
        }
    }
    return sumaDivisores == num;
}

// Función para calcular el MCD de dos números
int calcularMCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calcularMCD(b, a % b);
}

int main() {
    // Ejemplo de uso de las funciones
    int numero = 154;
    std::cout << "Sumatoria de los digitos de " << numero << ": " << sumatoriaDigitos(numero) << std::endl;

    int numeroPropiedad = 135;
    std::cout << "Cumple la propiedad: " << std::boolalpha << cumplePropiedad(numeroPropiedad) << std::endl;

    int punto1_x = 2, punto1_y = 3;
    int punto2_x = 5, punto2_y = 7;
    std::cout << "Distancia de Manhattan entre los puntos: " << distanciaManhattan(punto1_x, punto1_y, punto2_x, punto2_y) << std::endl;

    int numeroPerfecto = 28;
    std::cout << "Es un numero perfecto: " << std::boolalpha << esPerfecto(numeroPerfecto) << std::endl;

    int num1 = 36, num2 = 48;
    std::cout << "MCD de " << num1 << " y " << num2 << ": " << calcularMCD(num1, num2) << std::endl;

    return 0;
}
