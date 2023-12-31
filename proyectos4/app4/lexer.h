#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType {
    NUMERO,
    OPERADOR
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    std::vector<Token> tokenize(const std::string& input);
    bool hasError() const;

private:
    bool isNumber(const std::string& str);
    bool isOperator(const std::string& str);
    bool isValidCharacter(char c);

    bool errorFlag = false;
};

#endif
