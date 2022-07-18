#include <fstream>
#include <getopt.h>
#include <string.h>
#include "Hash.hpp"
#include "memlog.hpp"

typedef struct opt{
    std::string logName;
    int regmem;
    std::string inputFile;
    std::string outputFile;
} opt_tipo;

// print the use options
void use(){
    fprintf(stderr,"Main\n");
    fprintf(stderr,"\t-i entrada.txt \t(arquivo de entrada)\n");
    fprintf(stderr,"\t-o saida.txt \t(arquivo de entrada)\n");
    fprintf(stderr,"\t-p log.out\t(registro de desempenho)\n");
    fprintf(stderr,"\t-l \t\t(padrao de acesso e localidade)\n");
}

// read command line options and initialize variables
void parse_args(int argc,char ** argv, opt_tipo * opt){
    // external variables
    extern char * optarg;
    // auxiliar variable
    int c;

    // global variables inicialization
    opt->regmem = 0;
    opt->logName[0] = 0;
    opt->inputFile = "entrada.txt";
    opt->outputFile = "saida.txt";
    
    // getopt - letter indicates option, : indicates parameter
    while ((c = getopt(argc, argv, "i:o:p:lh")) != EOF) {
        switch(c) {
            case 'i':
                opt->inputFile = std::string(optarg);
                break;
            case 'o':
                opt->outputFile = std::string(optarg);
                break;
            case 'p': 
                opt->logName = std::string(optarg);
                break;
            case 'l': 
                opt->regmem = 1;
                break;
            case 'h':
            default:
                use();
                exit(1);
        }
    }

    // verify the options consistency
    if (opt->inputFile.empty()) {
        opt->inputFile = "entrada.txt";
        avisoAssert(1, "Input File was not passed as parameter, 'entrada.txt' file will be used.");
    }  
    if (opt->outputFile.empty()) {
        opt->outputFile = "saida.txt";
        avisoAssert(1, "Output File was not passed as parameter, 'saida.txt' file will be used.");
    }
    if (opt->logName.empty()) {
        opt->logName = "/tmp/tp3log.out";
        avisoAssert(1, "Log File Name was not passed as parameter, '/tmp/tp3log.out' value will be used.");
    }
}

void sendEmail(std::ifstream &inputFile, std::ofstream &outputFile, Hash_BT *hash) {
    std::string word, emailMessage;
    int userKey, emailKey, messageSize;

    inputFile >> userKey;
    inputFile >> emailKey;
    inputFile >> messageSize;

    erroAssert(messageSize <= 200, "The message has more than 200 words.");

    for (int i = 0; i < messageSize; i++) {
        inputFile >> word;
        emailMessage += word;
        emailMessage += " ";
    }
    emailMessage.pop_back(); // removes the last space

    Email *email = new Email(emailKey, userKey, emailMessage); // creates the email to insert in the hash table

    int pos = hash->insert(userKey, email);

    outputFile << "OK: MENSAGEM " << emailKey << " PARA " << userKey << " ARMAZENADA EM " << pos << std::endl;
}

void consultEmail(std::ifstream &inputFile, std::ofstream &outputFile, Hash_BT *hash) {
    int userKey, emailKey;

    inputFile >> userKey;
    inputFile >> emailKey;

    Email* email = hash->search(userKey, emailKey);

    if (email->getMessage().empty())
        outputFile << "CONSULTA " << userKey << " " << emailKey << ": MENSAGEM INEXISTENTE" << std::endl;
    else
        outputFile << "CONSULTA " << userKey << " " << emailKey << ": " << email->getMessage() << std::endl;
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

int main(int argc, char **argv) {
    opt_tipo opt;
    // evaluate command line
    parse_args(argc, argv, &opt);

    // access log initialization
    char logName[opt.logName.size()];
    strcpy(logName, opt.logName.c_str());
    iniciaMemLog(logName);

    // activate or not the access log
    if (opt.regmem)
        ativaMemLog();
    else   
        desativaMemLog();

    defineFaseMemLog(0);

    std::ifstream inputFile(opt.inputFile);
    std::ofstream outputFile(opt.outputFile);

    if (inputFile.is_open() && outputFile.is_open()) {
        readInputFile(inputFile, outputFile);
    } else {
        erroAssert(inputFile.is_open(), "Could not open the Input File.");
        erroAssert(outputFile.is_open(), "Could not open the output file.");
    }

    inputFile.close();
    outputFile.close();

    finalizaMemLog();

    return 0;
}