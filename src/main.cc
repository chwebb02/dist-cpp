#include <iostream>
#include <fstream>
#include "lexer.hh"

void printUsage(const char *programName) {
    std::cout << "Usage:\n\t" << programName << "<input file> [options]" << std::endl;
}

int main(int argc, char *argv[]) {
    using namespace distLang;

    if (argc < 2) {
        printUsage(argv[0]);
        exit(1);
    }

    std::vector<Token> tokens = tokenize(argv[1]);
}