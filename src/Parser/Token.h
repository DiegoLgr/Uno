#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <array>

enum class TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    COMMENT, WHITE, EOFF, ERROR
};
struct Token{
    /*
     * Bundle of all the information corresponding to a lexeme.
     *
     * Components: the string corespondin to the lexeme, its type (Whether it is
     * a number, a plus sign...), and its line number in the source file.
     *
     * Terminology used:
     *      lexeme:  A meaningfull secuence of one or more characters such that
     *               it is imposible to find in it a substring with meaning.
     */
        TokenType type;
        std::string lexeme;
        int line; //<The line in the source file in wich the token has been found.
};

std::array<TokenType, 1> left_associative{
    TokenType::MINUS
};

#endif
