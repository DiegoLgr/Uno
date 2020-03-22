#include <string>
#include <iostream>

#include "Token.h"
#include "Ast.h"

std::string Node::toString(){
    std::string s =" (";
    if (child1) s = s + child1->toString();
    if (token.lexeme != "")  s = s + " " + token.lexeme;
    if (child2) s = s + " " + child2->toString();
    return s + ")";
}

