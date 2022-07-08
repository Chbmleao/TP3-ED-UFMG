#ifndef BINARYTREEHPP
#define BINARYTREEHPP

#include "Node.hpp"

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(Email email);
        void printInOrder();
        void clean();
        Email search(int key);
        bool remove(int key);

    private:
        void insertRecursive(Node* &currentNode, Email email);
        void printInOrderRecursive(Node* currentNode);
        void cleanRecursive(Node* currentNode);
        Email searchRecursive(Node* currentNode, int key);
        bool removeRecursive(Node* &currentNode, int key);
        void previous(Node* q, Node* &r);
        Node *root;

};

#endif