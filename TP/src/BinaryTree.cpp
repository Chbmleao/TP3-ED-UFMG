#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
    this->root = NULL;
}

BinaryTree::~BinaryTree() {
    this->clean();
}

void BinaryTree::insert(Email email) {
    this->insertRecursive(this->root, email);
}

void BinaryTree::insertRecursive(Node* &currentNode, Email email) {
    if (currentNode == NULL) 
        currentNode = new Node(email);
    else {
        if (email.getKey() < currentNode->email.getKey())
            this->insertRecursive(currentNode->left, email);
        else
            this->insertRecursive(currentNode->right, email);
    }
}

void BinaryTree::printInOrder() {
    erroAssert(this->root != NULL, "The tree is empty!");
    this->printInOrderRecursive(this->root);
}

void BinaryTree::printInOrderRecursive(Node *currentNode) {
    if (currentNode != NULL) {
        this->printInOrderRecursive(currentNode->left);
        currentNode->email.print();
        this->printInOrderRecursive(currentNode->right);
    }
}

void BinaryTree::clean() {
    this->cleanRecursive(this->root);
    this->root = NULL;
}

void BinaryTree::cleanRecursive(Node *currentNode) {
    if (currentNode == NULL) {
        this->cleanRecursive(currentNode->left);
        this->cleanRecursive(currentNode->right);
        delete currentNode;
    }
}

Email BinaryTree::search(int key) {
    return this->searchRecursive(this->root, key);
}

Email BinaryTree::searchRecursive(Node* currentNode, int key) {
    Email aux = Email();

    if (currentNode == NULL) 
        return aux;
    
    if (key < currentNode->email.getKey())
        return this->searchRecursive(currentNode->left, key);
    else if (key > currentNode->email.getKey())
        return this->searchRecursive(currentNode->right, key);
    else
        return currentNode->email;
}

bool BinaryTree::remove(int key) {
    return this->removeRecursive(this->root, key);
}

bool BinaryTree::removeRecursive(Node* &currentNode, int key) {
    Node *aux;

    if (currentNode == NULL) {
        avisoAssert(currentNode == NULL, "Email does not exist");
        return false;
    }
    if (key < currentNode->email.getKey())
        return removeRecursive(currentNode->left, key);
    else if (key > currentNode->email.getKey())
        return removeRecursive(currentNode->right, key);
    else {
        if (currentNode->right == NULL) {
            aux = currentNode;
            currentNode = currentNode->left;
            delete aux;
        }
        else if (currentNode->left == NULL) {
            aux = currentNode;
            currentNode = currentNode->right;
            delete aux;
        }
        else
            this->previous(currentNode, currentNode->left);
        return true;
    }
}

void BinaryTree::previous(Node* q, Node* &r) {
    if (r->right != NULL) {
        this->previous(q, r->right);
        return;
    }
    
    q->email = r->email;
    q = r;
    r = r->left;
    delete q;
}