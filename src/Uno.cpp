#include "Uno.h"
#include "Scanner.h"
#include <iostream>

Uno::Uno ( void){
    has_error = false;
};

void Uno::run( std::string source){
    Scanner scanner( source);
    scanner.scanTokens();
    std::list<Token> tokens = scanner.getTokens();

    for (Token token : tokens){
        std::cout << token.toString() << "\n";
    }
    std::cout << "\n";
}

void Uno::error( int line, std::string mssg){
    std::cout << "[line " << line << " ] Error : " << mssg;
    has_error = true;
}
