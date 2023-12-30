#include "analizador_sintactico.h"
#include <iostream>

AnalizadorSintactico::AnalizadorSintactico() {}

std::tuple<std::string, int, int> AnalizadorSintactico::ParseExpresion(const std::vector<std::pair<std::string, std::string>>& tokens) {
    std::stack<std::tuple<std::string, int, int>> pila;

    for (const auto& token : tokens) {
        if (token.first == "NUMERO") {
            int numero = std::stoi(token.second);
            pila.push(std::make_tuple("NUMERO", numero, numero));
        } else if (token.first == "OPERADOR") {
            if (pila.size() < 2) {
                // Error: no hay suficientes operandos para la operación
                std::cout << "Error: Operador sin suficientes operandos." << std::endl;
                return std::make_tuple("ERROR", 0, 0);
            }

            int op2 = std::get<1>(pila.top());
            pila.pop();
            int op1 = std::get<1>(pila.top());
            pila.pop();

            if (token.second == "+") {
                pila.push(std::make_tuple("NUMERO", op1 + op2, op2));
            } else if (token.second == "-") {
                pila.push(std::make_tuple("NUMERO", op1 - op2, op2));
            } else if (token.second == "*") {
                pila.push(std::make_tuple("NUMERO", op1 * op2, op2));
            } else if (token.second == "/") {
                if (op2 == 0) {
                    // Error: división por cero
                    std::cout << "Error: División por cero." << std::endl;
                    return std::make_tuple("ERROR", 0, 0);
                }
                pila.push(std::make_tuple("NUMERO", op1 / op2, op2));
            }
        } else {
            // Error: token no reconocido
            std::cout << "Error: Token no reconocido: " << token.second << std::endl;
            return std::make_tuple("ERROR", 0, 0);
        }
    }

    if (pila.size() != 1) {
        // Error: la pila final no tiene un solo resultado
        std::cout << "Error: Expresión incompleta." << std::endl;
        return std::make_tuple("ERROR", 0, 0);
    }

    return pila.top();
}
