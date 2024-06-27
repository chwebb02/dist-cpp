#include "lexer.hh"

#include <fstream>
#include <sstream>
#include <iostream>

namespace distLang {
Token categorizeToken(const std::string& buffer) {
    Token out = {.type = TokenType::identifier, .value = buffer};

    for (int i = 0; i < sizeof(tokenCategories) / sizeof(TokenCategorizer); i++) {
        const TokenCategorizer& temp = tokenCategories[i];
        
        if (!buffer.compare(temp.value)) {
            return {.type = temp.type};
        }
    }

    return out;
}

std::vector<Token> tokenize(const char *filepath) {
    // Read file contents into string
    std::string contents;
    {
        std::ifstream input(filepath);
        std::stringstream contents_stream;
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    // Construct vector of tokens from file contents
    std::vector<Token> tokens;
    for (size_t i = 0; i < contents.length(); i++) {
        char c = contents.at(i);

        switch (c) {
            // Whitespace
            case ' ':
            case '\t':                        
            case '\n':
            case EOF:
                continue;
            
            // Single character tokens
            case '{':
                tokens.push_back({.type = TokenType::open_curl});
                break;
            case '}':
                tokens.push_back({.type = TokenType::close_curl});
                break;
            case '[':
                tokens.push_back({.type = TokenType::open_block});
                break;
            case ']':
                tokens.push_back({.type = TokenType::close_block});
                break;
            case '(':
                tokens.push_back({.type = TokenType::open_paren});
                break;
            case ')':
                tokens.push_back({.type = TokenType::close_paren});
                break;
            case ';':
                tokens.push_back({.type = TokenType::semi});
                break;

            // Arithmetic and compound assignment operators
            case '+':
                if (contents.at(i + 1) == '=') {
                    tokens.push_back({.type = TokenType::add_assn});
                    i += 1;
                } else {
                    tokens.push_back({.type = TokenType::add});
                }

                break;
            case '-':
                if (contents.at(i + 1) == '=') {
                    tokens.push_back({.type = TokenType::sub_assn});
                    i += 1;
                } else {
                    tokens.push_back({.type = TokenType::sub});
                }

                break;
            case '*':
                if (contents.at(i + 1) == '=') {
                    tokens.push_back({.type = TokenType::mult_assn});
                    i += 1;
                } else {
                    tokens.push_back({.type = TokenType::mult});
                }

                break;
            case '/':
                if (contents.at(i + 1) == '=') {
                    tokens.push_back({.type = TokenType::div_assn});
                    i += 1;
                } else {
                    tokens.push_back({.type = TokenType::div});
                }

                break;
            case '%':
                if (contents.at(i + 1) == '=') {
                    tokens.push_back({.type = TokenType::modulo_assn});
                    i += 1;
                } else {
                    tokens.push_back({.type = TokenType::modulo});
                }

                break;
            case '=':
                if (contents.at(i + 1) == '=') {
                    tokens.push_back({.type = TokenType::is_eq});
                    i += 1;
                } else {
                    tokens.push_back({.type = TokenType::assn});
                }

                break;

            default:
                std::cerr << "Invalid character detected at pos " << i;
                exit(EXIT_FAILURE);
        }
    }

    return tokens;
}
};