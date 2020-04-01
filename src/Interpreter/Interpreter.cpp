#include "Interpreter.h"


Interpreter::Interpreter ( void){
    has_error = false;
};

void Interpreter::run( std::string source){
    Scanner scanner{ source};
    auto tokens = scanner.getTokens();

    Parser parser{ tokens};
    auto ast = parser.getExpr();

    std::cout << ast->eval() << std::endl;
}

void Interpreter::error( int line, std::string mssg){
    std::cout << "[line " << line << " ] Error : " << mssg;
    has_error = true;
}
