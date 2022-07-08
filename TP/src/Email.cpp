#include "Email.hpp"

Email::Email() {
    this->key = -1;
    this->message = "";
}

Email::Email(int key, std::string message) {
    this->key = key;
    this->message = message;
}

int Email::getKey() {
    return this->key;
}

std::string Email::getMessage() {
    return this->message;
}

void Email::print() {
    std::cout << this->key << " - ";
    std::cout << this->message << std::endl;
}