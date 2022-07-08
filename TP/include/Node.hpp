#ifndef NODEHPP
#define NODEHPP

#include "Email.hpp"

class Node {
    public:
        Node();
        Node(Email email);

    private:
        Email email;
        Node *left;
        Node *right;

    friend class BinaryTree;
};

#endif