#include <string>
#include <iostream>
#include <memory>

#include "Token.h"
#include "AstNode.h"


AstNode::AstNode( Token token) : token{token} {};

AstNode::AstNode( Token token, std::unique_ptr<AstNode> left_child,
                  std::unique_ptr<AstNode> right_child) :
    token{token},
    left_child{ move(left_child) },
    right_child{ move(right_child) }
{};

std::string AstNode::toString( void) const{
    std::string s =" (";
    if (left_child) s = s + left_child->toString();
    if (token.lexeme != "")  s = s + " " + token.lexeme;
    if (right_child) s = s + " " + right_child->toString();
    return s + ")";
}

