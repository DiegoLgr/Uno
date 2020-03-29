#include <iostream>
#include <memory>
#include <vector>

#include "Interpreter.h"
#include "../Token.h"
#include "../Ast/Ast.h"
#include "../Scanner/Scanner.h"
#include "../Parser/Parser.h"

Interpreter::Interpreter ( void){
    has_error = false;
};

void Interpreter::run( std::string source){
    Scanner scanner{ source};
    scanner.scanTokens();
    auto tokens = scanner.getTokens();

    Parser parser{ tokens};
    auto ast = parser.getAst();

    std::cout << ast->toString() << std::endl;
}

void Interpreter::error( int line, std::string mssg){
    std::cout << "[line " << line << " ] Error : " << mssg;
    has_error = true;
}
