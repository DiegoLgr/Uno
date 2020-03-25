#include <string>
#include <iostream>

#include "Token.h"
#include "Ast.h"

class Ast {
    private:
        std::unique_ptr<AstNode> root;
};

class AstNode {
    public:
        AstNode( Token token, unique_ptr<AstNode> left_child,
                            unique_ptr<AstNode> right_child);
        void toString() const;

    private:
        Token token;
        std::unique_ptr<AstNode> left_child;
        std::unique_ptr<AstNode> right_child;
};

std::string Node::toString(){
    std::string s =" (";
    if (left_childe) s = s + left_childe->toString();
    if (token.lexeme != "")  s = s + " " + token.lexeme;
    if (right_child) s = s + " " + right_child->toString();
    return s + ")";
}

