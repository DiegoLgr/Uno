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
    keywords["and"] =    TokenType::AND;
    keywords["class"] =  TokenType::CLASS;
    keywords["else"] =   TokenType::ELSE;
    keywords["false"] =  TokenType::FALSE;
    keywords["for"] =    TokenType::FOR;
    keywords["fun"] =    TokenType::FUN;
    keywords["if"] =     TokenType::IF;
    keywords["nil"] =    TokenType::NIL;
    keywords["or"] =     TokenType::OR;
    keywords["print"] =  TokenType::PRINT;
    keywords["return"] = TokenType::RETURN;
    keywords["super"] =  TokenType::SUPER;
    keywords["this"] =   TokenType::THIS;
    keywords["true"] =   TokenType::TRUE;
    keywords["var"] =    TokenType::VAR;
    keywords["while"] =  TokenType::WHILE;
};

std::list<Token> Scanner::getTokens( void){
    return tokens;
}

void Scanner::scanTokens( void){
    while (!(current >= source.end())){
        start = current;
        Token t = nextToken();
        if (t.type != TokenType::COMMENT && t.type != TokenType::WHITE){
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
        case '(': token_id = TokenType::LEFT_PAREN; break;
        case ')': token_id = TokenType::RIGHT_PAREN; break;
        case '{': token_id = TokenType::LEFT_BRACE; break;
        case '}': token_id = TokenType::RIGHT_BRACE; break;
        case ',': token_id = TokenType::COMMA; break;
        case '.': token_id = TokenType::DOT; break;
        case '-': token_id = TokenType::MINUS; break;
        case '+': token_id = TokenType::PLUS; break;
        case ';': token_id = TokenType::SEMICOLON; break;
        case '*': token_id = TokenType::STAR; break;
        case '=': token_id = followedBy('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL; break;
        case '!': token_id = followedBy('=') ? TokenType::BANG_EQUAL : TokenType::BANG; break;
        case '<': token_id = followedBy('=') ? TokenType::LESS_EQUAL : TokenType::LESS; break;
        case '>': token_id = followedBy('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER; break;
        case '/': token_id = followedBy('/') ? scanComment() : TokenType::SLASH; break;
        case '"': token_id = scanComment(); break;
        default:
            if (isdigit( c)) token_id = scanNumber();
            else if (isalpha( c) || c == '_') token_id = scanWord();
            else token_id = TokenType::ERROR; error = true;
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

TokenType Scanner::scanComment( void){
    while (*current++ != '\n') continue;
    return TokenType::COMMENT;
};

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

TokenType Scanner::scanWord( void){
    while (isalpha( *current++)) continue;
    std::map<std::string, TokenType>::iterator it;
    it = keywords.find( std::string( start, current));
    if (it != keywords.end()){
        return it->second;
    }else {
        return TokenType::IDENTIFIER;
    }
};
