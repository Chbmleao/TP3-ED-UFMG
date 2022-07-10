#include "Hash.hpp"
#include <fstream>

void sendEmail(std::ifstream &inputFile, std::ofstream &outputFile, Hash_BT *hash) {
    std::string word, emailMessage;
    int userKey, emailKey, messageSize;

    inputFile >> userKey;
    inputFile >> emailKey;
    inputFile >> messageSize;

    for (int i = 0; i < messageSize; i++) {
        inputFile >> word;
        emailMessage += word;
        emailMessage += " ";
    }
    emailMessage.pop_back(); // removes the last space

    Email email = Email(emailKey, emailMessage); // creates the email to insert in the hash table

    int pos = hash->insert(userKey, email);

    outputFile << "OK: MENSAGEM " << emailKey << " PARA " << userKey << " ARMAZENADA EM " << pos << std::endl;
}

void consultEmail(std::ifstream &inputFile, std::ofstream &outputFile, Hash_BT *hash) {
    int userKey, emailKey;

    inputFile >> userKey;
    inputFile >> emailKey;

    Email email = hash->search(userKey, emailKey);

    if (email.getMessage().empty())
        outputFile << "CONSULTA " << userKey << " " << emailKey << ": MENSAGEM INEXISTENTE" << std::endl;
    else
        outputFile << "CONSULTA " << userKey << " " << emailKey << ": " << email.getMessage() << std::endl;
}

void removeEmail(std::ifstream &inputFile, std::ofstream &outputFile, Hash_BT *hash) {
    int userKey, emailKey;

    inputFile >> userKey;
    inputFile >> emailKey;

    if (hash->remove(userKey, emailKey))
        outputFile << "OK: MENSAGEM APAGADA" << std::endl;
    else 
        outputFile << "ERRO: MENSAGEM INEXISTENTE" << std::endl;
}

void readInputFile(std::ifstream &inputFile, std::ofstream &outputFile) {
    int intAux;
    std::string strAux;
    inputFile >> intAux;
    Hash_BT *hash = new Hash_BT(intAux);

    while (inputFile.good()) {
        strAux = "";
        inputFile >> strAux;
        if (strAux == "ENTREGA")
            sendEmail(inputFile, outputFile, hash);
        if (strAux == "CONSULTA")
            consultEmail(inputFile, outputFile, hash);
        if (strAux == "APAGA")
            removeEmail(inputFile, outputFile, hash);
    }
}

int main(int argc, char const *argv[]) {

    std::ifstream inputFile("entrada.txt");
    std::ofstream outputFile("saida.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        readInputFile(inputFile, outputFile);
    } else {
        erroAssert(inputFile.is_open(), "Could not open the Input File.");
        erroAssert(outputFile.is_open(), "Could not open the output file.");
    }

    return 0;
}