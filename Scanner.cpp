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
    std::list<Token> li {Token {ELSE, "else", 1}};
    return li;
}
