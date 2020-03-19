
#include <iostream>
#include <iostream>
#include <string>

#include "Ast.cpp"
#include "Token.h"


struct Printer: Visitor {
    std::string s {};

    void visit( const Expr &e) { e.accept( *this); }

    void visit( const Unary &e) {
        s.append( e.t.toString());
        visit( e.e1);
    }

    void visit( const Binary &e) {
        visit( e.e1);
        s.append( e.t.toString());
        visit( e.e2);
    }

    void visit( const Group &e) {
        s.append(" (");
        visit( e.e1);
        s.append(" )");
    }

    void visit( const Literal &e) {
        s.append( e.t.toString());
    }

    void print( void) const {
        std::cout << s << std::endl;
    }
};
