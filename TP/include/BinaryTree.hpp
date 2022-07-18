#ifndef BINARYTREEHPP
#define BINARYTREEHPP

#include "Node.hpp"

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(Email *email);
        void printInOrder();
        void clean();
        Email* search(int emailKey, int userKey);
        bool remove(int emailKey, int userKey);

    private:
        void insertRecursive(Node* &currentNode, Email *email);
        void printInOrderRecursive(Node* currentNode);
        void cleanRecursive(Node* currentNode);
        Email* searchRecursive(Node* currentNode, int emailKey, int userKey);
        bool removeRecursive(Node* &currentNode, int emailKey, int userKey);
        void previous(Node* q, Node* &r);
        Node *root;

};

#endif