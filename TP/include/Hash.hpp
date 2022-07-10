#ifndef HASHHPP
#define HASHHPP

#include "BinaryTree.hpp"

class Hash_BT {
    public:
        Hash_BT(int tableSize);
        Email search(int userKey, int emailKey);
        int insert(int userKey, Email email);
        bool remove(int userKey, int emailKey);
        void print();

    private:
        int tableSize;
        int hash(int key);
        BinaryTree *table;
};


#endif