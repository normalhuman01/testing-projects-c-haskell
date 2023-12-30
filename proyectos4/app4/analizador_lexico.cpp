#include "analizador_lexico.h"
#include <sstream>
#include <iostream>

AnalizadorLexico::AnalizadorLexico() {}

std::vector<std::pair<std::string, std::string>> AnalizadorLexico::AnalizarExpresion(const std::string& expresion) {
    std::vector<std::pair<std::string, std::string>> tokens;
    std::istringstream iss(expresion);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            tokens.emplace_back("OPERADOR", token);
        } else if (std::isdigit(token[0])) {
            tokens.emplace_back("NUMERO", token);
        } else {
            // Caracter no reconocido
            tokens.emplace_back("ERROR", token);
        }
    }

    return tokens;
}
