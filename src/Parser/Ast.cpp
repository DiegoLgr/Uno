#include <string>
#include <iostream>
#include <memory>

#include "Token.h"

typedef struct Node Node;
struct Node {
    const Token token;
    Node* child1;
    Node* child2;

    std::string toString();
};

std::string Node::toString(){
    std::string s =" (";
    if (child1) s = s + child1->toString();
    if (token.lexeme != "")  s = s + " " + token.lexeme;
    if (child2) s = s + " " + child2->toString();
    return s + ")";
}

Node* f( Token t, Node* c1 = 0, Node* c2 = 0){
    return new Node{ t, c1, c2 };
}

void cleanStack (void) {
    int list[200] = {0};
    for (auto i:list) std::cout << i;
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
int main( void){
    Node *ast = g();
    std::cout << ast->toString() << "\n";

    return 0;
}
