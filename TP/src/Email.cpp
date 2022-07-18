#include "Email.hpp"
#include "memlog.hpp"

Email::Email() {
    this->emailKey = -1;
    this->userKey = -1;
    this->message = "";
}

Email::Email(int emailKey, int userKey, std::string message) {
    erroAssert(userKey >= 0, "User key must be a positive number.");
    erroAssert(emailKey >= 0, "Email key must be a positive number.");
    this->emailKey = emailKey;
    this->userKey = userKey;
    this->message = message;
    
    ESCREVEMEMLOG((long int) (&(this->emailKey)), sizeof(int), this->userKey);
}

int Email::getEmailKey() {
    LEMEMLOG((long int) (&(this->emailKey)), sizeof(int), this->userKey);
    return this->emailKey;
}

int Email::getUserKey() {
    return this->userKey;
}

std::string Email::getMessage() {
    return this->message;
}

void Email::print() {
    std::cout << "EmailKey: ";
    std::cout << this->emailKey;
    std::cout << " UserKey: ";
    std::cout << this->userKey << " - ";
    std::cout << this->message << std::endl;
}