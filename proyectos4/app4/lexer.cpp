#include "lexer.h"
#include <sstream>

std::vector<Token> Lexer::tokenize(const std::string& input) {
    std::vector<Token> tokens;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        Token t;
        if (isNumber(token)) {
            t.type = NUMERO;
            t.value = token;
        } else if (isOperator(token)) {
            t.type = OPERADOR;
            t.value = token;
        } else {
            errorFlag = true;
            break;
        }
        tokens.push_back(t);
    }

    return tokens;
}

bool Lexer::hasError() const {
    return errorFlag;
}

bool Lexer::isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool Lexer::isOperator(const std::string& str) {
    return (str == "+" || str == "-" || str == "*" || str == "/");
}

bool Lexer::isValidCharacter(char c) {
    return (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/');
}
