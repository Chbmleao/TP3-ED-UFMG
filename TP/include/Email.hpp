#ifndef EMAILHPP
#define EMAILHPP

#include <string>
#include <iostream>
#include "msgassert.hpp"

class Email {
    public:
        Email();
        Email(int emailKey, int userKey, std::string message);
        int getEmailKey();
        int getUserKey();
        std::string getMessage();
        void print();

    private:
        int emailKey;
        int userKey;
        std::string message;

    friend class Node;
};

#endif