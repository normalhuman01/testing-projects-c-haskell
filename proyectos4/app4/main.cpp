#include <iostream>
#include <vector>
#include "lexer.h"
#include "parser.h"

int main() {
    std::string expression;
    std::cout << "Ingrese una expresión postfija (separando números y operadores con espacios): ";
    std::getline(std::cin, expression);

    Lexer lexer;
    std::vector<Token> tokens = lexer.tokenize(expression);

    if (lexer.hasError()) {
        std::cout << "Error léxico: Caracter no reconocido." << std::endl;
        return 1;
    }

    Parser parser;
    Node* root = parser.parse(tokens);

    if (parser.hasError()) {
        std::cout << "Error sintáctico: Expresión incorrecta." << std::endl;
        return 1;
    }

    std::cout << "Resultado de la expresión: " << evaluateExpression(root) << std::endl;

    return 0;
}
