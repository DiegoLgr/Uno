#include "Scanner.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <list>

Scanner::Scanner( std::string src){
    source = src;
};

std::list<Token> Scanner::scanTokens( void){
    std::list<Token> tokens;
    tokens.push_back( Token {ELSE, "else", 1});
    tokens.push_back( Token {PRINT, "print", 1});
    return tokens;
}
