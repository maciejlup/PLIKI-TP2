#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string chunk;
    float value;
    Node* left;
    Node* right;

    Node(const std::string& frag, Node* left, Node* right);

    bool is_leaf();
    std::string print();
    float compute();
};

#endif
