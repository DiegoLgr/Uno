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

int Expr::eval( void) const{
    if (token.type == TokenType::NUMBER)
        return std::stoi( token.lexeme);

    switch (token.type){
        case TokenType::PLUS:
            return left_child->eval() + right_child->eval();
        case TokenType::MINUS:
            return left_child->eval() - right_child->eval();
        case TokenType::STAR:
            return left_child->eval() * right_child->eval();
        case TokenType::SLASH:
            return left_child->eval() / right_child->eval();
    }
}

