#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <array>

enum class TokenType {
    MINUS, PLUS, SLASH, STAR, NUMBER, ERROR, EOFF
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

#endif
