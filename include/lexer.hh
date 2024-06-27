#pragma once

#include <optional>
#include <string>
#include <vector>

namespace distLang {
enum class TokenType {
    ret,            // return
    _for,           // for keyword
    int8,           // 8 bit integer
    int16,          // 16 bit integer
    int32,          // 32 bit integer
    int64,          // 64 bit integer
    int128,         // 128 bit integer
    split,          // split keyword
    none,           // none type
    int_lit,        // integer literal
    open_curl,      // Open curly brace
    close_curl,     // Close curly brace
    open_block,     // Open block brace
    close_block,    // Close block brace
    open_paren,     // Open parentheses
    close_paren,    // Close parentheses
    add,            // Addition operator
    sub,            // Subtraction operator
    mult,           // Multiplication operator
    div,            // Division operator
    modulo,         // Modulo operator
    assn,           // Assignment operator
    is_eq,          // Equality operator
    is_not_eq,      // Not equal operator
    negate,         // Not operator
    gt,             // Greater than
    lt,             // Less than
    gte,            // Greater than or equal to
    lte,            // Less than or equal to
    add_assn,       // Addition compound assignment
    sub_assn,       // Subtraction compound assignment
    mult_assn,      // Multiplication compound assignment
    div_assn,       // Division compounnd assignment
    modulo_assn,    // Modulo compound assignment
    semi,           // Semicolon
    _char,
    _string,
    _bool,
    float16,
    float32,
    float64,
    _struct,
    _main,
    _unsigned,
    identifier
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

struct TokenCategorizer {
    std::string value;
    TokenType type;
};

const TokenCategorizer tokenCategories[] = {
    {"int8", TokenType::int8},
    {"int16", TokenType::int16},
    {"int32", TokenType::int32},
    {"int64", TokenType::int64},
    {"int128", TokenType::int128},
    {"char", TokenType::_char},
    {"string", TokenType::_string},
    {"bool", TokenType::_bool},
    {"float16", TokenType::float16},
    {"float32", TokenType::float32},
    {"float64", TokenType::float64},
    {"struct", TokenType::_struct},
    {"main", TokenType::_main},
    {"split", TokenType::split},
    {"unsigned", TokenType::_unsigned}
};

std::vector<Token> tokenize(const char *filepath);

};