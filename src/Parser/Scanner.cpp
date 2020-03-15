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

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <list>
#include <cassert>

Scanner::Scanner( std::string src){
    source = src;
    line = 0;
    current = source.begin();
    start = current;
    error = false;
    keywords["and"] =    AND;
    keywords["class"] =  CLASS;
    keywords["else"] =   ELSE;
    keywords["false"] =  FALSE;
    keywords["for"] =    FOR;
    keywords["fun"] =    FUN;
    keywords["if"] =     IF;
    keywords["nil"] =    NIL;
    keywords["or"] =     OR;
    keywords["print"] =  PRINT;
    keywords["return"] = RETURN;
    keywords["super"] =  SUPER;
    keywords["this"] =   THIS;
    keywords["true"] =   TRUE;
    keywords["var"] =    VAR;
    keywords["while"] =  WHILE;
};

std::list<Token> Scanner::getTokens( void){
    return tokens;
}

void Scanner::scanTokens( void){
    while (!(current >= source.end())){
        start = current;
        Token t = nextToken();
        if (t.getType() != COMMENT && t.getType() != WHITE){
            tokens.push_back( t);
        }
    }
    tokens.push_back( Token {EOFF, "end", line});
}

Token Scanner::nextToken( void){
    int token_id = -1;
    char c = *current++;
    switch (c){
        //Whitespace.
        case '\n': line++; //Fallthrough.
        case ' ': //Fallthrough.
        case '\r': //Fallthrough.
        case '\t': token_id = WHITE; break;
        //Operators
        case '(': token_id = LEFT_PAREN; break;
        case ')': token_id = RIGHT_PAREN; break;
        case '{': token_id = LEFT_BRACE; break;
        case '}': token_id = RIGHT_BRACE; break;
        case ',': token_id = COMMA; break;
        case '.': token_id = DOT; break;
        case '-': token_id = MINUS; break;
        case '+': token_id = PLUS; break;
        case ';': token_id = SEMICOLON; break;
        case '*': token_id = STAR; break;
        case '=': token_id = followedBy('=') ? EQUAL_EQUAL : EQUAL; break;
        case '!': token_id = followedBy('=') ? BANG_EQUAL : BANG; break;
        case '<': token_id = followedBy('=') ? LESS_EQUAL : LESS; break;
        case '>': token_id = followedBy('=') ? GREATER_EQUAL : GREATER; break;
        case '/': token_id = followedBy('/') ? scanComment() : SLASH; break;
        case '"': token_id = scanComment(); break;
        default:
            if (isdigit( c)) token_id = scanNumber();
            else if (isalpha( c) || c == '_') token_id = scanWord();
            else token_id = ERROR; error = true;
    }
    std::string lexeme = std::string( start, current);
    return Token{ token_id, lexeme, line };
}

bool Scanner::followedBy( char c){
    if (*current++ == c){
        return true;
    }else {
        --current;
        return false;
    }
}

int Scanner::scanComment( void){
    while (*current++ != '\n') continue;
    return COMMENT;
};

int Scanner::scanNumber( void){
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
    return NUMBER;
};

int Scanner::scanWord( void){
    while (isalpha( *current++)) continue;
    std::map<std::string,int>::iterator it;
    it = keywords.find( std::string( start, current));
    if (it != keywords.end()){
        return it->second;
    }else {
        return IDENTIFIER;
    }
};
