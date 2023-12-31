#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "lexer.h"

struct Node {
    TokenType type;
    std::string value;
    Node* left = nullptr;
    Node* right = nullptr;
};

class Parser {
public:
    Node* parse(const std::vector<Token>& tokens);
    bool hasError() const;

private:
    Node* parseExpression(std::vector<Token>& tokens);
    Node* createNode(TokenType type, const std::string& value);
    bool errorFlag = false;
};

#endif
