#ifndef ANALIZADOR_LEXICO_H
#define ANALIZADOR_LEXICO_H

#include <string>
#include <vector>

class AnalizadorLexico {
public:
    AnalizadorLexico();
    std::vector<std::pair<std::string, std::string>> AnalizarExpresion(const std::string& expresion);
};

#endif // ANALIZADOR_LEXICO_H
