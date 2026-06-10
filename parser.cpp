#include "parser.h"

#include <cctype>
#include <iostream>
#include <string>

Parser::Parser(const std::string& s) : eq(s), pos(0), ast(nullptr) {}

void Parser::print_ast() {
    std::cout << ast->print() << std::endl;
}

std::string Parser::consumeAll() {
    int tmp = pos;
    while (pos < eq.size() && (std::isdigit(eq[pos]) || eq[pos] == '.')) {
        pos++;
    }
    return eq.substr(tmp, pos - tmp);
}

std::string Parser::consumeUntil(std::string symbols) {
    int tmp = pos;
    while (pos < eq.size() && (symbols.find(eq[pos]) != std::string::npos)) {
        pos++;
    }
    return eq.substr(tmp, pos - tmp);
}

Node* Parser::terminal() {
    if (pos < eq.size() && eq[pos] == '(') {
        consumeUntil("(");
        Node* node = expr_as();
        consumeUntil(")");
        return node;
    }
    return new Node(consumeAll(), nullptr, nullptr);
}

Node* Parser::expr_as() {
    Node* left = expr_md();
    std::string n;
    while (!(n = consumeUntil("-+")).empty()) {
        Node* right = expr_md();
        left = new Node(n, left, right);
    }
    return left;
}

Node* Parser::expr_md() {
    Node* left = terminal();
    std::string n;
    while (!(n = consumeUntil("*/")).empty()) {
        Node* right = terminal();
        left = new Node(n, left, right);
    }
    return left;
}

void Parser::parse() {
    ast = expr_as();
}
