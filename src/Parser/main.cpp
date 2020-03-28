#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Token.h"
#include "AstNode.h"
#include "Parser.h"
#include "Scanner.h"


std::vector <Token> scan( void){
    std::string uno{ "1" };
    std::string dos{ "2" };
    std::string tres{ "3" };
    std::string mas{ "+" };
    std::string por{ "*" };
    std::vector<Token> l;
    l.push_back( Token{ TokenType::NUMBER, "1", 0 });
    l.push_back( Token{ TokenType::PLUS, "+", 0 });
    l.push_back( Token{ TokenType::NUMBER, "2", 0 });
    l.push_back( Token{ TokenType::STAR, "*", 0 });
    l.push_back( Token{ TokenType::NUMBER, "3", 0 });
    return l;
}

int main( void){
    std::string source = "1+2*3";
    Scanner scanner( source);
    scanner.scanTokens();
    auto tokenl = scanner.getTokens();
    std::vector<Token> tokenv;
    for (auto token : tokenl){
        if (token.type != TokenType::EOFF)
            tokenv.push_back( token);
    }

    // Wont work with the EOF at the end...
    Parser parser{ tokenv};
    std::unique_ptr<AstNode> ast = parser.getAst();
    std::cout << ast->toString() << std::endl;
    return 0;
}
