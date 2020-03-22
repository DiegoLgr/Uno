#include <string>
#include <iostream>
#include <vector>

#include "Token.h"
#include "Ast.h"


Node* f( Token t, Node* c1 = 0, Node* c2 = 0){
    return new Node{ t, c1, c2 };
}

void cleanStack (void) {
    int vector[200] = {0};
    for (auto i:vector) std::cout << i;
    std::cout << std::endl;
}

Node* g(){
    Token t1 { TokenType::NUMBER, "1", 1 };
    Token t2 { TokenType::NUMBER, "2", 1 };
    Token t3 { TokenType::PLUS, "+", 1 };

    cleanStack();
    Node *ast1 = f(t1);
    cleanStack();
    Node *ast2 = f(t2);
    cleanStack();

    return f( t3, ast1, ast2);
}

std::vector <Token> scan( void){
    std::vector <Token> l;
    l.push_back( Token{ TokenType::NUMBER, "1" });
    l.push_back( Token{ TokenType::PLUS, "+" });
    l.push_back( Token{ TokenType::NUMBER, "2" });
    l.push_back( Token{ TokenType::STAR, "*" });
    l.push_back( Token{ TokenType::NUMBER, "3" });
    return l;
}

Node* parse( std::vector<Token> tokens, int start, int end, TokenType operation){
    for (int i = start; i < end; ++i){
        if (tokens[i].type == operation){
            Node* child1 = parse( tokens, start, i, TokenType::STAR);
            Node* child2 = parse( tokens, i, end, TokenType::PLUS);
            return new Node{ tokens[i], child1, child2 };
        }
    }
    return nullptr;
}

int main( void){
    //Node *ast = g();
    //std::cout << ast->toString() << "\n";
    std::vector <Token> l = scan();

    return 0;
}
