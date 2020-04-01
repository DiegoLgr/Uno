/**
 * @file Scanner.cpp
 *
 * Scanner class.
 *
 * Recurrent special terminology used in this file:
 *      source: Alwais refers to the source code.
 *      scann:	It is used to mean that we advance in the source string and
 *		    process the value read. IMPORTANT: The iterator advances!!
 *      keyword: Every reserved word in uno.
 *
 */
#include "Scanner.h"


#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <cassert>


Scanner::Scanner( std::string src){
    source = src;
    line = 0;
    current = source.begin();
    start = current;
    error = false;
    scanTokens();
};

std::vector<Token> Scanner::getTokens( void){
    return tokens;
}

void Scanner::scanTokens( void){
    while (!(current >= source.end())){
        start = current;
        Token t = nextToken();
        if (t.type != TokenType::WHITE){
            tokens.push_back( t);
        }
    }
    tokens.push_back( Token {TokenType::EOFF, "end", line});
}

Token Scanner::nextToken( void){
    TokenType token_id;
    char c = *current++;
    switch (c){
        //Whitespace.
        case '\n': line++; //Fallthrough.
        case ' ': //Fallthrough.
        case '\r': //Fallthrough.
        case '\t': token_id = TokenType::WHITE; break;
        //Operators
        case '-': token_id = TokenType::MINUS; break;
        case '+': token_id = TokenType::PLUS; break;
        case '*': token_id = TokenType::STAR; break;
        case '/': token_id = TokenType::SLASH; break;
        default:
            if (isdigit( c)) token_id = scanNumber();
            else token_id = TokenType::ERROR; error = true;
    }
    std::string lexeme = std::string( start, current);
    return Token{ token_id, lexeme, line };
}

TokenType Scanner::scanNumber( void){
    /*
     * Real numbers and integer are treated in the same way.
     * A number always starts with a digit.
     * 0.980 -> right
     * .980 -> wrong
     */
    assert( isdigit( *(current-1))); //The first digit has already been consumed

    while (isdigit( *current++)) continue;
    if (*current++ == '.' && isdigit( *current++)){
        while (isdigit( *current++)) continue;
    }else {
        --current;
        --current; //Reset current to '.' if it is not followed by a number.
    }
    return TokenType::NUMBER;
};
