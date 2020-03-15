
#include "Scanner.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <list>

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
    /*
     * Creates a list of tokens from the scanner's source string.
     */
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
    char c = *current++;
    int token_id = -1;
    switch (c){
        //Whitespace.
        case '\n': line++;
        case ' ':
        case '\r':
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
            if (c >= '0' && c <= '9') token_id = scanNumber();
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
    while (*current++ != '\n');
    return COMMENT;
};

int Scanner::scanNumber( void){
    while (isdigit( *current++))
    if (*current++ == '.' && isdigit( *current++)){
        while (isdigit( *current++));
    }else {
        --current;
        --current; //If '.' is not followed by a number, go back to it.
    }
    return NUMBER;
};

int Scanner::scanWord( void){
    while (isalpha( *current++));
    std::map<std::string,int>::iterator it = keywords.find( std::string( start, current));
    if (it != keywords.end()){
        return it->second;
    }else {
        return IDENTIFIER;
    }
};
