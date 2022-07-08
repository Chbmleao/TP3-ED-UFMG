#include "Hash.hpp"

Hash_BT::Hash_BT(int tableSize) {
    this->tableSize = tableSize;
    this->table = (BinaryTree*) malloc(this->tableSize * sizeof(BinaryTree));
}

int Hash_BT::hash(int key) {
    return key % this->tableSize;
}

Email Hash_BT::search(int userKey, int emailKey) {
    int pos;
    Email email;
    pos = this->hash(userKey);

    email = this->table[pos].search(emailKey);
    return email;
}

int Hash_BT::insert(int userKey, Email email) {
    int pos;
    Email aux;

    aux = this->search(userKey, email.getKey());
    erroAssert(aux.getMessage().empty(), "Email already exists.");

    pos = this->hash(userKey);
    this->table[pos].insert(email);

    return pos;
}

bool Hash_BT::remove(int userKey, int emailKey) {
    int pos;

    pos = this->hash(userKey);
    return this->table[pos].remove(emailKey);
}