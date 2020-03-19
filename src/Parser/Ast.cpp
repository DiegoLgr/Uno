#include <string>

#include "Token.h"

typedef struct Expr Expr;
typedef struct Unary Unary;
typedef struct Binary Binary;
typedef struct Group Group;
typedef struct Literal Literal;

struct Visitor {
    virtual void visit( Expr &e) = 0;
    virtual void visit( const Unary &e) = 0;
    virtual void visit( const Binary &e) = 0;
    virtual void visit( const Group &e) = 0;
    virtual void visit( const Literal &e) = 0;
};

struct Expr {
 virtual void accept( Visitor &v) const = 0;
 };

struct Unary: public Expr {
    Unary( const Token &t, const Expr &e1):
        t(t),
        e1(e1)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Token& t;
    const Expr& e1;
};

struct Binary: public Expr {
    Binary( const Expr &e1, const Token &t, const Expr &e2):
        e1(e1),
        t(t),
        e2(e2)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Token& t;
    const Expr& e2;
};

struct Group: public Expr {
    Group( const Expr &e1):
        e1(e1)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
};

struct Literal: public Expr {
    Literal( const Token &t):
        t(t)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Token& t;
};

