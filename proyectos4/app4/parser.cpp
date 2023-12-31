#include "parser.h"

Node* Parser::parse(const std::vector<Token>& tokens) {
    std::vector<Token> tokensCopy = tokens;
    return parseExpression(tokensCopy);
}

Node* Parser::parseExpression(std::vector<Token>& tokens) {
    if (tokens.empty()) {
        return nullptr;
    }

    Token token = tokens.back();
    tokens.pop_back();
    Node* node = createNode(token.type, token.value);

    if (token.type == NUMERO) {
        return node;
    } else if (token.type == OPERADOR) {
        node->right = parseExpression(tokens);
        node->left = parseExpression(tokens);
        return node;
    } else {
        errorFlag = true;
        return nullptr;
    }
}

Node* Parser::createNode(TokenType type, const std::string& value) {
    Node* node = new Node;
    node->type = type;
    node->value = value;
    return node;
}

bool Parser::hasError() const {
    return errorFlag;
}
