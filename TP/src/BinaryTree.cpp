#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
    this->root = NULL;
}

BinaryTree::~BinaryTree() {
    this->clean();
}

// inserts an email in the tree
void BinaryTree::insert(Email *email) {
    erroAssert(email->getEmailKey() >= 0, "Email key must be a positive number.");
    this->insertRecursive(this->root, email);
}

void BinaryTree::insertRecursive(Node* &currentNode, Email *email) {
    if (currentNode == NULL) 
        currentNode = new Node(email);
    else {
        if (email->getEmailKey() < currentNode->email->getEmailKey())
            this->insertRecursive(currentNode->left, email);
        else
            this->insertRecursive(currentNode->right, email);
    }
}

// print all the e-mails in the tree
void BinaryTree::printInOrder() {
    avisoAssert(this->root != NULL, "The tree is empty!");
    this->printInOrderRecursive(this->root);
}

void BinaryTree::printInOrderRecursive(Node *currentNode) {
    if (currentNode != NULL) {
        this->printInOrderRecursive(currentNode->left);
        currentNode->email->print();
        this->printInOrderRecursive(currentNode->right);
    }
}

// desallocates the nodes
void BinaryTree::clean() {
    avisoAssert(this->root != NULL, "The tree is already empty!");
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

// search an email in the tree and returns it
// if the search fails, returns an empty email
Email* BinaryTree::search(int emailKey, int userKey) {
    erroAssert(userKey >= 0, "User key must be a positive number.");
    erroAssert(emailKey >= 0, "Email key must be a positive number.");
    return this->searchRecursive(this->root, emailKey, userKey);
}

Email* BinaryTree::searchRecursive(Node* currentNode, int emailKey, int userKey) {
    Email* aux = new Email();

    if (currentNode == NULL) 
        return aux;

    if (emailKey < currentNode->email->getEmailKey())
        return this->searchRecursive(currentNode->left, emailKey, userKey);
    else if (emailKey > currentNode->email->getEmailKey())
        return this->searchRecursive(currentNode->right, emailKey, userKey);
    else if (userKey == currentNode->email->getUserKey())
        return currentNode->email;
    else
        return aux;
}

// remove an email in the tree and returns true if suceeded or false if failed
bool BinaryTree::remove(int emailKey, int userKey) {
    avisoAssert(userKey >= 0, "User key must be a positive number.");
    avisoAssert(emailKey >= 0, "Email key must be a positive number.");
    return this->removeRecursive(this->root, emailKey, userKey);
}

bool BinaryTree::removeRecursive(Node* &currentNode, int emailKey, int userKey) {
    Node *aux;

    if (currentNode == NULL) {
        avisoAssert(currentNode == NULL, "Email does not exist");
        return false;
    }
    if (emailKey < currentNode->email->getEmailKey())
        return removeRecursive(currentNode->left, emailKey, userKey);
    else if (emailKey > currentNode->email->getEmailKey())
        return removeRecursive(currentNode->right, emailKey, userKey);
    else if (userKey == currentNode->email->getUserKey()){
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

// helper function to restructure the tree after a removal
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