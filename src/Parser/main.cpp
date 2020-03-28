#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Token.h"
#include "AstNode.h"
#include "Parser.h"
#include "Scanner.h"


int main( void){
    std::string source = "1+2*3";
    Scanner scanner( source);
    scanner.scanTokens();
    auto tokens = scanner.getTokens();

    Parser parser{ tokens };
    std::unique_ptr<AstNode> ast = parser.getAst();
    std::cout << ast->toString() << std::endl;
    return 0;
}
