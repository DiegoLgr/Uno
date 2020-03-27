#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Token.h"
#include "AstNode.h"
#include "Parser.h"


std::vector <Token> scan( void){
    std::vector<Token> l;
    l.push_back( Token{ TokenType::NUMBER, "1" });
    l.push_back( Token{ TokenType::PLUS, "+" });
    l.push_back( Token{ TokenType::NUMBER, "2" });
    l.push_back( Token{ TokenType::STAR, "*" });
    l.push_back( Token{ TokenType::NUMBER, "3" });
    return l;
}

int main( void){
    std::vector<Token> tokens = scan();
    Parser parser{ tokens};
    AstNode ast = parser.getAst();
    std::cout << ast.toString() << std::endl;
    return 0;
}
