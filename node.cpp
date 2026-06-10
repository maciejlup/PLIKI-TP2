#include "node.h"
#include <stdexcept>
#include <string>

Node::Node(const std::string& frag, Node* left, Node* right)
    : chunk(frag), value(0), left(left), right(right) {}

bool Node::is_leaf() {
    return left == nullptr && right == nullptr;
}

std::string Node::print() {
    return is_leaf() ? chunk : left->print() + chunk + right->print();
}

float Node::compute() {
    if (is_leaf()) {
        return std::stof(chunk);
    }

    if (chunk == "+") return left->compute() + right->compute();
    if (chunk == "-") return left->compute() - right->compute();
    if (chunk == "*") return left->compute() * right->compute();
    if (chunk == "/") return left->compute() / right->compute();

    throw std::runtime_error("Unknown operator: " + chunk);
}
