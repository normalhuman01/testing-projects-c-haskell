#ifndef ANALIZADOR_SINTACTICO_H
#define ANALIZADOR_SINTACTICO_H

#include <string>
#include <stack>
#include <tuple>

class AnalizadorSintactico {
public:
    AnalizadorSintactico();
    std::tuple<std::string, int, int> ParseExpresion(const std::vector<std::pair<std::string, std::string>>& tokens);
};

#endif // ANALIZADOR_SINTACTICO_H
