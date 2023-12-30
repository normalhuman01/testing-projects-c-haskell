#include "analizador_lexico.h"
#include "analizador_sintactico.h"
#include <iostream>

int main() {
    AnalizadorLexico lexico;
    AnalizadorSintactico sintactico;

    std::string expresion = "2 3 + 4 *"; // Cambia la expresión a analizar aquí

    std::vector<std::pair<std::string, std::string>> tokens = lexico.AnalizarExpresion(expresion);
    
    std::tuple<std::string, int, int> resultado = sintactico.ParseExpresion(tokens);

    if (std::get<0>(resultado) == "NUMERO") {
        std::cout << "Resultado: " << std::get<1>(resultado) << std::endl;
    }

    return 0;
}
