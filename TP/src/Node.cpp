#include "Node.hpp"

Node::Node() {
    this->email = new Email();
    this->left = NULL;
    this->right = NULL;
}

Node::Node(Email *email) {
    this->email = email;
    this->left = NULL;
    this->right = NULL;
}