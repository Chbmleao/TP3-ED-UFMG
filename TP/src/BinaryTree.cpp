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
        if (email.getEmailKey() < currentNode->email.getEmailKey())
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

Email BinaryTree::search(int emailKey, int userKey) {
    return this->searchRecursive(this->root, emailKey, userKey);
}

Email BinaryTree::searchRecursive(Node* currentNode, int emailKey, int userKey) {
    Email aux = Email();

    if (currentNode == NULL) 
        return aux;

    if (emailKey < currentNode->email.getEmailKey())
        return this->searchRecursive(currentNode->left, emailKey, userKey);
    else if (emailKey > currentNode->email.getEmailKey())
        return this->searchRecursive(currentNode->right, emailKey, userKey);
    else if (userKey == currentNode->email.getUserKey())
        return currentNode->email;
    else
        return aux;
}

bool BinaryTree::remove(int emailKey, int userKey) {
    return this->removeRecursive(this->root, emailKey, userKey);
}

bool BinaryTree::removeRecursive(Node* &currentNode, int emailKey, int userKey) {
    Node *aux;

    if (currentNode == NULL) {
        avisoAssert(currentNode == NULL, "Email does not exist");
        return false;
    }
    if (emailKey < currentNode->email.getEmailKey())
        return removeRecursive(currentNode->left, emailKey, userKey);
    else if (emailKey > currentNode->email.getEmailKey())
        return removeRecursive(currentNode->right, emailKey, userKey);
    else if (userKey == currentNode->email.getUserKey()){
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
    else
        return false;
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