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

std::list<std::string> Scanner::scanTokens( void){
    std::list<std::string> li = {source};
    return li;
}
