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
    current = source.begin();
    start = current;
    scanTokens();
};

std::vector<std::unique_ptr<Token>> Scanner::getTokens( void){
    return move( tokens);
}

void Scanner::scanTokens( void){
    do {
        tokens.push_back( nextToken());
    } while (!(current >= source.end()));
}

std::unique_ptr<Token> Scanner::nextToken( void){
    while (is_white( *current++)){ continue; }

    start = --current;
    if (isdigit( *current)){
        return scanNumber();
    }else if (is_operator( *current)){
        return match_operator( *current);
    }else{
        throw std::runtime_error("Unknown symbol");
    }
}

std::unique_ptr<Token> Scanner::scanNumber( void){
    /*
     * Real numbers and integer are treated in the same way.
     * A number always starts with a digit.
     * 0.980 -> right
     * .980 -> wrong
     */
    assert( !isdigit( *(current-1)));
    assert( isdigit( *current)); //This has to be the first digit.
    while (isdigit( *++current)) continue;
    if (*current == '.' && isdigit( *(current+1) )){
        current++; //Skip the '.'
        while (isdigit( *++current)) continue;
    }
    assert( isdigit( *(current-1))); //Te character before this is a digit.
    assert( !isdigit( (*current))); //But this is not.

    auto value = std::stof( std::string{start, current});
    return std::make_unique<Number>( value);
}

std::unique_ptr<Token> Scanner::match_operator ( char op){
    // This token is consumed.
    std::unique_ptr<Token> t;
    switch (op){
        case '+': t = std::make_unique<Plus>(); break;
        case '-': t = std::make_unique<Minus>(); break;
        case '*': t = std::make_unique<Star>(); break;
        case '/': t = std::make_unique<Slash>(); break;
        default: throw std::runtime_error{"op not op"};
    }
    current++;
    return move( t);
}

bool Scanner::is_white( char c) const {
    switch(c){
        case ' ': // Fallthrogh.
        case '\t': return true;
        default: return false;
    }
}

bool Scanner::is_operator( char c) const{
    switch (c){
        case '+': // fallthrow;
        case '-': // fallthrow;
        case '*': // fallthrow;
        case '/': return true;
        default: return false;
    }
}
