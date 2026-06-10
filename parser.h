#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "node.h"

class Parser {
public:
    std::string eq;
    int pos = 0;
    Node* ast = nullptr;

    Parser(const std::string& s);

    void print_ast();
    std::string consumeAll();
    std::string consumeUntil(std::string symbols);
    Node* terminal();
    Node* expr_as();
    Node* expr_md();
    void parse();
};

#endif
