#ifndef EXPR_H
#define EXPR_H

#include <string>
#include <iostream>
#include <memory>

#include "../Uno.h"
class Expr {
    public:
        Expr( void);
        Expr( Token token);
        Expr( Token token, std::unique_ptr<Expr> left_child,
                            std::unique_ptr<Expr> right_child);
        std::string toString( void) const;
        int eval( void) const;

    private:
        Token token;
        std::unique_ptr<Expr> left_child;
        std::unique_ptr<Expr> right_child;
};

#endif
