#ifndef ASTNODE_H
#define ASTNODE_H

class AstNode {
    public:
        AstNode( void);
        AstNode( Token token);
        AstNode( Token token, std::unique_ptr<AstNode> left_child,
                            std::unique_ptr<AstNode> right_child);
        std::string toString( void) const;

    private:
        Token token;
        std::unique_ptr<AstNode> left_child;
        std::unique_ptr<AstNode> right_child;
};

#endif
