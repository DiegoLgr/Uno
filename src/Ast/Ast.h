#ifndef ASTNODE_H
#define ASTNODE_H

class Ast {
    public:
        Ast( void);
        Ast( Token token);
        Ast( Token token, std::unique_ptr<Ast> left_child,
                            std::unique_ptr<Ast> right_child);
        std::string toString( void) const;

    private:
        Token token;
        std::unique_ptr<Ast> left_child;
        std::unique_ptr<Ast> right_child;
};

#endif
