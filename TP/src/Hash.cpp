#include "Hash.hpp"

Hash_BT::Hash_BT(int tableSize) {
    erroAssert(tableSize > 0, "Null dimension");

    this->tableSize = tableSize;
    this->table = (BinaryTree*) malloc(this->tableSize * sizeof(BinaryTree));

    erroAssert(this->table!=NULL, "Malloc failed");
}

int Hash_BT::hash(int key) {
    erroAssert(key >= 0, "User key must be a positive number.");
    return key % this->tableSize;
}

// search an email in the tree and returns it
// if the search fails, returns an empty email
Email* Hash_BT::search(int userKey, int emailKey) {
    erroAssert(userKey >= 0, "User key must be a positive number.");
    erroAssert(emailKey >= 0, "Email key must be a positive number.");

    int pos;
    Email* email;
    pos = this->hash(userKey);

    email = this->table[pos].search(emailKey, userKey);
    return email;
}

// inserts an email in the hash table
int Hash_BT::insert(int userKey, Email* email) {
    erroAssert(userKey >= 0, "User key must be a positive number.");
    erroAssert(email->getEmailKey() >= 0, "Email key must be a positive number.");

    int pos;
    Email* aux;

    aux = this->search(userKey, email->getEmailKey());
    erroAssert(aux->getMessage().empty(), "Email already exists.");

    pos = this->hash(userKey);
    this->table[pos].insert(email);

    return pos;
}

// remove an email in the tree and returns true if suceeded or false if failed
bool Hash_BT::remove(int userKey, int emailKey) {
    avisoAssert(userKey >= 0, "User key must be a positive number.");
    avisoAssert(emailKey >= 0, "Email key must be a positive number.");

    int pos;

    pos = this->hash(userKey);
    return this->table[pos].remove(emailKey, userKey);
}

// print all the e-mails in the hash table
void Hash_BT::print() {
    for (int i = 0; i < this->tableSize; i++) {
        this->table->printInOrder();
    }   
}