#include <string>
#include <iostream>
#include <memory>

#include "../Token.h"
#include "Ast.h"


Ast::Ast( void) : token{ Token{} } {};
Ast::Ast( Token token) : token{ token } {};

Ast::Ast( Token token, std::unique_ptr<Ast> left_child,
                  std::unique_ptr<Ast> right_child) :
    token{token},
    left_child{ move(left_child) },
    right_child{ move(right_child) }
{};

std::string Ast::toString( void) const{
    std::string s =" (";
    if (left_child) s = s + left_child->toString();
    if (token.lexeme != "")  s = s + " " + token.lexeme;
    if (right_child) s = s + " " + right_child->toString();
    return s + ")";
}

