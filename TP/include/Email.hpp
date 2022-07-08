#ifndef EMAILHPP
#define EMAILHPP

#include <string>
#include <iostream>

class Email {
    public:
        Email();
        Email(int key, std::string message);
        int getKey();
        std::string getMessage();
        void print();

    private:
        int key;
        std::string message;

    friend class Node;
};

#endif