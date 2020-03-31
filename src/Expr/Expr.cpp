#include <string>
#include <iostream>
#include <memory>

#include "../Token.h"
#include "Expr.h"


Expr::Expr( void) : token{ Token{} } {};
Expr::Expr( Token token) : token{ token } {};

Expr::Expr( Token token, std::unique_ptr<Expr> left_child,
                  std::unique_ptr<Expr> right_child) :
    token{token},
    left_child{ move(left_child) },
    right_child{ move(right_child) }
{};

std::string Expr::toString( void) const{
    std::string s =" (";
    if (left_child) s = s + left_child->toString();
    if (token.lexeme != "")  s = s + " " + token.lexeme;
    if (right_child) s = s + " " + right_child->toString();
    return s + ")";
}

